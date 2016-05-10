#include "enemy.h"

Enemy::Enemy(std::string name)
{
	this->name = name;
	strength = 4;
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
