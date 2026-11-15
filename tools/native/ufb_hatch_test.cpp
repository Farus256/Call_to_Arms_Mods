// Runs the hatch logic on fake engine objects laid out like the real ones.
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include "ufb_hatch_core.h"

using namespace ufb;
#define CHECK(x) do { if (!(x)) { printf("FAILED line %d: %s\n", __LINE__, #x); exit(1); } ++checks; } while (0)
static int checks = 0;
static int closes = 0, opens = 0;
static void __fastcall fakeSetSealed(void*, bool sealed) { (sealed ? closes : opens)++; }

struct Action {
    char memory[0x100] = {};
    Action(const char* name, bool enable, bool place = false) {
        memory[kModeIsPlace] = place;
        memory[kEnable] = enable;
        std::size_t size = strlen(name), capacity = size > 15 ? size : 15;
        memcpy(memory + kNameSize, &size, sizeof(size));
        memcpy(memory + kNameCapacity, &capacity, sizeof(capacity));
        if (size > 15) {
            char* text = new char[size + 1];
            strcpy(text, name);
            memcpy(memory + kNameBuffer, &text, sizeof(text));
        } else strcpy(memory + kNameBuffer, name);
    }
};
struct Tank {
    std::vector<char> seats;
    char crew[0x100] = {};
    char entity[0x600] = {};
    explicit Tank(int count, bool sealed = false) : seats(count * kSeatSize) {
        char* begin = seats.data();
        char* end = begin + seats.size();
        char* crewPointer = crew;
        memcpy(crew + kSeatsBegin, &begin, sizeof(begin));
        memcpy(crew + kSeatsEnd, &end, sizeof(end));
        memcpy(entity + kCrew, &crewPointer, sizeof(crewPointer));
        if (sealed) seal(count - 1);
    }
    void seal(int seat) { unsigned flag = kSeatSealed | 0x80000; memcpy(seats.data() + seat * kSeatSize + kSeatFlags, &flag, 4); }
};

int main() {
    Action close("ufb_hatch", false), open("ufb_hatch", true);
    CHECK(isHatchRequest(close.memory));
    CHECK(!isHatchRequest(Action("crew", false).memory));
    CHECK(!isHatchRequest(Action("ufb_hatch", false, true).memory));
    CHECK(!isHatchRequest(Action("ufb_hatchx", false).memory));
    CHECK(!isHatchRequest(Action("passenger_ufb_hatch_long", false).memory));

    { Closed closed; Tank tank(4); apply(close.memory, tank.entity, fakeSetSealed, closed); CHECK(closes == 1);
      apply(open.memory, tank.entity, fakeSetSealed, closed); CHECK(opens == 1);
      apply(open.memory, tank.entity, fakeSetSealed, closed); CHECK(opens == 1); }
    { closes = opens = 0; Closed closed; Tank tank(4, true); // shut with the player's button
      apply(close.memory, tank.entity, fakeSetSealed, closed); CHECK(closes == 0);
      apply(open.memory, tank.entity, fakeSetSealed, closed); CHECK(opens == 0); }
    { closes = opens = 0; Closed closed; char noCrew[0x600] = {};
      apply(close.memory, noCrew, fakeSetSealed, closed); CHECK(closes == 0); }
    { closes = 0; Closed closed; Tank empty(0); apply(close.memory, empty.entity, fakeSetSealed, closed); CHECK(closes == 1); }
    { Closed closed; std::vector<int> marks(300);
      for (auto& mark : marks) closed.add(&mark);
      CHECK(!closed.has(&marks.back())); CHECK(closed.has(&marks.front())); }
    { Closed closed; Tank reused(4, true); closed.add(reused.entity);
      Action reset("ufb_hatch_reset",false); apply(reset.memory,reused.entity,fakeSetSealed,closed);
      opens=0; apply(close.memory,reused.entity,fakeSetSealed,closed);
      apply(open.memory,reused.entity,fakeSetSealed,closed); CHECK(opens==0); }
    { Closed closed; Tank reused(4); closed.add(reused.entity); Action reset("ufb_hatch_reset",false);
      CHECK(isHatchRequest(reset.memory)); apply(reset.memory,reused.entity,fakeSetSealed,closed);
      opens=0; apply(open.memory,reused.entity,fakeSetSealed,closed); CHECK(opens==0); }
    { Closed closed; std::vector<int> marks(256); for(auto& m:marks) CHECK(closed.add(&m));
      Tank overflow(4); closes=0; apply(close.memory,overflow.entity,fakeSetSealed,closed); CHECK(closes==0);
      CHECK(closed.has(&marks.front())); }
    { Closed closed; Tank tank(4); apply(close.memory,tank.entity,fakeSetSealed,closed);
      tank.seal(0); apply(close.memory,tank.entity,fakeSetSealed,closed);
      CHECK(closed.has(tank.entity)); opens=0; apply(open.memory,tank.entity,fakeSetSealed,closed); CHECK(opens==1); }
    { Closed closed; int owner=0; closed.add(&owner); closed.clear(); CHECK(!closed.has(&owner)); }
    printf("{\"checks\":%d,\"passed\":true}\n", checks);
}
