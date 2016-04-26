#Copyright Notice:
#The files within this zip file are copyrighted by Lazy Foo' Productions (2004-2014)
#and may not be redistributed without written permission.

#OBJS specifies which files to compile as part of the project
OBJS = $(wildcard src/*.cpp src/*.h src/*/*.cpp src/*/*.h src/*/*.hpp)

#CC specifies which compiler we're using
CC = g++
WINDRES = windres.exe

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window
COMPILER_FLAGS = -w -Wl,-subsystem,windows

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lmingw32 -lopengl32 -lSDL2_ttf -lSDL2_image -lSDL2main -lSDL2 -static-libgcc -static-libstdc++ -std=c++11

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = bin\ceppem.exe

#This is the target that compiles our executable
all : res/resources.res
	$(CC) $(OBJS) res/resources.res $(LINKER_FLAGS) -o $(OBJ_NAME)
	echo All done
	
res/resources.res: res/resources.rc
	$(WINDRES) --input=res/resources.rc --input-format=rc --output=res/resources.res --output-format=coff