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
	~Texture();
	void setText(char* text, char* name=NULL);
	char* getPath();

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

	virtual void setX(int x) {
		this->x = x;
	}

	virtual void setY(int y) {
		this->y = y;
	}

protected:
	Texture();
	virtual void loadTexture();
	void unloadTexture();

	int x;
	int y;
	int width;
	int height;
	int id;

	char path[256];
	char text[1024];
};

#endif /* SRC_VIEW_TEXTURE_H_ */
