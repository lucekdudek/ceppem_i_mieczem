#include "progress.h"



Progress::Progress(int x, int y, int width, int height, char* name, char* path) : Texture(x, y, width, height, path)
{
	this->name = _strdup(name);
	this->max_width = width;
	fill = 100;
}


Progress::~Progress()
{
}

void Progress::setFill(unsigned char fill)
{
	this->fill = fill;
	this->width = max_width*fill / 100;
}

char* Progress::getName()
{
	return this->name;
}