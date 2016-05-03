//
// Created by Aschali on 02.05.2016.
//

#include "character.h"

Character::Character(int basic, int points): points(points), strength(basic), dexterity(basic), agility(basic), wisdom(basic), inteligence(basic), charisma(basic)
{

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
	if (strength > 1)
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
	if (dexterity > 1)
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
	if (agility > 1)
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
	if (wisdom > 1)
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
	if (inteligence > 1)
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
	if (charisma > 1)
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

























