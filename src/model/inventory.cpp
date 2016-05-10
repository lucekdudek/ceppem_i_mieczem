#include "inventory.h"

void Inventory::putItem(Itemz* item)
{
	itemList.push_back(item);
}

Itemz* Inventory::getItem(int itemNumber)
{
	std::list<Itemz*>::iterator it = itemList.begin();
	std::advance(it, itemNumber);
	return *it;
}

Inventory::Inventory()
{
	
}

Inventory::~Inventory()
{

}