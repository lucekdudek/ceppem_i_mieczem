//
// Created by Aschali on 02.05.2016.
//

#ifndef CEPEM_I_MIECZEM_CHAR_H
#define CEPEM_I_MIECZEM_CHAR_H


class Character
{
public:
    Character(int basic=4);
    int getStrength();
    int getDexterity();
    int getAgility();
    int getWisdom();
    int getInteligence();
    int getCharisma();
    inline void setStrength(int value);
    inline void setDexterity(int value);
    inline void setAgility(int value);
    inline void setWisdom(int value);
    inline void  setInteligence(int value);
    inline void setCharisma(int value);
    void decStrength();
    void incStrength();
    void decDexterity();
    void incDexterity();
    void decAgility();
    void incAgility();
    void decWisdom();
    void incWisdom();
    void decInteligence();
    void incInteligence();
    void decCharisma();
    void incCharisma();
private:
    int strength;
    int dexterity;
    int agility;
    int wisdom;
    int inteligence;
    int charisma;
};


#endif //CEPEM_I_MIECZEM_CHAR_H
