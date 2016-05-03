//
// Created by Aschali on 02.05.2016.
//

#include "character.h"

Character::Character(int basic): strength(basic), dexterity(basic), agility(basic), wisdom(basic), inteligence(basic), charisma(basic)
{

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
    if(strength >1)
        strength --;
}

void Character::incStrength()
{
    if(strength <10)
        strength ++;
}

void Character::decDexterity()
{
    if(dexterity >1)
        dexterity --;
}

void Character::incDexterity()
{
    if(dexterity <10)
        dexterity ++;
}

void Character::decAgility()
{
    if(agility >1)
        agility --;
}

void Character::incAgility()
{
    if(agility <10)
        agility ++;
}

void Character::decWisdom()
{
    if(wisdom >1)
        wisdom --;
}

void Character::incWisdom()
{
    if(wisdom <10)
        wisdom ++;
}

void Character::decInteligence()
{
    if(inteligence >1)
        inteligence --;
}

void Character::incInteligence()
{
    if(inteligence <10)
        inteligence ++;
}

void Character::decCharisma()
{
    if(charisma >1)
        charisma --;
}

void Character::incCharisma()
{
    if(charisma <10)
        charisma ++;
}
























