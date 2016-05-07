#ifndef WEARABLE_H
#define WEARABLE_H
#include "itemz.h"

class Wearable: Itemz
{
public:
	Wearable(int id, std::string name, int slot, int goldValue, int armor, int bonusStrength, int bonusDexterity, int bonusAgility, int bonusWisdom, int bonusInteligence, int bonusCharisma);
	~Wearable();

	int getId();
	std::string getName();
	int getSlot();
	int getGoldValue();
	int getArmor();
	int getStrength();
	int getDexterity();
	int getAgility();
	int getWisdom();
	int getInteligence();
	int getCharisma();

	void setId(int value);
	void setName(std::string value);
	void setSlot(int value);
	void setGoldValue(int value);
	void setArmor(int value);
	void setStrength(int value);
	void setDexterity(int value);
	void setAgility(int value);
	void setWisdom(int value);
	void setInteligence(int value);
	void setCharisma(int value);

private:
	int armor;
	int slot;
	int strength;
	int dexterity;
	int agility;
	int wisdom;
	int inteligence;
	int charisma;
};
#endif