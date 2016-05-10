#ifndef ITEMZ_H
#define ITEMZ_H

#include <string>

class Itemz
{
public:
	Itemz();
	~Itemz();

	int getId();
	std::string getName();
	int getGoldValue();

protected:
	int id;
	int goldValue;
	std::string name;
};

#endif // !ITEMZ_H