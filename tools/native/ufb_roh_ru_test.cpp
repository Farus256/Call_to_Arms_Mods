// Checks roh::translate on cells shaped like the memorial's. Built and run by build.cmd.
#include <cassert>
#include <cstdio>
#include "ufb_roh_ru_core.h"

int main() {
    using roh::translate;
    assert(translate("Rifleman") == "Стрелок");
    assert(translate("Gefr.\nOb. Gefr.\n\nRyadovoy") == "Гефр.\nОбергефр.\n\nРядовой");
    assert(translate("Pz. IV Crew") == "Экипаж Pz. IV");
    assert(translate("Tank Crew") == "Танкист");
    assert(translate("T-34 Kmdr") == "Ком. T-34");
    assert(translate("Pz. Uffz.") == "Пз. Унтер-оф.");
    assert(translate("Panzer-Feldwebel") == "Панцер-Фельдфебель");
    assert(translate("NKVD Rifleman") == "НКВД Стрелок");
    assert(translate("Gds. Sgt.") == "Гв. Серж.");
    assert(translate("PzG SMG") == "Панцергр. Автоматчик");
    assert(translate("  Medic  |Sniper") == "  Санитар  |Снайпер");
    assert(translate("Schütze") == "Шютце");
    assert(translate("Hans Müller") == "Hans Müller"); // names pass through
    assert(translate("Pz. Unknown") == "Pz. Unknown");
    assert(translate("") == "");
    std::puts("roh translate ok");
    return 0;
}
