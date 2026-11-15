// Russian labels for the Roll of Honour memorial (Workshop 3791314577). The mod builds every
// cell from fixed English/transliterated strings; this maps them line by line. Names stay as
// the mod reads them from its name files. Unknown text passes through unchanged.
#pragma once
#include <cstring>
#include <string>
#include <unordered_map>

namespace roh {

inline const std::unordered_map<std::string, std::string>& words() {
    static const std::unordered_map<std::string, std::string> map = {
        // Roles
        {"Rifleman", "Стрелок"}, {"Medic", "Санитар"}, {"Sniper", "Снайпер"}, {"Commissar", "Комиссар"},
        {"Machine Gunner", "Пулемётчик"}, {"MG", "Пулемётчик"}, {"Asst. MG", "Пом. пулемётчика"},
        {"Pilot", "Лётчик"}, {"Officer", "Офицер"}, {"NCO", "Сержант"}, {"Assistant NCO", "Мл. командир"},
        {"Flamer", "Огнемётчик"}, {"Radio", "Радист"}, {"Pioneer", "Сапёр"}, {"Engineer", "Инженер"},
        {"PzSchreck", "Панцершрек"}, {"PzFaust", "Фаустник"}, {"AT Rifle", "Бронебойщик"},
        {"SMG", "Автоматчик"}, {"Tank Crew", "Танкист"}, {"Tank Kmdr", "Ком. танка"},
        {"Tank Cmdr", "Ком. танка"}, {"Unidentified", "Не опознан"},
        {"Squad Ldr.", "Ком. отд."}, {"Asst. Squad Ldr.", "Пом. ком. отд."},
        {"Sect. Ldr.", "Ком. отд."}, {"Asst. Sect. Ldr.", "Пом. ком. отд."},
        {"Sect. Cmdr.", "Ком. отд."}, {"Sect. 2IC", "Пом. ком. отд."},
        {"Grp.Fhr.", "Ком. отд."}, {"Stv. Grp.Fhr.", "Пом. ком. отд."},
        {"Kom. otd.", "Ком. отд."}, {"Pom. kom. otd.", "Пом. ком. отд."},
        {"Ryhm.joht.", "Ком. отд."}, {"Vara ryhm.joht.", "Пом. ком. отд."},
        {"Chef grp.", "Ком. отд."}, {"Chef grp. adj.", "Пом. ком. отд."},
        {"Dow. druz.", "Ком. отд."}, {"Zast. dow. druz.", "Пом. ком. отд."},
        {"Gruppchef", "Ком. отд."}, {"Stf. gruppchef", "Пом. ком. отд."},
        // Germany
        {"Schtz.", "Шютце"}, {"Schütze", "Шютце"}, {"Ob. Schtz.", "Обершютце"}, {"Oberschütze", "Обершютце"},
        {"Gren.", "Гренадер"}, {"Grenadier", "Гренадер"}, {"Ob. Gren.", "Обергренадер"},
        {"Obergrenadier", "Обергренадер"}, {"Gefr.", "Гефр."}, {"Gefreiter", "Гефрайтер"},
        {"Ob. Gefr.", "Обергефр."}, {"Ogefr.", "Обергефр."}, {"Obergefreiter", "Обергефрайтер"},
        {"Stabsgefr.", "Штабсгефр."}, {"Stabsgefreiter", "Штабсгефрайтер"}, {"Hptgefr.", "Гауптгефр."},
        {"Uffz.", "Унтер-оф."}, {"Unteroffizier", "Унтер-офицер"}, {"Ufw.", "Унтер-фв."},
        {"Unterfeldwebel", "Унтер-фельдфебель"}, {"Fw.", "Фельдф."}, {"Feldwebel", "Фельдфебель"},
        {"OFw.", "Обер-фв."}, {"Ofw.", "Обер-фв."}, {"Oberfeldwebel", "Обер-фельдфебель"},
        {"StFw.", "Штабс-фв."}, {"Stfw.", "Штабс-фв."}, {"Stabsfeldwebel", "Штабс-фельдфебель"},
        {"Lt.", "Лейт."}, {"Leutnant", "Лейтенант"}, {"Oblt.", "Обер-лейт."}, {"Oberleutnant", "Обер-лейтенант"},
        {"Hptm.", "Гауптман"}, {"Hauptmann", "Гауптман"}, {"Maj.", "Майор"},
        {"Obstlt.", "Оберст-лейт."}, {"Oberstleutnant", "Оберст-лейтенант"},
        {"Jaeger", "Егерь"}, {"Oberjaeger", "Оберегерь"}, {"Flieger", "Флигер"},
        // Soviet Union
        {"Ryadovoy", "Рядовой"}, {"Yefr.", "Ефр."}, {"Ml. Sgt.", "Мл. серж."}, {"Sgt.", "Серж."},
        {"St. Sgt.", "Ст. серж."}, {"Starshina", "Старшина"}, {"Ml. Lt.", "Мл. лейт."},
        {"St. Lt.", "Ст. лейт."}, {"Kapitan", "Капитан"}, {"Major", "Майор"}, {"Podpolk.", "Подполк."},
        {"Krasnofl.", "Краснофл."}, {"St. Krasnofl.", "Ст. краснофл."}, {"Starsh. 2cl", "Старш. 2 ст."},
        {"Starsh. 1cl", "Старш. 1 ст."}, {"Gl. Starsh.", "Гл. старш."}, {"Michman", "Мичман"},
        {"Capt-Lt.", "Кап.-лейт."},
        // Britain
        {"Pte", "Рядовой"}, {"Tpr", "Рядовой"}, {"L/Cpl", "Мл. капрал"}, {"Cpl", "Капрал"}, {"Sgt", "Сержант"},
        {"S/Sgt", "Шт.-серж."}, {"CoH", "Капрал"}, {"SoH", "Шт.-серж."}, {"WOII", "Уорэнт-оф. 2"},
        {"WO1", "Уорэнт-оф. 1"}, {"2nd Lt", "Мл. лейт."}, {"Lt", "Лейт."}, {"Capt", "Капитан"},
        {"Maj", "Майор"}, {"Lt Col", "Подполк."},
        // USA
        {"Pvt.", "Рядовой"}, {"Pfc.", "Рядовой 1 кл."}, {"Cpl.", "Капрал"}, {"S/Sgt.", "Шт.-серж."},
        {"T/Sgt.", "Тех.-серж."}, {"1st Sgt.", "Перв. серж."}, {"M/Sgt.", "Маст.-серж."},
        {"2nd Lt.", "Мл. лейт."}, {"1st Lt.", "Перв. лейт."}, {"Capt.", "Капитан"}, {"Lt. Col.", "Подполк."},
        // Finland
        {"Stm.", "Рядовой"}, {"Korpr.", "Капрал"}, {"Alik.", "Мл. серж."}, {"Kers.", "Серж."},
        {"Ylik.", "Ст. серж."}, {"Vaap.", "Вяяпели"}, {"Vanr.", "Вянрикки"}, {"Luutn.", "Лейт."},
        {"Kapt.", "Капитан"}, {"Everstiluutn.", "Подполк."},
        // France
        {"Sdt", "Солдат"}, {"Chasseur", "Егерь"}, {"Bgr", "Бригадир"}, {"Bgc", "Ст. бригадир"},
        {"Ccl", "Ст. капрал"}, {"Mdl", "Сержант"}, {"Mlc", "Ст. сержант"}, {"Sgt-Ch", "Ст. сержант"},
        {"Adj", "Аджюдан"}, {"Adj-Ch", "Ст. аджюдан"}, {"S-Lt", "Мл. лейт."}, {"Cne", "Капитан"},
        {"Cdt", "Майор"}, {"Lt-Col", "Подполк."},
    };
    return map;
}

// Prefixes the mod glues onto a role or rank, longest first where they overlap.
struct Affix { const char* from; const char* to; };
inline constexpr Affix kPrefixes[] = {
    {"Panzer-", "Панцер-"}, {"NKVD ", "НКВД "}, {"PzG ", "Панцергр. "}, {"Gds. ", "Гв. "}, {"Pz. ", "Пз. "},
};

inline bool startsWith(const std::string& s, const char* p) { return s.rfind(p, 0) == 0; }
// HF breed job codes which the original memorial treats as generic Rifleman.
// Other jobs keep the native formatter, including its detailed vehicle labels.
inline std::string roleAlias(std::string job) {
    for (char& c : job) if (c >= 'A' && c <= 'Z') c = static_cast<char>(c + ('a' - 'A'));
    if (job == "commisar" || job == "commissar" || job == "politruk") return "Commissar";
    if (job == "officer") return "Officer";
    if (job == "mgun_asst" || startsWith(job, "mgun_asst_")) return "Asst. MG";
    if (startsWith(job, "mgun_") && job.size() > 5
        && job.find_first_not_of("0123456789", 5) == std::string::npos) return "Machine Gunner";
    return {};
}
inline bool endsWith(const std::string& s, const std::string& p) {
    return s.size() >= p.size() && s.compare(s.size() - p.size(), p.size(), p) == 0;
}

inline std::string word(const std::string& text) {
    if (text.empty()) return text;
    auto& map = words();
    if (auto it = map.find(text); it != map.end()) return it->second;
    // "Pz. IV Crew" -> "Экипаж Pz. IV"; "T-34 Kmdr" -> "Ком. T-34". Vehicle names stay as written.
    for (auto [suffix, to] : {std::pair{" Crew", "Экипаж "}, std::pair{" Kmdr", "Ком. "}, std::pair{" Cmdr", "Ком. "}})
        if (endsWith(text, suffix) && text.size() > strlen(suffix))
            return std::string(to) + text.substr(0, text.size() - strlen(suffix));
    for (auto& a : kPrefixes)
        if (startsWith(text, a.from) && text.size() > strlen(a.from)) {
            const std::string rest = text.substr(strlen(a.from));
            const std::string done = word(rest);
            if (done != rest) return a.to + done;
        }
    return text;
}

// Keeps padding and separators: each line, and each "|" part of it, is mapped on its own.
inline std::string translate(const std::string& text) {
    std::string out;
    size_t start = 0;
    while (start <= text.size()) {
        size_t end = text.find_first_of("\n|", start);
        if (end == std::string::npos) end = text.size();
        std::string part = text.substr(start, end - start);
        const size_t a = part.find_first_not_of(" \r\t"), b = part.find_last_not_of(" \r\t");
        if (a == std::string::npos) out += part;
        else out += part.substr(0, a) + word(part.substr(a, b - a + 1)) + part.substr(b + 1);
        if (end == text.size()) break;
        out += text[end];
        start = end + 1;
    }
    return out;
}

} // namespace roh
