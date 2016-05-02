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
	this->onhover = NULL;
}

Element::~Element() {
	/*if(this->onhover != NULL){
		delete this->onhover;
	}*/
}

void Element::addTexture(Texture texture) {
	texture.setX(texture.getX()+this->x);
	texture.setY(texture.getY()+this->y);
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

std::list<Texture> Element::getTextures() {
	return textures;
}

void Element::loadTextures() {
	if(this->onhover!=NULL){
		this->onhover->loadTexture();
	}
	for (auto i = textures.begin(); i != textures.end();) {
		auto tmpElem = *i;
		i = textures.erase(i);
		tmpElem.loadTexture();
		textures.insert(i, tmpElem);
	}
}

void Element::setText(char* name, char* text){
	for (auto i = textures.begin(); i != textures.end();) {
		auto tmpElem = *i;
		i = textures.erase(i);
		if(strcmp(tmpElem.getName(),name)==0){
			tmpElem.setText(text);
			tmpElem.loadTexture();
		}
		textures.insert(i, tmpElem);
	}
}
