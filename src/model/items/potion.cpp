#include "potion.h"

Potion::Potion(int id, std::string name, std::string description, int goldValue, int healing, int stack)
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