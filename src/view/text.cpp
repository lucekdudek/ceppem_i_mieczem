#include "text.h"



Text::Text(int x, int y, int width, int height, char* text, TTF_Font *font): Texture(x, y, width, height, text, font)
{
}


Text::~Text()
{
}

char* Text::getName()
{
	return this->path;
}