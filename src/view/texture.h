/*
 * texture.h
 *
 *  Created on: 18 kwi 2016
 *      Author: Michal
 */

#ifndef SRC_VIEW_TEXTURE_H_
#define SRC_VIEW_TEXTURE_H_
#include "SDL2/SDL_ttf.h"
#include <iostream>
#include <string>

class Texture {
public:
	Texture(int x, int y, int width, int height, char* path);
	Texture(int x, int y, int width, int height, char* text, TTF_Font *font);
	virtual ~Texture();
	void loadTexture();
	void unloadTexture();
	void setText(char* text);
	char* getName();

	int getHeight() const {
		return height;
	}

	int getId() const {
		return id;
	}

	int getWidth() const {
		return width;
	}

	int getX() const {
		return x;
	}

	int getY() const {
		return y;
	}

	void setX(int x) {
		this->x = x;
	}

	void setY(int y) {
		this->y = y;
	}

private:
	int x;
	int y;
	int width;
	int height;
	int id;

	int tx;
	int ty;
	int twidth;
	int theight;
	char path[256];
	char text[256];
};

#endif /* SRC_VIEW_TEXTURE_H_ */
