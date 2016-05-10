#ifndef WEAPON_H
#define WEAPON_H

#include "itemz.h"

class Weapon: public Itemz
{
public:
	Weapon(int id, std::string name, std::string description, int goldValue, int minDamage, int maxDamage, int bonusStrength, int bonusDexterity, int bonusAgility, int bonusWisdom, int bonusInteligence, int bonusCharisma);
	~Weapon();
	
	std::string getType();

	int getMinDamage();
	int getMaxDamage();
	int getStrength();
	int getDexterity();
	int getAgility();
	int getWisdom();
	int getInteligence();
	int getCharisma();

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