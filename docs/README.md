# Отчёты и история

Последний пакет: [повороты, обзор и PBR](realism/visual-motion/REPORT_RU.md). Контрольная точка перед пакетом: `c408373`.

Предыдущий пакет: [ИИ, предупреждения и производительность](realism/warning-fix/REPORT_RU.md). Исправлены повторные таймеры и закупки, материалы и DDS; указаны оставшиеся предупреждения движка. Контрольный коммит перед изменениями: `9e2adba`. Предыдущий пакет: [проверка боя, построения, дистанции и логика ботов](realism/postbattle/REPORT_RU.md).

Текущее состояние описано в [исправлении ресурсов схватки](realism/asset-fix/REPORT_RU.md), [исправлении косвенных макросов](realism/macro-fix/REPORT_RU.md), [README репозитория](../README.md), [исправлении сбоя загрузки](realism/crash-fix/REPORT_RU.md) и [отчёте пакета реализма](realism/REPORT_RU.md).

| Файл | Содержание |
|---|---|
| [realism/asset-fix/REPORT_RU.md](realism/asset-fix/REPORT_RU.md) | Сбой загрузки схватки: 44 круга, BMP в комплекте, боеприпасы, XML и отсутствующие зависимости |
| [realism/asset-fix/verification.json](realism/asset-fix/verification.json) | Ссылки ресурсов, схема интерфейса, синтаксис и макросы; ограничения проверки |
| [realism/asset-fix/payload.json](realism/asset-fix/payload.json) | 82 замены и четыре новых ресурса с хешами |
| [realism/macro-fix/REPORT_RU.md](realism/macro-fix/REPORT_RU.md) | Второй сбой: косвенные макросы, восстановление curve_direct, восемь лишних скобок, расширенный анализ |
| [realism/macro-fix/verification.json](realism/macro-fix/verification.json) | Проверка 13 109 эффективных SDL-файлов, 1 288 макросов и двух локальных модов; ограничения |
| [realism/macro-fix/payload.json](realism/macro-fix/payload.json) | Три исправленных ресурса, SHA-256 и точные изменения |
| [realism/crash-fix/REPORT_RU.md](realism/crash-fix/REPORT_RU.md) | Исправление Nested mods, проверка обоих модов, сохранение сюжета и отменённые авиационные/sIG33 изменения |
| [realism/crash-fix/verification.json](realism/crash-fix/verification.json) | Исторические 6 604 проверки; пропущены косвенные макросы, результат заменён следующим исправлением |
| [realism/crash-fix/payload.json](realism/crash-fix/payload.json) | 255 исправленных файлов и SHA-256 до/после |
| [realism/REPORT_RU.md](realism/REPORT_RU.md) | Дальние бои, здоровье/ветераны, ремонт, дым, волны, нагрузка, решения по всем 30 пунктам и анализ анимаций |
| [realism/manifest.json](realism/manifest.json) | 259 файлов пакета, изменения и контрольные суммы |
| [realism/verification.json](realism/verification.json) | Исторические 5 031 проверка; пропущен запрет вложенных mod, результат заменён исправлением |
| [realism/representative-ranges.json](realism/representative-ranges.json) | 20 представителей оружия и 31 набор параметров с раскрытием наследования |
| [REPORT_RU.md](REPORT_RU.md) | Первый анализ оригинального ИИ, Horten, приоритетов модов и первая поставка |
| [PLAN_RU.md](PLAN_RU.md) | План первого этапа; исторические предложения не равнозначны установленным изменениям |
| [REALISM_FOLLOWUP_RU.md](REALISM_FOLLOWUP_RU.md) | Промежуточная настройка; уменьшение дистанций до 45/12 м позже отменено |
| [phase3/REPORT_RU.md](phase3/REPORT_RU.md) | Последующие правки ИИ, скрытие кругов, КО ×2, исследование возврата ЛС и ограничения |
| [phase3/changes.json](phase3/changes.json) | Старые/новые значения последнего этапа |
| [phase3/payload.json](phase3/payload.json) | 62 файла последнего этапа с контрольными суммами до/после |
| [current-files.json](current-files.json) | Полный актуальный снимок 946 файлов двух модов, относительные пути, размеры и SHA-256 |

Отчёты сохранены как история выполненной работы. Упоминания абсолютных путей, `_ai_work`, установщиков, резервных копий и ранних манифестов относятся к исходной рабочей машине. Эти временные инструменты и извлечённые архивы не входят в репозиторий; для установки следует использовать полные папки `mods`, а не исторические команды отката из отчётов.

Окончательные дистанции: **медик 90 м, ПТ-граната 18 м**; паузы AP/AT и дыма — 18 с. Возврат 75% ЛС при выводе не установлен. Актуальные хеши всех ресурсов приведены в `current-files.json`.
