//
// Created by Aschali on 02.05.2016.
//

#include <iostream>
#include <ctime>
#include "character.h"

const int MAX_ATTRIBUTE = 99;

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
	health = 100;
	backpack = new Inventory();
	gold = 2000;
}

Character::Character(int st, int dex, int ag, int wi, int in, int ch, int health, int gold, int pkt)
{
	points = pkt;
	min_strength = strength = st;
	min_dexterity = dexterity = dex;
	min_agility = agility = ag;
	min_wisdom = wisdom = wi;
	min_inteligence = inteligence = in;
	min_charisma = charisma = ch;
	this->health = health;
	this->gold = gold;
	backpack = new Inventory();
}

Character::~Character()
{
	for(int i = 0; i < backpack->getLength(); i++)
	{
		backpack->throwItem(backpack->getItem(0));
	}
	delete backpack;
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
	if (strength < MAX_ATTRIBUTE && points > 0)
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
	if (dexterity < MAX_ATTRIBUTE && points > 0)
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
	if (agility < MAX_ATTRIBUTE && points > 0)
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
	if (wisdom < MAX_ATTRIBUTE && points > 0)
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
	if (inteligence < MAX_ATTRIBUTE && points > 0)
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
	if (charisma < MAX_ATTRIBUTE && points > 0)
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
	points += strength - min_strength + agility - min_agility + dexterity - min_dexterity + wisdom - min_wisdom + inteligence - min_inteligence + charisma - min_charisma;
	strength = min_strength;
	agility = min_agility;
	dexterity = min_dexterity;
	wisdom = min_wisdom;
	inteligence = min_inteligence;
	charisma = min_charisma;
}

int Character::getHealth()
{
	return health;
}

void Character::incHealth(int value)
{
	health += value;
	if(health > 100)
		health = 100;
}

void Character::decHealth(int value)
{
	if (head != nullptr)
		value -= ((Wearable*)head)->getArmor();
	if (chest != nullptr)
		value -= ((Wearable*)chest)->getArmor();
	if (hands != nullptr)
		value -= ((Wearable*)hands)->getArmor();
	if (legs != nullptr)
		value -= ((Wearable*)legs)->getArmor();
	if (feet != nullptr)
		value -= ((Wearable*)feet)->getArmor();

	if (value < 0)
		value = 0;
	health -= value;
	if(health < 0)
		health = 0;
}

int Character::getGold()
{
	return gold;
}

void Character::incGold(int value)
{
	gold += value;
}

void Character::decGold(int value)
{
	gold += value;
}

Itemz * Character::getInventoryItem(int number)
{
	int len = backpack->getLength();
	if((len > number) && (number >= 0))
	{
		return backpack->getItem(number);
	}
	else
	{
		return new Itemz("");
	}
}

char* Character::getInventoryItemName(int number)
{

	int len = backpack->getLength();
	std::cout << len << ">" << number << std::endl;
	if(len > number)
	{
		return _strdup(backpack->getItem(number)->getName().c_str());
	}
	else
	{
		return "-";
	}
}

int  Character::getInventorySize()
{
	return backpack->getLength();
}

void Character::wearHead(Wearable * item)
{
	head = item;
}

void Character::wearChest(Wearable * item)
{
	chest = item;
}

void Character::wearLegs(Wearable * item)
{
	legs = item;
}

void Character::wearFeet(Wearable * item)
{
	feet = item;
}

void Character::wearHands(Wearable * item)
{
	hands = item;
}

void Character::wearWeapon(Weapon * item)
{
	weapon = item;
}

void Character::addItem(Itemz * item)
{
	backpack->putItem(item);
}

std::string Character::eqToString()
{
	std::string result = "";
	result += "{your_equipment}:";
	if(head != nullptr)
		result += "\n {head}: " + head->getName();
	if(chest != nullptr)
		result += "\n {chest}: " + chest->getName();
	if(hands != nullptr)
		result += "\n {hands}: " + hands->getName();
	if(legs != nullptr)
		result += "\n {legs}: " + legs->getName();
	if(feet != nullptr)
		result += "\n {feet}: " + feet->getName();
	if(weapon != nullptr)
		result += "\n {weapon}: " + weapon->getName();
	return result;
}

std::string Character::getWeaponName()
{
	if (weapon != nullptr)
		return weapon->getName();
	else
		return "{fists}";
}

void Character::throwItem(Itemz * item)
{
	backpack->throwItem(item);
	if(weapon == item)
	{
		weapon = nullptr;
	}
	else if(head == item)
	{
		head = nullptr;
	}
	else if(chest == item)
	{
		chest = nullptr;
	}
	else if(hands == item)
	{
		hands = nullptr;
	}
	else if(legs == item)
	{
		legs = nullptr;
	}
	else if(feet == item)
	{
		feet = nullptr;
	}
}

int Character::getAttack()
{
	srand(time(NULL));
	int s = this->strength;

	if (weapon != nullptr)
	{
		int min = ((Weapon*)weapon)->getMinDamage();
		int max = ((Weapon*)weapon)->getMaxDamage();
		s += rand()%(max-min)+min;
	}
	return s;
}