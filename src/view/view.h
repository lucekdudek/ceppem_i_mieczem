#ifndef SRC_VIEW_VIEW_H_
#define SRC_VIEW_VIEW_H_
#include <list>
#include "../model/element.h"

class View {
public:
	View(std::list<Element*> elements);
	~View();
	std::list<Element*> getList();
	void setText(char* name, std::string text);
	void setOnHoverText(char* name, std::string text);
	void extendView(View* v, bool locked = false);
	void removeLastView();
	int getClickMap();
private:
	std::list<Element*> elements;
	std::list<int> views;
	std::list<int> clickMap;
};

#endif /* SRC_VIEW_VIEW_H_ */
