// Hatch logic with no engine dependency, so ufb_hatch_test.cpp can run it on fake objects.
// Layouts verified by disassembly of call_to_arms.exe 1.067 (build 2026.09.23).
#pragma once
#include <cstddef>
#include <cstring>

namespace ufb {
// eCrewEnable: {crew_enable group "ufb_hatch" 0|1}
constexpr std::ptrdiff_t kModeIsPlace = 0x88; // 1 = place, 0 = group
constexpr std::ptrdiff_t kEnable = 0x89;
constexpr std::ptrdiff_t kNameBuffer = 0x68; // std::string inside the tag at +0x28
constexpr std::ptrdiff_t kNameSize = 0x78;
constexpr std::ptrdiff_t kNameCapacity = 0x80;
// Entity -> crew component -> seats.
constexpr std::ptrdiff_t kCrew = 0x568;
constexpr std::ptrdiff_t kSeatsBegin = 0x28;
constexpr std::ptrdiff_t kSeatsEnd = 0x30;
constexpr std::ptrdiff_t kSeatSize = 0x298;
constexpr std::ptrdiff_t kSeatFlags = 0x248;
constexpr unsigned kSeatSealed = 0x100000;

using SetSealedFn = void(__fastcall*)(void* crew, bool sealed);

template <typename T> T read(const void* base, std::ptrdiff_t offset) {
    T value;
    std::memcpy(&value, static_cast<const char*>(base) + offset, sizeof(T));
    return value;
}

inline bool isHatchRequest(const char* action) {
    static const char name[] = "ufb_hatch";
    const std::size_t length = sizeof(name) - 1;
    if (read<bool>(action, kModeIsPlace) || read<std::size_t>(action, kNameSize) != length)
        return false;
    const char* text = read<std::size_t>(action, kNameCapacity) > 0xf
        ? read<const char*>(action, kNameBuffer)
        : action + kNameBuffer;
    return text && std::memcmp(text, name, length) == 0;
}

inline bool anySeatSealed(const char* crew) {
    const char* end = read<const char*>(crew, kSeatsEnd);
    for (const char* seat = read<const char*>(crew, kSeatsBegin); seat && seat != end; seat += kSeatSize)
        if (read<unsigned>(seat, kSeatFlags) & kSeatSealed)
            return true;
    return false;
}

// Remembers only what UFB closed, so a hatch closed with the player's button stays closed.
// ponytail: fixed ring, a tank pushed out after 256 closures just stays shut until its next close.
class Closed {
    const void* slots_[256] = {};
    unsigned next_ = 0;
public:
    bool has(const void* entity) const {
        for (auto slot : slots_)
            if (slot == entity)
                return true;
        return false;
    }
    void add(const void* entity) {
        if (!has(entity))
            slots_[next_++ % 256] = entity;
    }
    void remove(const void* entity) {
        for (auto& slot : slots_)
            if (slot == entity)
                slot = nullptr;
    }
};

inline void apply(const char* action, char* entity, SetSealedFn setSealed, Closed& closed) {
    char* crew = read<char*>(entity, kCrew);
    if (!crew)
        return;
    if (read<bool>(action, kEnable)) { // {crew_enable group "ufb_hatch" 1}: open what UFB closed
        if (closed.has(entity)) {
            closed.remove(entity);
            setSealed(crew, false);
        }
    } else if (!anySeatSealed(crew)) { // already shut by the player's button: leave it to him
        setSealed(crew, true);
        closed.add(entity);
    }
}
} // namespace ufb
