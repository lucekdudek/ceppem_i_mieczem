//
// Created by Aschali on 02.05.2016.
//

#ifndef CEPEM_I_MIECZEM_CHAR_H
#define CEPEM_I_MIECZEM_CHAR_H
#include "items/itemz.h"
#include "inventory.h"

class Character
{
public:
    Character(int basic=4, int points=10);
	Character(int st, int dex, int ag, int wi, int in, int ch, int pkt = 0);
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

	Itemz* weapon;
	Itemz* head;
	Itemz* chest;
	Itemz* legs;
	Itemz* feet;
	Itemz* hands;
	Itemz* slot1;
	Itemz* slot2;

	Inventory* backpack;
};

#endif //CEPEM_I_MIECZEM_CHAR_H