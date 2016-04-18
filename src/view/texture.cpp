/*
 * texture.cpp
 *
 *  Created on: 18 kwi 2016
 *      Author: Michal
 */

#include "texture.h"
#include "window.h"
#include <iostream>

Texture::Texture(int x, int y, int width, int height, char* path) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	string(path).copy(this->path,256,0);
	this->path[strlen(path)]='\0';
}

Texture::~Texture() {
	// TODO Auto-generated destructor stub
}

void Texture::loadTexture(){
	this->id = Window::loadGLTexture(path);
}
