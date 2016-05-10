#include "element.h"
#include <iostream>
#include <string.h>

Element::Element(int x, int y, int width, int height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	isClickable = false;
	isHoverable = false;
	this->onhover = nullptr;
}

Element::~Element() {
	if(this->onhover != nullptr){
		delete this->onhover;
	}

	for (auto i = textures.begin(); i != textures.end();i++) {
		auto tmpElem = *i;
		delete tmpElem;
	}
}

void Element::addTexture(Texture* texture) {
	texture->setX(texture->getX()+this->x);
	texture->setY(texture->getY()+this->y);
	textures.push_back(texture);
}

void Element::setOnClick(std::string onclick) {
	isClickable = true;
	this->onclick = onclick;
}
std::string Element::getOnClick() {
	return this->onclick;
}

bool Element::clickable() {
	return isClickable;
}

void Element::setOnHover(Texture* t) {
	isHoverable = true;
	t->setX(t->getX()+this->x);
	t->setY(t->getY()+this->y);
	this->onhover = t;
}

Texture* Element::getOnHover() {
	if(!isHoverable){
		return NULL;
	}
	return this->onhover;
}

std::list<Texture*> Element::getTextures() {
	return textures;
}

void Element::setText(char* name, char* text){
	for (auto i = textures.begin(); i != textures.end();i++) {
		auto tmpElem = *i;
		if (Text* t = dynamic_cast<Text*>(tmpElem))
		{
			char * pch = strstr(t->getName(), name);
			if (strcmp(t->getName(), name) == 0)
			{
				tmpElem->setText(text);
			}
			else if (pch != NULL)
			{
				tmpElem->setText(text, name);
			}
		}
	}
}

void Element::setFill(char* name, unsigned char fill)
{
	for (auto i = textures.begin(); i != textures.end(); i++)
	{
		auto tmpElem = *i;
		if (Progress* t = dynamic_cast<Progress*>(tmpElem))
		{
			if (strcmp(t->getName(), name) == 0)
			{
				t->setFill(fill);
			}
		}
	}
}