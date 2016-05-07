#include "wearable.h"

Wearable::Wearable(int id, std::string name, int slot, int goldValue, int armor, int bonusStrength, int bonusDexterity, int bonusAgility, int bonusWisdom, int bonusInteligence, int bonusCharisma)
{
	Wearable::id = id;
	Wearable::name = name;
	Wearable::slot = slot;
	Wearable::goldValue = goldValue;
	Wearable::armor = armor;
	Wearable::agility = bonusAgility;
	Wearable::charisma = bonusCharisma;
	Wearable::dexterity = bonusDexterity;
	Wearable::wisdom = bonusWisdom;
	Wearable::inteligence = bonusInteligence;
	Wearable::charisma = bonusCharisma;
}

Wearable::~Wearable()
{

}

int Wearable::getId()
{
	return id;
}
std::string Wearable::getName()
{
	return name;
}
int Wearable::getArmor()
{
	return armor;
}
int Wearable::getSlot()
{
	return slot;
}
int Wearable::getGoldValue()
{
	return goldValue;
}

int Wearable::getStrength()
{
	return strength;
}
int Wearable::getDexterity()
{
	return dexterity;
}
int Wearable::getAgility()
{
	return agility;
}
int Wearable::getWisdom()
{
	return wisdom;
}
int Wearable::getInteligence()
{
	return inteligence;
}
int Wearable::getCharisma()
{
	return charisma;
}

void Wearable::setId(int value)
{
	id = value;
}
void Wearable::setName(std::string value)
{
	name = value;
}
void Wearable::setSlot(int value)
{
	slot = value;
}
void Wearable::setGoldValue(int value)
{
	goldValue = value;
}
void Wearable::setArmor(int value)
{
	armor = value;
}
void Wearable::setStrength(int value)
{
	strength = value;
}
void Wearable::setDexterity(int value)
{
	dexterity = value;
}
void Wearable::setAgility(int value)
{
	agility = value;
}
void Wearable::setWisdom(int value)
{
	wisdom = value;
}
void Wearable::setInteligence(int value)
{
	inteligence = value;
}
void Wearable::setCharisma(int value)
{
	charisma;
}