#include "font.h"



Font::Font(std::string file_name)
{
	this->file_name = file_name;
}


Font::~Font()
{
	for (std::map<int, TTF_Font*>::iterator it= font_sizes.begin(); it != font_sizes.end(); it++)
	{
		delete it->second;
	}
}

bool load()
{
	

	return true;
}

TTF_Font* Font::getFont(int size)
{
	std::map<int, TTF_Font*>::iterator it;
	it = font_sizes.find(size);

	if (it != font_sizes.end())
	{
		return it->second;
	}
	else
	{
		TTF_Font* font = TTF_OpenFont(file_name.c_str(), size);
		font_sizes.insert(std::pair<int, TTF_Font*>(size, font));
		return font;
	}
}