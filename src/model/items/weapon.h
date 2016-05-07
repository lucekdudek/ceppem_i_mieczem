#ifndef WEAPON_H
#define WEAPON_H

#include "itemz.h"

class Weapon: Itemz
{
public:
	Weapon(int id, std::string name, int goldValue, int minDamage, int maxDamage, int bonusStrength, int bonusDexterity, int bonusAgility, int bonusWisdom, int bonusInteligence, int bonusCharisma);
	~Weapon();
	
	int getId();
	std::string getName();
	int getGoldValue();
	int getMinDamage();
	int getMaxDamage();
	int getStrength();
	int getDexterity();
	int getAgility();
	int getWisdom();
	int getInteligence();
	int getCharisma();

	void setId(int value);
	void setName(std::string value);
	void setGoldValue(int value);
	void setMinDamage(int value);
	void setMaxDamage(int value);
	void setStrength(int value);
	void setDexterity(int value);
	void setAgility(int value);
	void setWisdom(int value);
	void setInteligence(int value);
	void setCharisma(int value);
private:
	int minDamage;
	int maxDamage;
	int strength;
	int dexterity;
	int agility;
	int wisdom;
	int inteligence;
	int charisma;
};

#endif