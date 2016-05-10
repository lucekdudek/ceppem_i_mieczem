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

int Inventory::getLength()
{
	int result = 0;
	/*for(std::list<Itemz*>::iterator it = itemList.begin(); it != itemList.end(); it++)
	{
		result++;
	}*/
	return result;
}

Inventory::Inventory()
{
	
}

Inventory::~Inventory()
{

}