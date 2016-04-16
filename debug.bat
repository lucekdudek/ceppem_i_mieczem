echo Kompilowanie
set PATH=%PATH%;c:\MinGW\bin
g++ src\*\*.h src\*\*.cpp src\main.cpp -o bin\ceppem.exe -lmingw32 -lopengl32 -lSDL2_ttf -lSDL2_image -lSDL2main -lSDL2 -static-libgcc -static-libstdc++
