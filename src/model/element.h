#ifndef SRC_VIEW_ELEMENT_H_
#define SRC_VIEW_ELEMENT_H_

#include "../view/texture.h"
#include <list>
#include <string>

using namespace std;

class Element {
public:
	Element(int x, int y, int width=0, int height=0);
	~Element();

	void addTexture(Texture texture);
	void setOnClick();
	void setOnHover();
	list<Texture> getTextures();
	int x;
	int y;
	int width;
	int height;
private:
	list<Texture> textures;
	string text;

	bool isClickable;
};

#endif /* SRC_VIEW_ELEMENT_H_ */
