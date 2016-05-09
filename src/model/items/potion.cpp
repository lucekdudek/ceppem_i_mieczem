#include "potion.h"



Potion::Potion(int id, std::string name, int goldValue, int healing, int stack)
{
	Potion::id = id;
	Potion::name = name;
	Potion::goldValue = goldValue;
	Potion::healing = healing;
	Potion::stack = stack;
}

Potion::~Potion()
{
	
}

int Potion::use()
{
	if (stack > 0)
		return healing;
	else return 0;
}

void Potion::setId(int value)
{
	id = value;
}
void Potion::setName(std::string value)
{
	name = value;
}
void Potion::setGoldValue(int value)
{
	goldValue = value;
}