// Exercise the real patched ROH bridge, including its borrowed long-string ABI.
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <new>
#include <cstdint>

struct MemorialRecord {
    alignas(std::string) unsigned char bytes[256]{};
    explicit MemorialRecord(const std::string& job) {
        new(bytes+0x10) std::string("mp/rus/mid/"+job);
        new(bytes+0x30) std::string("rus");
        new(bytes+0x50) std::string(job);
        new(bytes+0xe0) std::string();
    }
    ~MemorialRecord() { for (auto offset : {0x10,0x30,0x50,0xe0}) reinterpret_cast<std::string*>(bytes+offset)->~basic_string(); }
};

static void checkColumns(unsigned char* base) {
    // Execute the formatter's actual quotient/remainder instructions on the CPU.
    // RCX=n; RDX=counts; native code writes [RBP-0x80 ... RBP-0x60].
    const unsigned char prefix[]={0x55,0x53,0x48,0x8d,0xaa,0x80,0,0,0,0x4c,0x8b,0xc1,0xbb,1,0,0,0};
    constexpr size_t bodySize=0xf125-0xf0ce;
    auto code=static_cast<unsigned char*>(VirtualAlloc(nullptr,128,MEM_RESERVE|MEM_COMMIT,PAGE_EXECUTE_READWRITE));assert(code);
    memcpy(code,prefix,sizeof(prefix));memcpy(code+sizeof(prefix),base+0xf0ce,bodySize);
    const unsigned char suffix[]={0x5b,0x5d,0xc3};memcpy(code+sizeof(prefix)+bodySize,suffix,sizeof(suffix));
    FlushInstructionCache(GetCurrentProcess(),code,128);
    using Counts=void(__fastcall*)(uint64_t,uint64_t*);auto counts=reinterpret_cast<Counts>(code);
    for(uint64_t n=0;n<=3000;++n){uint64_t out[5]={};counts(n,out);assert(out[0]+out[1]+out[2]==n);assert(out[3]==0&&out[4]==0);assert(out[0]>=out[1]&&out[1]>=out[2]&&out[0]-out[2]<=1);}
    uint64_t sample[5]={};counts(19,sample);assert(sample[0]==7&&sample[1]==6&&sample[2]==6);
    VirtualFree(code,0,MEM_RELEASE);
    std::puts("ROH columns: native instructions preserve all casualties for 0..3000 entries in three groups");
}

struct Widget { void** vtable; std::string received; };
static void __fastcall receive(void* raw, std::string value) {
    static_cast<Widget*>(raw)->received = value;
} // destroys the incoming by-value argument, like the real game widget

int main(int argc, char** argv) {
    if (argc == 2) { assert(!LoadLibraryA(argv[1])); std::puts("ROH absent dependency rejected"); return 0; }
    assert(argc == 3 || argc == 4);
    HMODULE roh = LoadLibraryA(argv[1]);
    assert(roh);
    auto base=reinterpret_cast<unsigned char*>(roh);
    using Role=std::string(__fastcall*)(const void*);
    auto nativeRole=reinterpret_cast<Role>(base+0x198d0),rank=reinterpret_cast<Role>(base+0x14260);
    MemorialRecord commissar("commisar");
    assert(nativeRole(commissar.bytes)=="Rifleman");
    const auto originalRank=rank(commissar.bytes);assert(originalRank=="Ml. Lt.");
    checkColumns(base);
    if (argc == 4) {
        DWORD old=0,ignored=0; auto site=base+0x198d0; const auto before=*site;
        assert(VirtualProtect(site,1,PAGE_EXECUTE_READWRITE,&old)); *site=0xcc;
        assert(!LoadLibraryA(argv[2])); *site=before; VirtualProtect(site,1,old,&ignored);
        std::puts("ROH incompatible signature rejected; retrying compatible dependency");
    }
    HMODULE patch = LoadLibraryA(argv[2]);
    assert(patch);
    auto init = reinterpret_cast<int(*)(void*)>(GetProcAddress(patch, "luaopen_ufb_roh_ru"));
    assert(init); init(nullptr);
    init(nullptr); // repeated loading must not install another trampoline.
    assert(nativeRole(commissar.bytes)=="Commissar" && rank(commissar.bytes)==originalRank);
    for(const auto& entry:std::vector<std::pair<std::string,std::string>>{{"mgun_1","Machine Gunner"},{"mgun_3","Machine Gunner"},{"mgun_asst_1","Asst. MG"},{"medic","Medic"},{"sniper","Sniper"},{"NCO","Kom. otd."},{"tankman","Tank Crew"}}){MemorialRecord record(entry.first);assert(nativeRole(record.bytes)==entry.second);}
    std::puts("ROH roles: commissar and HF MG codes corrected, native fallbacks and ranks retained");
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
