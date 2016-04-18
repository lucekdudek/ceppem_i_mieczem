#include "element.h"
#include <iostream>

Element::Element(int x, int y, int width, int height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	isClickable = false;
}

Element::~Element() {

}

void Element::addTexture(Texture texture) {
	texture.x+=this->x;
	texture.y+=this->y;
	textures.push_back(texture);
}

void Element::setOnClick() {
	isClickable = true;
}

void Element::setOnHover() {

}

list<Texture> Element::getTextures() {
		return textures;
}
