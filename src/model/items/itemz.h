#ifndef ITEMZ_H
#define ITEMZ_H

#include <string>

class Itemz
{
public:
	Itemz();
	~Itemz();

	virtual std::string getType();

	int getId();
	std::string getName();
	std::string Itemz::getDescription();
	int getGoldValue();

	void setId(int id);
	void setName(std::string name);
	void setDescription(std::string description);
	void setGoldValue(int value);

protected:
	int id;
	int goldValue;
	std::string name;
	std::string description;
};

#endif // !ITEMZ_H