#include "itemz.h"

Itemz::Itemz()
{

}

Itemz::~Itemz()
{

}

std::string Itemz::getType()
{
	return "uninherited";
}

int Itemz::getId()
{
	return id;
}
std::string Itemz::getName()
{
	return name;
}
std::string Itemz::getDescription()
{
	return description;
}
int Itemz::getGoldValue()
{
	return goldValue;
}

void Itemz::setId(int id)
{
	Itemz::id = id;
}
void Itemz::setName(std::string name)
{
	Itemz::name = name;
}
void Itemz::setDescription(std::string description)
{
	Itemz::description = description;
}
void Itemz::setGoldValue(int value)
{
	Itemz::goldValue = value;
}