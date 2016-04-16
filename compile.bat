set PATH=%PATH%;c:\MinGW\bin
mkdir ..\BIN
g++ *.h *.cpp -o ..\BIN\ceppem.exe -IC:\MinGW\include\SDL2 -lmingw32 -lopengl32 -lSDL2_ttf -lSDL2_image -lSDL2main -lSDL2 -static-libgcc -static-libstdc++ 