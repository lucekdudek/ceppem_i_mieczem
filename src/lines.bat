@echo off
setlocal EnableDelayedExpansion

set /a cnt=0
for /r %%F in ("*.cpp") do (
	for /f %%a in ('type "%%~dpnxF"^|find "" /v /c') do set /a cnt=!cnt!+%%a
)
for /r %%F in ("*.h") do (
	for /f %%a in ('type "%%~dpnxF"^|find "" /v /c') do set /a cnt=!cnt!+%%a
)
set /a cnt=%cnt%-5797
echo %cnt%

pause