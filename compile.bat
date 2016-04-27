@echo off
echo Kompilowanie
set PATH=%PATH%;c:\MinGW\bin

mingw32-make 2> error.log
type error.log
pause