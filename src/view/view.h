#ifndef SRC_VIEW_VIEW_H_
#define SRC_VIEW_VIEW_H_
#include <list>
#include "../model/element.h"

class View {
public:
	View(std::list<Element*> elements);
	~View();
	std::list<Element*> getList();
	void setText(char* name, char* text);
private:
	std::list<Element*> elements;
};

#endif /* SRC_VIEW_VIEW_H_ */
