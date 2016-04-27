@echo off
setlocal EnableDelayedExpansion

set Prev_path=%~dp0
cd..
set Reference_path=%cd%\
cd %Prev_path%
echo !Reference_path!

echo. 2> list_of_files.txt
echo %~dp0
for /R "..\src\" %%f in (*.cpp, *.h, *.hpp) do (
	set Path_to_convert=%%f
	set Result=!Path_to_convert:*%Reference_path%=!
	echo !Result! >> list_of_files.txt
)
pause