#include "enemy.h"
#include <iostream>

Enemy::Enemy(std::string name)
{
	this->name = name;
	int sum = 0;
	for (int i = 0; i < name.length(); i++)
	{
		sum += name[i];
	}
	sum = sum / name.length() / 70;
	std::cout << sum << std::endl;
	strength = 4 + sum;
	health = 100;
}

Enemy::~Enemy()
{
}

int Enemy::getStrength()
{
	return strength;
}

int Enemy::getHealth()
{
	return health;
}

void Enemy::incHealth(int value)
{
	health += value;
}

void Enemy::decHealth(int value)
{
	health -= value;
	if (health < 0)
	{
		health = 0;
	}
}
