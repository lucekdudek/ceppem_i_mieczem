#include "weapon.h"

Weapon::Weapon(int id, std::string name, int goldValue, int minDamage, int maxDamage, int bonusStrength, int bonusDexterity, int bonusAgility, int bonusWisdom, int bonusInteligence, int bonusCharisma)
{
	Weapon::id = id;
	Weapon::name = name;
	Weapon::goldValue = goldValue;
	Weapon::minDamage = minDamage;
	Weapon::maxDamage = maxDamage;
	Weapon::agility = bonusAgility;
	Weapon::charisma = bonusCharisma;
	Weapon::dexterity = bonusDexterity;
	Weapon::wisdom = bonusWisdom;
	Weapon::inteligence = bonusInteligence;
	Weapon::charisma = bonusCharisma;
}


Weapon::~Weapon()
{
}

int Weapon::getId()
{
	return id;
}
std::string Weapon::getName()
{
	return name;
}
int Weapon::getGoldValue()
{
	return goldValue;
}
int Weapon::getMinDamage()
{
	return minDamage;
}
int Weapon::getMaxDamage()
{
	return maxDamage;
}
int Weapon::getStrength()
{
	return strength;
}
int Weapon::getDexterity()
{
	return dexterity;
}
int Weapon::getAgility()
{
	return agility;
}
int Weapon::getWisdom()
{
	return wisdom;
}
int Weapon::getInteligence()
{
	return inteligence;
}
int Weapon::getCharisma()
{
	return charisma;
}

void Weapon::setId(int value)
{
	id = value;
}
void Weapon::setName(std::string value)
{
	name = value;
}
void Weapon::setGoldValue(int value)
{
	goldValue = value;
}
void Weapon::setMaxDamage(int value)
{
	maxDamage = value;
}
void Weapon::setMinDamage(int value)
{
	minDamage = value;
}
void Weapon::setStrength(int value)
{
	strength = value;
}
void Weapon::setDexterity(int value)
{
	dexterity = value;
}
void Weapon::setAgility(int value)
{
	agility = value;
}
void Weapon::setWisdom(int value)
{
	wisdom = value;
}
void Weapon::setInteligence(int value)
{
	inteligence = value;
}
void Weapon::setCharisma(int value)
{
	charisma;
}