#ifndef SRC_VIEW_ELEMENT_H_
#define SRC_VIEW_ELEMENT_H_

#include "../view/texture.h"
#include <list>
#include <string>

class Element {
public:
	Element(int x, int y, int width=0, int height=0);
	~Element();

	void addTexture(Texture texture);
	void setOnClick(std::string onclick);
	std::string getOnClick();
	void setOnHover(Texture* t);
	Texture* getOnHover();
	std::list<Texture> getTextures();
	void loadTextures();
	bool clickable();
	void setText(char* name, char* text);

	int getHeight() const {
		return height;
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

	int getHheight() const {
		return hheight;
	}

	int getHwidth() const {
		return hwidth;
	}

	int getHx() const {
		return hx;
	}

	int getHy() const {
		return hy;
	}

private:
	std::list<Texture> textures;
	std::string text;

	bool isClickable;
	std::string onclick;
	bool isHoverable;
	Texture *onhover;
	int hx;
	int hy;
	int hwidth;
	int hheight;

	int x;
	int y;
	int width;
	int height;
};

#endif /* SRC_VIEW_ELEMENT_H_ */
