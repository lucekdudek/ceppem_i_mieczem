#ifndef ITEMZ_H
#define ITEMZ_H

#include <string>

class Itemz
{
public:
	Itemz(std::string name_original);
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
	std::string getItemOriginalName();

protected:
	int id;
	int goldValue;
	std::string name;
	std::string description;
	std::string name_original;
};

#endif // !ITEMZ_H