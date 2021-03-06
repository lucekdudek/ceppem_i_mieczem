#ifndef TEXT_H_
#define TEXT_H_
#include "texture.h"
class Text :
	public Texture
{
public:
	Text(int x, int y, int width, int height, char* text, int fontSize, bool box=false);
	~Text();
	char* getName();
	void loadTexture();
	void setColor(unsigned char r, unsigned char g, unsigned char b);

	virtual void setX(int x)
	{
		this->x = x;
		this->t_x = x;
	}

	virtual void setY(int y)
	{
		this->y = y;
		this->t_y = y;
	}
private:
	bool box;
	int t_x;
	int t_y;
	int t_width;
	int t_height;
	char r, g, b;
	int fontSize;
};
#endif //TEXT_H_