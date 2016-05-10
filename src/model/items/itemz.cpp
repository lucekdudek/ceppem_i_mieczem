#include "itemz.h"

Itemz::Itemz()
{
	name = "-";
	goldValue = 100;
	id = 0;
}

Itemz::~Itemz()
{

}

int Itemz::getId()
{
	return id;
}
std::string Itemz::getName()
{
	return name;
}
int Itemz::getGoldValue()
{
	return goldValue;
}