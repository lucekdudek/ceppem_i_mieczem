//
// Created by Aschali on 02.05.2016.
//

#ifndef CEPEM_I_MIECZEM_CHAR_H
#define CEPEM_I_MIECZEM_CHAR_H
#include "items/itemz.h"
#include "items/wearable.h"
#include "items/weapon.h"
#include "inventory.h"

class Character
{
public:
    Character(int basic=4, int points=10);
	Character(int st, int dex, int ag, int wi, int in, int ch, int health, int gold, int pkt = 0);
	int getPoints();
    int getStrength();
	void decStrength();
    void incStrength();
    void setStrength(int value);
    int getDexterity();
    void decDexterity();
    void incDexterity();
    void setDexterity(int value);
    int getAgility();
    void decAgility();
    void incAgility();
    void setAgility(int value);
    int getWisdom();
    void decWisdom();
    void incWisdom();
    void setWisdom(int value);
    int getInteligence();
    void decInteligence();
    void incInteligence();
    void  setInteligence(int value);
    int getCharisma();
    void decCharisma();
    void incCharisma();
    void setCharisma(int value);
	void saveAttributes();
	void clearAttributes();
	int getHealth();
	void incHealth(int value);
	void decHealth(int value);
	int getGold();
	void incGold(int value);
	void decGold(int value);
	Itemz *getInventoryItem(int number);
	char *getInventoryItemName(int number);
	int getInventorySize();
	void wearHead(Wearable *item);
	void wearChest(Wearable *item);
	void wearLegs(Wearable *item);
	void wearFeet(Wearable *item);
	void wearHands(Wearable *item);
	void wearWeapon(Weapon *item);
	void addItem(Itemz* item);
	std::string eqToString();
	std::string getWeaponName();
	void throwItem(Itemz* item);
	int getAttack();
private:
	int points;
	int strength;
	int min_strength;
	int dexterity;
	int min_dexterity;
    int agility;
    int min_agility;
    int wisdom;
    int min_wisdom;
    int inteligence;
    int min_inteligence;
    int charisma;
    int min_charisma;
	int health;
	int gold;

	Itemz* weapon;
	Itemz* head;
	Itemz* chest;
	Itemz* legs;
	Itemz* feet;
	Itemz* hands;

	Inventory* backpack;
};

#endif //CEPEM_I_MIECZEM_CHAR_H