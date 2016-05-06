//
// Created by Aschali on 02.05.2016.
//

#include "character.h"

Character::Character(int basic, int points)
{
	this->points = points;
	strength = basic;
	min_strength = basic;
	agility = basic;
	min_agility = basic;
	dexterity = basic;
	min_dexterity = basic;
	wisdom = basic;
	min_wisdom = basic;
	inteligence = basic;
	min_inteligence = basic;
	charisma = basic;
	min_charisma = basic;
}

int Character::getPoints()
{
	return points;
}

int Character::getStrength()
{
    return strength;
}

int Character::getDexterity()
{
    return dexterity;
}

int Character::getAgility()
{
    return agility;
}

int Character::getWisdom()
{
    return wisdom;
}

int Character::getInteligence()
{
    return inteligence;
}

int Character::getCharisma()
{
    return charisma;
}

void Character::setStrength(int value)
{
    strength = value;
}

void Character::setDexterity(int value)
{
    dexterity = value;
}

void Character::setAgility(int value)
{
    agility = value;
}

void Character::setWisdom(int value)
{
    wisdom = value;
}

void Character::setInteligence(int value)
{
    inteligence = value;
}

void Character::setCharisma(int value)
{
    charisma = value;
}

void Character::decStrength()
{
	if (strength > min_strength)
	{
		strength--;
		points++;
	}
}

void Character::incStrength()
{
	if (strength < 10 && points > 0)
	{
		strength++;
		points--;
	}
}

void Character::decDexterity()
{
	if (dexterity > min_dexterity)
	{
		dexterity--;
		points++;
	}
}

void Character::incDexterity()
{
	if (dexterity < 10 && points > 0)
	{
		dexterity++;
		points--;
	}
}

void Character::decAgility()
{
	if (agility > min_agility)
	{
		agility--;
		points++;
	}
}

void Character::incAgility()
{
	if (agility < 10 && points > 0)
	{
		agility++;
		points--;
	}
}

void Character::decWisdom()
{
	if (wisdom > min_wisdom)
	{
		wisdom--;
		points++;
	}
}

void Character::incWisdom()
{
	if (wisdom < 10 && points > 0)
	{
		wisdom++;
		points--;
	}
}

void Character::decInteligence()
{
	if (inteligence > min_inteligence)
	{
		inteligence--;
		points++;
	}
}

void Character::incInteligence()
{
	if (inteligence < 10 && points > 0)
	{
		inteligence++;
		points--;
	}
}

void Character::decCharisma()
{
	if (charisma > min_charisma)
	{
		charisma--;
		points++;
	}
}

void Character::incCharisma()
{
	if (charisma < 10 && points > 0)
	{
		charisma++;
		points--;
	}
}

void Character::saveAttributes()
{
	min_strength = strength;
	min_agility = agility;
	min_dexterity = dexterity;
	min_wisdom = wisdom;
	min_inteligence = inteligence;
	min_charisma = charisma;
}

void Character::clearAttributes()
{
	strength = min_strength;
	agility = min_agility;
	dexterity = min_dexterity;
	wisdom = min_wisdom;
	inteligence = min_inteligence;
	charisma = min_charisma;
}
