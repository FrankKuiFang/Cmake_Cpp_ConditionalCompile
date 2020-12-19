@echo off
set CurrentPath=%cd%
cd %CurrentPath%
path %ProgramFiles%\CMake\bin;%PATH%


if not exist build md build
cd build
cmake .. -G "Visual Studio 15 2017 Win64" -DWITH_CHINA=1 -DWITH_EURO=1 -DWITH_JAPAN=1
cd ..

pause
if %ERRORLEVEL% GEQ 1 EXIT /B 1