//
// Created by Aschali on 02.05.2016.
//

#ifndef CEPEM_I_MIECZEM_CHAR_H
#define CEPEM_I_MIECZEM_CHAR_H


class Char
{
public:
    inline int getStrenght();
    inline int getDexterity();
    inline int getAgility();
    inline int getWisdom();
    inline int getInteligence();
    inline int getCharisma();
    inline void setStrenght(int value);
    inline void setDexterity(int value);
    inline void setAgility(int value);
    inline void setWisdom(int value);
    inline void  setInteligence(int value);
    inline void setCharisma(int value);
private:
    int strenght;
    int dexterity;
    int agility;
    int wisdom;
    int inteligence;
    int charisma;
};


#endif //CEPEM_I_MIECZEM_CHAR_H
