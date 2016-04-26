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
	std::string(path).copy(this->path, 256, 0);
	this->path[strlen(path)] = '\0';
	this->id = -1;
	this->text[0]='\0';
}

Texture::Texture(int x, int y, int width, int height, char* text, TTF_Font *text_font){
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->id = -1;

	this->path[0] = '\0';
	std::string(text).copy(this->text, 256, 0);
	this->text[strlen(text)] = '\0';
	this->text_font=text_font;
	std::cout<<this->text_font<<std::endl;
}

Texture::~Texture() {

}
void Texture::remove() {
	if (this->id != -1) {
		Window::removeGLTexture(this->id);
	}
}

void Texture::load() {
	if (this->id == -1) {
		if(strlen(this->text)==0){
			this->id = Window::loadGLTexture(path);
		}else{
			std::cout<<text_font<<std::endl;
			Text t = Window::renderText(this->text, text_font);
			std::cout<<text_font<<std::endl;
			this->id = t.id;
			this->x += (this->width-t.width)/2;
			this->y += (this->height-t.height)/2;
			this->width = t.width;
			this->height = t.height;
		}
	}
}
