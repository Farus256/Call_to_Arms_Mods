// Russian text for the Roll of Honour memorial page (Workshop 3791314577, fallen_memorial.dll).
// Every memorial cell goes through one function there: it hands the widget a std::string by value
// through vtable slot 0xC8. We replace that function with the same steps plus roh::translate.
// Another fallen_memorial.dll build fails the byte check and keeps its English text.
// Build: tools/native/build.cmd (/MD: the strings share the CRT heap with fallen_memorial.dll).
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "ufb_roh_ru_core.h"

namespace {
// RVAs in fallen_memorial.dll as published on 2026-09-23 (sha256 cc2882be..., before or after
// tools/patch-roll-of-honour.cjs, which does not touch these bytes).
constexpr DWORD kSetText = 0x23150;
constexpr DWORD kIsCode = 0x16AB0;
const unsigned char kSetTextStart[] = {0x48, 0x89, 0x5C, 0x24, 0x08, 0x48, 0x89, 0x74, 0x24, 0x10, 0x57, 0x48, 0x83,
    0xEC, 0x20, 0x48, 0x8B, 0xFA, 0x48, 0x8B, 0xD9, 0x48, 0x85, 0xC9, 0x74, 0x30, 0x48, 0x85, 0xD2, 0x74, 0x2B, 0x48,
    0x8B, 0x01, 0x48, 0x85, 0xC0, 0x74, 0x25, 0x48, 0x8B, 0xB0, 0xC8, 0x00, 0x00, 0x00};
const unsigned char kIsCodeStart[] = {0x48, 0x83, 0xEC, 0x58, 0x48, 0x85, 0xC9, 0x74, 0x6A};

// MSVC passes a nontrivial by-value string through an indirect pointer. The
// widget destroys that argument. ROH's hand-written bridge supplies a shallow
// alias of its 25-cell array for long strings: never assign to that alias.
using SetTextFn = void(__fastcall*)(void* widget, std::string text);
using IsCodeFn = bool(__fastcall*)(void* address);
IsCodeFn g_isCode = nullptr;

// Read the borrowed input and let C++ create a separate, owned by-value argument.
bool __fastcall setText(void* widget, std::string* text) {
    if (!widget || !text) return false;
    void** vtable = *static_cast<void***>(widget);
    if (!vtable) return false;
    void* fn = vtable[0xC8 / sizeof(void*)];
    if (!g_isCode(fn)) return false;
    try {
        reinterpret_cast<SetTextFn>(fn)(widget, roh::translate(*text));
    } catch (...) {
        return false;
    }
    return true;
}

void install() {
    auto base = reinterpret_cast<unsigned char*>(GetModuleHandleW(L"fallen_memorial.dll"));
    if (!base) return; // Roll of Honour is not active.
    unsigned char jump[12] = {0x48, 0xB8, 0, 0, 0, 0, 0, 0, 0, 0, 0xFF, 0xE0}; // mov rax, hook; jmp rax
    void* target = reinterpret_cast<void*>(&setText);
    memcpy(jump + 2, &target, sizeof(target));
    unsigned char* site = base + kSetText;
    __try {
        if (memcmp(site, jump, sizeof(jump)) == 0) return; // Already installed in this process.
        if (memcmp(site, kSetTextStart, sizeof(kSetTextStart)) != 0
            || memcmp(base + kIsCode, kIsCodeStart, sizeof(kIsCodeStart)) != 0)
            return;
        g_isCode = reinterpret_cast<IsCodeFn>(base + kIsCode);
        DWORD old = 0;
        if (!VirtualProtect(site, sizeof(jump), PAGE_EXECUTE_READWRITE, &old)) return;
        memcpy(site, jump, sizeof(jump));
        VirtualProtect(site, sizeof(jump), old, &old);
        FlushInstructionCache(GetCurrentProcess(), site, sizeof(jump));
    } __except (EXCEPTION_EXECUTE_HANDLER) {
    }
}
} // namespace

// Pinned: fallen_memorial.dll would otherwise jump into unloaded code after Lua closes its libraries.
BOOL WINAPI DllMain(HINSTANCE module, DWORD reason, LPVOID) {
    if (reason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(module);
        HMODULE pinned = nullptr;
        GetModuleHandleExW(GET_MODULE_HANDLE_EX_FLAG_PIN | GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS,
                           reinterpret_cast<LPCWSTR>(&setText), &pinned);
    }
    return TRUE;
}

// Each battle loads fallen_memorial.dll first (its bot.main.lua), then UFB calls this.
extern "C" __declspec(dllexport) int luaopen_ufb_roh_ru(void*) {
    install();
    return 0;
}
