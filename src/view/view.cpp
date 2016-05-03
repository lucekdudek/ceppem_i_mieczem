#include "view.h"
#include <iostream>

View::View(std::list<Element*> elements) {
	this->elements = elements;
}

View::~View() {
	for (auto i = this->elements.begin(); i != this->elements.end();) {
		auto tmpElem = *i;
		i = this->elements.erase(i);
		delete tmpElem;
		this->elements.insert(i, tmpElem);
	}
}

std::list<Element*> View::getList() {
	return this->elements;
}

void View::setText(char* name, char* text) {
	for (auto i = this->elements.begin(); i != this->elements.end();) {
		auto tmpElem = *i;
		i = this->elements.erase(i);
		tmpElem->setText(name,text);
		this->elements.insert(i, tmpElem);
	}
}
