@echo off
rem Builds ufb_hatch.dll and ufb_roh_ru.dll into the mod folder and runs their logic tests. Needs Visual Studio C++ tools.
setlocal
"%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe" -latest -products * -property installationPath > "%TEMP%\ufb_vs_path.txt" || exit /b 1
set /p VS=<"%TEMP%\ufb_vs_path.txt"
call "%VS%\VC\Auxiliary\Build\vcvars64.bat" >nul || exit /b 1
cd /d "%~dp0"
set "OUT=%TEMP%\ufb_hatch_build"
if not exist "%OUT%" mkdir "%OUT%"
cl /nologo /std:c++17 /EHsc /O2 /W4 /D_CRT_SECURE_NO_WARNINGS /Fo"%OUT%\\" /Fe"%OUT%\ufb_hatch_test.exe" ufb_hatch_test.cpp || exit /b 1
"%OUT%\ufb_hatch_test.exe" || exit /b 1
cl /nologo /std:c++17 /O2 /W4 /MT /LD /Fo"%OUT%\\" ufb_hatch.cpp /link /NOLOGO /OUT:"..\..\mods\ultimate_frontline_bundle\ufb_hatch.dll" /IMPLIB:"%OUT%\ufb_hatch.lib" kernel32.lib || exit /b 1
cl /nologo /std:c++17 /utf-8 /EHsc /O2 /W4 /Fo"%OUT%\\" /Fe"%OUT%\ufb_roh_ru_test.exe" ufb_roh_ru_test.cpp || exit /b 1
"%OUT%\ufb_roh_ru_test.exe" || exit /b 1
rem /MD on purpose: translated strings are freed by the game, like fallen_memorial.dll's own.
cl /nologo /std:c++17 /utf-8 /EHsc /O2 /W4 /MD /LD /Fo"%OUT%\\" ufb_roh_ru.cpp /link /NOLOGO /OUT:"..\..\mods\ultimate_frontline_bundle\ufb_roh_ru.dll" /IMPLIB:"%OUT%\ufb_roh_ru.lib" kernel32.lib || exit /b 1
cl /nologo /std:c++17 /utf-8 /EHsc /O2 /W4 /MD /Fo"%OUT%\\" /Fe"%OUT%\ufb_roh_ru_bridge_test.exe" ufb_roh_ru_bridge_test.cpp || exit /b 1
"%OUT%\ufb_roh_ru_bridge_test.exe" "..\..\..\3791314577\fallen_memorial.dll" "..\..\mods\ultimate_frontline_bundle\ufb_roh_ru.dll" || exit /b 1
