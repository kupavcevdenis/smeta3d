@rem Командный файл для конфигурации проектов Visual Studio средствами CMake
@echo on

setlocal

rem Устанавливаем переменные среды для студии
call "%VS150COMNTOOLS%../../VC/vcvarsall.bat" x64
if "%VSINSTALLDIR%"=="" echo "VSINSTALLDIR not set" & exit 1

set SRC=%~dp0

cd /d %SRC%

md build_cm-vc15-x64

cd build_cm-vc15-x64

cmake -G"Visual Studio 15 Win64" %1 %2 %3 %4 %5 %6 %7 %8 %9 %SRC%

cd %SRC%
