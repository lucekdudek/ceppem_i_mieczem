#include "text.h"
#include "window.h"

Text::Text(int x, int y, int width, int height, char* text, int fontSize, bool box)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;

	this->t_x = x;
	this->t_y = y;
	this->t_width = width;
	this->t_height = height;
	this->box = box;

	std::string s = text;

	s.copy(this->text, 256, 0);
	this->text[strlen(text)] = '\0';

	s.copy(this->path, 256, 0);
	this->path[strlen(text)] = '\0';

	this->id = -1;

	this->r = 128;
	this->g = 0;
	this->b = 0;
	if (fontSize == 0)
	{
		this->fontSize = 50;
	}
	else
	{
		this->fontSize = fontSize;
	}

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
	unloadTexture();
	int w, h;
	if (box)
	{
		this->id = Window::renderTextBox(this->text, w, h, this->t_width, this->t_height, this->fontSize, this->r, this->g, this->b);
	}
	else
	{
		this->id = Window::renderText(this->text, w, h, this->fontSize, this->r, this->g, this->b);
		this->x = this->x + (this->width - w) / 2;
		this->y = this->y + (this->height - h) / 2;
	}
	this->width = w;
	this->height = h;
}

void Text::setColor(unsigned char r, unsigned char g, unsigned char b)
{
	this->r = r;
	this->g = g;
	this->b = b;
	loadTexture();
}