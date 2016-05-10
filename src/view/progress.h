#pragma once
#include "texture.h"
class Progress :
	public Texture
{
public:
	Progress(int x, int y, int width, int height, char* name, char* path);
	~Progress();

	void setFill(unsigned char fill);
	char* getName();
private:
	char* name;
	unsigned char fill;
	int max_width;
};

