@echo off
rem Builds ufb_hatch.dll into the mod folder and runs the logic test. Needs Visual Studio C++ tools.
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
