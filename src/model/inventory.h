#pragma once

#include "items\itemz.h"
#include <list>
class Inventory
{
public:
	void putItem(Itemz* item);
	Itemz* getItem(int itemNumber);

	Inventory();
	~Inventory();
private:
	std::list<Itemz*> itemList;
};

