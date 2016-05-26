#include "dragon.h"

dragon::dragon(string n)
{
	my_name = n;
	my_health = 230;
	defense_mode = false;
    numWins = 0;
    numTies = 0;
    numLoses = 0;
}

string dragon::getName() const
{
	return my_name;
}

string dragon::getDescription() const
{
	return "The dragon is furious and will burn you to crisp";
}

void dragon::basicAttack(monster * enemy)
{
	defense_mode = false;//Can't defend and attack
	enemy->doDamage(35);
}

string dragon::basicName() const
{
	return "FireBlast";
}

void dragon::defenseAttack(monster * enemy)
{
	defense_mode = true;
}

string dragon::defenseName() const
{
	return "Wing Shield";
}

void dragon::specialAttack(monster * enemy)
{
	defense_mode = false;//Can't defend and attack
	enemy->doDamage(40);
}

string dragon::specialName() const
{
	return "FlameThrower";
}

int dragon::getHealth() const
{
	return my_health;
}

void dragon::doDamage(int damage)
{
	if (defense_mode)
	{
		//Defense mode cuts damage in half
		my_health = my_health - (damage / 2);
	}
	else
	{
		my_health = my_health - damage;
	}
}

void dragon::resetHealth()
{
	my_health = 230;
}

int dragon::getWins() const
{
	return numWins;
}

void dragon::addWin()
{
	numWins += 1;
}

int dragon::getTies() const
{
	return numTies;
}

void dragon::addTie()
{
	numTies += 1;
}

int dragon::getLosses() const
{
	return numLoses;
}

void dragon::addLoss()
{
	numLoses += 1;
}
