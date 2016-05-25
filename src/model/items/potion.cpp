#include "potion.h"

Potion::Potion(int id, std::string name, std::string name_original, std::string description, int goldValue, int healing, int stack) :Itemz(name_original)
{
	Potion::id = id;
	Potion::name = name;
	Potion::goldValue = goldValue;
	Potion::healing = healing;
	Potion::stack = stack;
	Potion::description = description;
}

Potion::~Potion()
{
	
}

std::string Potion::getType()
{
	return "potion";
}

int Potion::use()
{
	if (stack > 0)
	{
		stack--;
		return healing;
	}
		
	else return 0;
}

std::string Potion::getSize()
{
	char buff[3];
	return std::to_string(this->stack);
}

void Potion::setSize(int size)
{
	stack = size;
}