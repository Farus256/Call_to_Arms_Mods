// Lets the mission language use the engine's real hatch, which only the panel button can reach.
// {crew_enable group "ufb_hatch" 0|1} is a harmless no-op without this DLL: no seat has that
// group. With it, the eCrewEnable action runs SetSealed on the simulation thread, where the
// native button command runs too. Calling it from Lua would race the simulation.
// Build: tools/native/build.cmd
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <excpt.h>
#include "ufb_hatch_core.h"

namespace {
// RVAs in call_to_arms.exe 1.067, build 2026.09.23.
constexpr DWORD kExecuteSlot = 0x10d29a0 + 9 * 8; // eCrewEnable vtable, action execute
constexpr DWORD kExecute = 0x743030;
constexpr DWORD kSetSealed = 0x77b4e0;
const unsigned char kExecuteStart[] = {0x48, 0x89, 0x5C, 0x24, 0x18, 0x48, 0x89, 0x74, 0x24, 0x20, 0x57};
const unsigned char kSetSealedStart[] = {0x48, 0x89, 0x5C, 0x24, 0x08, 0x48, 0x89, 0x6C, 0x24, 0x10, 0x48, 0x89, 0x74, 0x24, 0x18};

using ExecuteFn = void(__fastcall*)(void* action, void* context, char* entity);
ExecuteFn g_execute = nullptr;
ufb::SetSealedFn g_setSealed = nullptr;
ufb::Closed g_closed;

void __fastcall hook(void* action, void* context, char* entity) {
    if (!ufb::isHatchRequest(static_cast<const char*>(action))) {
        g_execute(action, context, entity);
        return;
    }
    __try {
        ufb::apply(static_cast<const char*>(action), entity, g_setSealed, g_closed);
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        // A hatch is never worth a crash; the tank just keeps its current state.
    }
}

bool install() {
    const char* base = reinterpret_cast<const char*>(GetModuleHandleW(nullptr));
    __try {
        auto slot = reinterpret_cast<void**>(const_cast<char*>(base) + kExecuteSlot);
        if (*slot != base + kExecute
            || memcmp(base + kExecute, kExecuteStart, sizeof(kExecuteStart)) != 0
            || memcmp(base + kSetSealed, kSetSealedStart, sizeof(kSetSealedStart)) != 0)
            return false;
        g_execute = reinterpret_cast<ExecuteFn>(const_cast<char*>(base) + kExecute);
        g_setSealed = reinterpret_cast<ufb::SetSealedFn>(const_cast<char*>(base) + kSetSealed);
        DWORD old = 0;
        if (!VirtualProtect(slot, sizeof(void*), PAGE_READWRITE, &old))
            return false;
        InterlockedExchangePointer(slot, reinterpret_cast<void*>(&hook));
        VirtualProtect(slot, sizeof(void*), old, &old);
        return true;
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        return false; // Not the expected game, for example a test host.
    }
}
} // namespace

// Lua closes its libraries when a battle ends. Pinned, so the hook never points at unloaded code.
BOOL WINAPI DllMain(HINSTANCE module, DWORD reason, LPVOID) {
    if (reason != DLL_PROCESS_ATTACH)
        return TRUE;
    DisableThreadLibraryCalls(module);
    if (!install())
        return FALSE; // package.loadlib reports the failure; the game runs without real hatches.
    HMODULE pinned = nullptr;
    GetModuleHandleExW(GET_MODULE_HANDLE_EX_FLAG_PIN | GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS,
                       reinterpret_cast<LPCWSTR>(&hook), &pinned);
    return TRUE;
}

// package.loadlib needs a C function; the real work already happened on load.
extern "C" __declspec(dllexport) int luaopen_ufb_hatch(void*) { return 0; }
