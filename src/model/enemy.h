#pragma once
#include <string>
class Enemy
{
public:
	Enemy(std::string name);
	~Enemy();

	int getStrength();
	int getHealth();
	void incHealth(int value);
	void decHealth(int value);
private:
	std::string name;
	int strength;
	int health;
};

