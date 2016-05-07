#ifndef ITEMZ_H
#define ITEMZ_H

#include <string>

class Itemz
{
public:
	Itemz();
	~Itemz();
protected:
	int id;
	int goldValue;
	std::string name;
};

#endif // !ITEMZ_H