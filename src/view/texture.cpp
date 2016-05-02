#include "texture.h"
#include "window.h"

Texture::Texture(int x, int y, int width, int height, char* path) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	std::string(path).copy(this->path, 256, 0);
	this->path[strlen(path)] = '\0';
	this->text[0] = '\0';
	this->id = -1;
}

Texture::Texture(int x, int y, int width, int height, char* text,
		TTF_Font *font) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;

	this->tx = x;
	this->ty = y;
	this->twidth = width;
	this->theight = height;

	std::string s=text;

	s.copy(this->text, 256, 0);
	this->text[strlen(text)] = '\0';

	s.copy(this->path, 256, 0);
	this->path[strlen(text)] = '\0';

	this->id = -1;
}

Texture::~Texture() {
	// TODO Auto-generated destructor stub
}

void Texture::loadTexture() {
	if (strlen(this->text) > 0) {
		if(this->id > 0){
			unloadTexture();
		}
		int w, h;
		this->id = Window::renderText(this->text, w, h, NULL);
		this->x += (this->width - w) / 2;
		this->y += (this->height - h) / 2;
		this->width = w;
		this->height = h;
	} else {
		this->id = Window::loadGLTexture(path);
	}
}

void Texture::unloadTexture(){
	Window::unloadGLTexture(this->id);
}

void Texture::setText(char* text) {
	std::string(text).copy(this->text, 256, 0);
	this->text[strlen(text)] = '\0';
}

char* Texture::getName(){
	return this->path;
}
