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

void View::setText(char* name, std::string text) {
	char * t = _strdup(text.c_str());
	for (auto i = this->elements.begin(); i != this->elements.end();) {
		auto tmpElem = *i;
		i = this->elements.erase(i);
		tmpElem->setText(name,t);
		this->elements.insert(i, tmpElem);
	}
}
