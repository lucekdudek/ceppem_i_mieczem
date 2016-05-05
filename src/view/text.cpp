#include "text.h"
#include "window.h"

Text::Text(int x, int y, int width, int height, char* text, TTF_Font *font, bool box) : Texture(x, y, width, height, text, font)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->t_width = width;
	this->t_height = height;
	this->box = box;

	std::string s = text;

	s.copy(this->text, 256, 0);
	this->text[strlen(text)] = '\0';

	s.copy(this->path, 256, 0);
	this->path[strlen(text)] = '\0';

	this->id = -1;
	loadTexture();
}

Text::~Text()
{
}

char* Text::getName()
{
	return this->path;
}
void Text::loadTexture()
{
	int w, h;
	if (box)
	{
		this->id = Window::renderTextBox(this->text, w, h, this->t_width, this->t_height, NULL);
	}
	else
	{
		this->id = Window::renderText(this->text, w, h, NULL);
		this->x += (this->width - w) / 2;
		this->y += (this->height - h) / 2;
	}
	this->width = w;
	this->height = h;
}