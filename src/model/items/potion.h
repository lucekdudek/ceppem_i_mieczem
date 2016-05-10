#ifndef POTION_H
#define POTION_H
#include "itemz.h"
class Potion: public Itemz
{
public:
	Potion(int id, std::string name, int value, int healing, int stack);
	~Potion();
private:
	int healing;
	int stack;

	int use();

	void setId(int value);
	void setName(std::string value);
	void setGoldValue(int value);
};

#endif