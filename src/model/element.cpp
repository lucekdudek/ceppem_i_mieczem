#include "element.h"

Element::Element(int x, int y, int width, int height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	isClickable = false;
}

Element::~Element() {

}

void Element::addTexture(unsigned int id) {
	textures.push_back(id);
}

void Element::setOnClick() {
	isClickable = true;
}

void Element::setOnHover() {

}

list<unsigned int> Element::getTextures() {
	return textures;
}
