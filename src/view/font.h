#pragma once
#include "SDL2/SDL_ttf.h"
#include <iostream>
#include <map>
class Font
{
public:
	Font(std::string file_name);
	~Font();

	TTF_Font* Font::getFont(int size);
private:
	std::string file_name;
	std::map<int, TTF_Font*> font_sizes;
};

