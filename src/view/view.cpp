#include "view.h"
#include <iostream>

View::View(std::list<Element> elements) {
	this->elements = elements;

	for (auto i = this->elements.begin(); i != this->elements.end();) {
		auto tmpElem = *i;
		i = this->elements.erase(i);
		tmpElem.loadTextures();
		this->elements.insert(i, tmpElem);
	}
}

View::~View() {
	for (auto i = this->elements.begin(); i != this->elements.end();) {
		auto tmpElem = *i;
		i = this->elements.erase(i);
		tmpElem.removeTextures();
		this->elements.insert(i, tmpElem);
	}
}

std::list<Element> View::getList() {
	return this->elements;
}
