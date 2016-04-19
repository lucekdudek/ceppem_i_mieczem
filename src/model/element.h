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
	void setOnHover();
	std::list<Texture> getTextures();
	void loadTextures();
	bool clickable();
	int x;
	int y;
	int width;
	int height;
private:
	std::list<Texture> textures;
	std::string text;

	bool isClickable;
	std::string onclick;
};

#endif /* SRC_VIEW_ELEMENT_H_ */
