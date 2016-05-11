#include "itemz.h"

Itemz::Itemz(std::string name_original)
{
	name = "-";
	goldValue = 100;
	id = 0;
	this->name_original = name_original;
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

std::string Itemz::getItemOriginalName()
{
	return name_original;
}