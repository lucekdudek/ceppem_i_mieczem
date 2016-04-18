@echo off
echo Kompilowanie
set PATH=%PATH%;c:\MinGW\bin

windres --input=res\app.rc --input-format=rc --output=app.res --output-format=coff

g++ src\main.cpp src\controller\controller.cpp src\controller\fpshandler.cpp src\controller\timer.cpp src\controller\controller.h src\controller\fpshandler.h src\controller\timer.h src\model\element.cpp src\model\model.cpp src\model\element.h src\model\model.h src\rapidxml-1.13\rapidxml.hpp src\rapidxml-1.13\rapidxml_print.hpp src\rapidxml-1.13\rapidxml_utils.hpp src\view\texture.cpp src\view\view.cpp src\view\window.cpp src\view\texture.h src\view\view.h src\view\window.h -o bin\ceppem.exe -lmingw32 -lopengl32 -lSDL2_ttf -lSDL2_image -lSDL2main -lSDL2 -static-libgcc -static-libstdc++ -std=c++11 > compilation.log 2>&1