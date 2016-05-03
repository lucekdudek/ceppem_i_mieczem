//
// Created by Aschali on 02.05.2016.
//

#include "Char.h"

Char::Char(int basic): strength(basic), dexterity(basic), agility(basic), wisdom(basic), inteligence(basic), charisma(basic)
{

}

int Char::getStrength()
{
    return strength;
}

int Char::getDexterity()
{
    return dexterity;
}

int Char::getAgility()
{
    return agility;
}

int Char::getWisdom()
{
    return wisdom;
}

int Char::getInteligence()
{
    return inteligence;
}

int Char::getCharisma()
{
    return charisma;
}

void Char::setStrength(int value)
{
    strength = value;
}

void Char::setDexterity(int value)
{
    dexterity = value;
}

void Char::setAgility(int value)
{
    agility = value;
}

void Char::setWisdom(int value)
{
    wisdom = value;
}

void Char::setInteligence(int value)
{
    inteligence = value;
}

void Char::setCharisma(int value)
{
    charisma = value;
}

void Char::decStrength()
{
    if(strength >1)
        strength --;
}

void Char::incStrength()
{
    if(strength <10)
        strength ++;
}

void Char::decDexterity()
{
    if(dexterity >1)
        dexterity --;
}

void Char::incDexterity()
{
    if(dexterity <10)
        dexterity ++;
}

void Char::decAgility()
{
    if(agility >1)
        agility --;
}

void Char::incAgility()
{
    if(agility <10)
        agility ++;
}

void Char::decWisdom()
{
    if(wisdom >1)
        wisdom --;
}

void Char::incWisdom()
{
    if(wisdom <10)
        wisdom ++;
}

void Char::decInteligence()
{
    if(inteligence >1)
        inteligence --;
}

void Char::incInteligence()
{
    if(inteligence <10)
        inteligence ++;
}

void Char::decCharisma()
{
    if(charisma >1)
        charisma --;
}

void Char::incCharisma()
{
    if(charisma <10)
        charisma ++;
}
























