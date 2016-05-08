#include "texture.h"
#include "window.h"

Texture::Texture(int x, int y, int width, int height, char* path) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	std::string s = path;
	s.copy(this->path, 256, 0);
	this->path[strlen(path)] = '\0';
	this->text[0] = '\0';
	this->id = -1;
	loadTexture();
}

Texture::Texture()
{

}

Texture::~Texture() {
	unloadTexture();
}

void Texture::loadTexture() {
	unloadTexture();
	this->id = Window::loadGLTexture(path);
}

void Texture::unloadTexture(){
	if (this->id > 0) {
		Window::unloadGLTexture(this->id);
	}
}

void Texture::setText(char* text, char* name) {
	std::string str = this->text;
	std::string str2 = "";
	if (name != NULL)
	{
		str2 = name;
		str.replace(str.find(str2), str2.length(), text);
		str.copy(this->text, 1024, 0);
		this->text[str.length()] = '\0';
	}
	else
	{
		std::string(text).copy(this->text, 1024, 0);
		this->text[strlen(text)] = '\0';
	}
	/*std::cout << str2 << std::endl;
	std::cout << str << std::endl;*/
	


	loadTexture();
}

char* Texture::getPath()
{
	return this->path;
}