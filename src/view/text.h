#ifndef TEXT_H_
#define TEXT_H_
#include "texture.h"
class Text :
	public Texture
{
public:
	Text(int x, int y, int width, int height, char* text, TTF_Font *font);
	~Text();
	char* getName();
};
#endif //TEXT_H_