#include "texture.h"
#include "window.h"
#include <iostream>

Texture::Texture(int x, int y, int width, int height, char* path) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	std::string(path).copy(this->path,256,0);
	this->path[strlen(path)]='\0';
	this->text[0]='\0';
	this->id=-1;
}

Texture::Texture(int x, int y, int width, int height, char* text, TTF_Font *font) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	std::string(text).copy(this->text,256,0);
	this->text[strlen(text)]='\0';
	this->path[0]='\0';
	this->id=-1;
}

Texture::~Texture() {
	// TODO Auto-generated destructor stub
}

void Texture::loadTexture(){
	if(strlen(this->text)>0){
		int w,h;
		this->id = Window::renderText(this->text, w, h, NULL);
		this->x += (this->width-w)/2;
		this->y += (this->height-h)/2;
		this->width = w;
		this->height = h;
	}else{
		this->id = Window::loadGLTexture(path);
	}
}
