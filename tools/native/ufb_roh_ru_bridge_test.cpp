// Exercise the real patched ROH bridge, including its borrowed long-string ABI.
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>

struct Widget { void** vtable; std::string received; };
static void __fastcall receive(void* raw, std::string value) {
    static_cast<Widget*>(raw)->received = value;
} // destroys the incoming by-value argument, like the real game widget

int main(int argc, char** argv) {
    assert(argc == 3);
    HMODULE roh = LoadLibraryA(argv[1]);
    assert(roh);
    HMODULE patch = LoadLibraryA(argv[2]);
    assert(patch);
    auto init = reinterpret_cast<int(*)(void*)>(GetProcAddress(patch, "luaopen_ufb_roh_ru"));
    assert(init); init(nullptr);
    auto bridge = reinterpret_cast<bool(*)(void*, std::string*)>(
        reinterpret_cast<unsigned char*>(roh) + 0x23150);
    void* vtable[26] = {};
    vtable[25] = reinterpret_cast<void*>(&receive);
    Widget widget{vtable, {}};
    for (int pass = 0; pass < 200; ++pass) {
        std::vector<std::string> cells(25, "Rifleman\nMedic\nSniper\nUnidentified\n");
        cells[1] = std::string(8192, 'A'); // large allocation path too
        cells[2] = "Medic"; // inline string
        for (auto& owner : cells) {
            const std::string before = owner;
            alignas(std::string) unsigned char alias[sizeof(std::string)];
            memcpy(alias, &owner, sizeof(alias)); // the exact ROH call-site shape
            assert(bridge(&widget, reinterpret_cast<std::string*>(alias)));
            assert(owner == before); // translation may not free or mutate the owner
            assert(memcmp(alias, &owner, sizeof(alias)) == 0);
            if (owner == "Medic") assert(widget.received == "Санитар");
            else if (owner.size() == 8192) assert(widget.received == owner);
            else assert(widget.received.find("Стрелок") != std::string::npos);
        }
    } // all 25 original strings must remain valid to destroy once
    assert(!bridge(nullptr, nullptr));
    std::puts("ROH bridge: 5000 borrowed cells, long/inline strings, ownership and translation passed");
}
