@echo off
echo Kompilowanie
set PATH=%PATH%;c:\MinGW\bin
g++ *.h *.cpp -o bin\ceppem.exe -IC:\MinGW\include\SDL2 -lmingw32 -lopengl32 -lSDL2_ttf -lSDL2_image -lSDL2main -lSDL2 -static-libgcc -static-libstdc++ 
echo Uruchamianie
cd bin
ceppem.exe