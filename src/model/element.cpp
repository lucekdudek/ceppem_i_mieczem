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
	texture.x += this->x;
	texture.y += this->y;
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

void Element::setOnHover() {

}

std::list<Texture> Element::getTextures() {
	return textures;
}

void Element::loadTextures() {
	for (auto i = textures.begin(); i != textures.end();) {
		auto &tmpElem = *i;
		i = textures.erase(i);
		tmpElem.load();
		textures.insert(i, tmpElem);
	}
}

void Element::removeTextures() {
	for (auto i = textures.begin(); i != textures.end();) {
		auto tmpElem = *i;
		i = textures.erase(i);
		tmpElem.remove();
		textures.insert(i, tmpElem);
	}
}
