#ifndef SRC_VIEW_VIEW_H_
#define SRC_VIEW_VIEW_H_
#include <list>
#include "../model/element.h"

class View {
public:
	View(std::list<Element> textures);
	~View();
private:
	std::list<Element> textures;
};

#endif /* SRC_VIEW_VIEW_H_ */
