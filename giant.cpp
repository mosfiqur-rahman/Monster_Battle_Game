#include "giant.h"

giant::giant(string n)
{
	my_name = n;
	my_health = 200;
	defense_mode = false;
    numWins = 0;
    numTies = 0;
    numLoses = 0;
}

string giant::getName() const
{
	return my_name;
}

string giant::getDescription() const
{
	return "The giant is huge and will crush you if you approach him";
}

void giant::basicAttack(monster * enemy)
{
	defense_mode = false;//Can't defend and attack
	enemy->doDamage(25);
}

string giant::basicName() const
{
	return "Skullcrush";
}

void giant::defenseAttack(monster * enemy)
{
	defense_mode = true;
}

string giant::defenseName() const
{
	return "Hand Shield";
}

void giant::specialAttack(monster * enemy)
{
	defense_mode = false;//Can't defend and attack
	enemy->doDamage(40);
}

string giant::specialName() const
{
	return "Body Slam";
}

int giant::getHealth() const
{
	return my_health;
}

void giant::doDamage(int damage)
{
	if (defense_mode)
	{
		//Defense mode cuts damage in half
		my_health = my_health - (damage / 4);
	}
	else
	{
		my_health = my_health - damage;
	}
}

void giant::resetHealth()
{
	my_health = 200;
}

int giant::getWins() const
{
	return numWins;
}

void giant::addWin()
{
	numWins += 1;
}

int giant::getTies() const
{
	return numTies;
}

void giant::addTie()
{
	numTies += 1;
}

int giant::getLosses() const
{
	return numLoses;
}

void giant::addLoss()
{
	numLoses += 1;
}
