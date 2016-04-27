/*
 * texture.h
 *
 *  Created on: 18 kwi 2016
 *      Author: Michal
 */

#ifndef SRC_VIEW_TEXTURE_H_
#define SRC_VIEW_TEXTURE_H_
#include "SDL2/SDL_ttf.h"

class Texture {
public:
	Texture(int x, int y, int width, int height, char* path);
	Texture(int x, int y, int width, int height, char* text, TTF_Font *font);
	virtual ~Texture();
	void loadTexture();

	int x;
	int y;
	int width;
	int height;
	int id;
	char path[256];
	char text[256];
};

#endif /* SRC_VIEW_TEXTURE_H_ */
