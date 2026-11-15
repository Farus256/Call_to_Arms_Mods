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
constexpr DWORD kRole = 0x198D0;
const unsigned char kRoleStart[] = {0x48,0x89,0x5c,0x24,0x18,0x55,0x56,0x57,0x41,0x54,0x41,0x55};
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
using RoleFn = std::string(__fastcall*)(const void*);
RoleFn g_role = nullptr;

std::string __fastcall role(const void* record) {
    // Verified in this DLL: job is an MSVC string at +0x50 in the 0x100-byte record.
    const auto& job = *reinterpret_cast<const std::string*>(static_cast<const unsigned char*>(record) + 0x50);
    auto alias = roh::roleAlias(job);
    return alias.empty() ? g_role(record) : alias;
}

void makeJump(unsigned char* out, const void* target) {
    out[0]=0x48; out[1]=0xb8; memcpy(out+2,&target,sizeof(target)); out[10]=0xff; out[11]=0xe0;
}

bool writeCode(unsigned char* site, const unsigned char* bytes, size_t count) {
    DWORD old=0;
    if(!VirtualProtect(site,count,PAGE_EXECUTE_READWRITE,&old))return false;
    memcpy(site,bytes,count);VirtualProtect(site,count,old,&old);
    FlushInstructionCache(GetCurrentProcess(),site,count);return true;
}

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

bool install() {
    auto base = reinterpret_cast<unsigned char*>(GetModuleHandleW(L"fallen_memorial.dll"));
    if (!base) return false;
    unsigned char jump[12], roleJump[12];
    makeJump(jump,reinterpret_cast<const void*>(&setText));
    makeJump(roleJump,reinterpret_cast<const void*>(&role));
    auto site=base+kSetText;
    __try {
        if (memcmp(site,jump,12)==0 && memcmp(base+kRole,roleJump,12)==0) return true;
        if (memcmp(site,kSetTextStart,sizeof(kSetTextStart)) ||
            memcmp(base+kIsCode,kIsCodeStart,sizeof(kIsCodeStart)) ||
            memcmp(base+kRole,kRoleStart,sizeof(kRoleStart))) return false;
        auto trampoline=static_cast<unsigned char*>(VirtualAlloc(nullptr,24,MEM_RESERVE|MEM_COMMIT,PAGE_EXECUTE_READWRITE));
        if (!trampoline) return false;
        memcpy(trampoline,base+kRole,12); makeJump(trampoline+12,base+kRole+12);
        DWORD roleProtection=0,textProtection=0;
        if (!VirtualProtect(base+kRole,12,PAGE_EXECUTE_READWRITE,&roleProtection)) {
            VirtualFree(trampoline,0,MEM_RELEASE); return false;
        }
        if (!VirtualProtect(site,12,PAGE_EXECUTE_READWRITE,&textProtection)) {
            DWORD ignored; VirtualProtect(base+kRole,12,roleProtection,&ignored);
            VirtualFree(trampoline,0,MEM_RELEASE); return false;
        }
        // Keep the dependency alive for both trampolines and cached function addresses.
        HMODULE pinned=nullptr;
        if (!GetModuleHandleExW(GET_MODULE_HANDLE_EX_FLAG_PIN | GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS,
                               reinterpret_cast<LPCWSTR>(base),&pinned)) {
            DWORD ignored; VirtualProtect(site,12,textProtection,&ignored);
            VirtualProtect(base+kRole,12,roleProtection,&ignored);
            VirtualFree(trampoline,0,MEM_RELEASE); return false;
        }
        g_role=reinterpret_cast<RoleFn>(trampoline);
        g_isCode=reinterpret_cast<IsCodeFn>(base+kIsCode);
        FlushInstructionCache(GetCurrentProcess(),trampoline,24);
        memcpy(base+kRole,roleJump,12); memcpy(site,jump,12);
        DWORD ignored; VirtualProtect(site,12,textProtection,&ignored);
        VirtualProtect(base+kRole,12,roleProtection,&ignored);
        FlushInstructionCache(GetCurrentProcess(),base+kRole,12);
        FlushInstructionCache(GetCurrentProcess(),site,12);
        return true;
    } __except (EXCEPTION_EXECUTE_HANDLER) { return false; }
}

} // namespace

// Pinned: fallen_memorial.dll would otherwise jump into unloaded code after Lua closes its libraries.
BOOL WINAPI DllMain(HINSTANCE module, DWORD reason, LPVOID) {
    if (reason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(module);
        if (!install()) return FALSE; // package.loadlib reports initialization failure.
        HMODULE pinned = nullptr;
        GetModuleHandleExW(GET_MODULE_HANDLE_EX_FLAG_PIN | GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS,
                           reinterpret_cast<LPCWSTR>(&setText), &pinned);
    }
    return TRUE;
}

// Each battle loads fallen_memorial.dll first (its bot.main.lua), then UFB calls this.
extern "C" __declspec(dllexport) int luaopen_ufb_roh_ru(void*) {
    return 0;
}
