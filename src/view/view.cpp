#include "view.h"
#include <iostream>

View::View(std::list<Element> textures) {
	this->textures = textures;
}

View::~View() {
	// TODO Auto-generated destructor stub
}

std::list<Element> View::getList(){
	return this->textures;
}
