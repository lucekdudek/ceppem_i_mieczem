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
	setText("{newGame}","Nowa gra");
	setText("{settings}","Ustawienia");
	setText("{exitGame}","Wyjście");
}

View::~View() {
	// TODO Auto-generated destructor stub
}

std::list<Element> View::getList() {
	return this->elements;
}

void View::setText(char* name, char* text) {
	for (auto i = this->elements.begin(); i != this->elements.end();) {
		auto tmpElem = *i;
		i = this->elements.erase(i);
		tmpElem.setText(name,text);
		this->elements.insert(i, tmpElem);
	}
}
