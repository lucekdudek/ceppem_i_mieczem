#ifndef SRC_VIEW_ELEMENT_H_
#define SRC_VIEW_ELEMENT_H_

#include <list>
#include <string>

using namespace std;

class Element {
public:
	Element(int x, int y, int width=0, int height=0);
	~Element();

	void addTexture(unsigned int id);
	void setOnClick();
	void setOnHover();
	list<unsigned int> getTextures();
private:
	list<unsigned int> textures;
	int x;
	int y;
	int width;
	int height;
	string text;

	bool isClickable;
};

#endif /* SRC_VIEW_ELEMENT_H_ */
