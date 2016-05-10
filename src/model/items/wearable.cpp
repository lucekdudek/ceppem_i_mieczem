#include "wearable.h"

Wearable::Wearable(int id, std::string name, std::string description, int slot, int goldValue, int armor, int bonusStrength, int bonusDexterity, int bonusAgility, int bonusWisdom, int bonusInteligence, int bonusCharisma)
{
	Wearable::id = id;
	Wearable::name = name;
	Wearable::description = description;
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

std::string Wearable::getType()
{
	return "wearable";
}

int Wearable::getArmor()
{
	return armor;
}
int Wearable::getSlot()
{
	return slot;
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