#ifndef POTION_H
#define POTION_H
#include "itemz.h"
class Potion: public Itemz
{
public:
	Potion(int id, std::string name, std::string name_original, std::string description, int value, int healing, int stack);
	~Potion();

	std::string getType();
	std::string getSize();
	void setSize(int size);
	int use();
private:
	int healing;
	int stack;
};

#endif