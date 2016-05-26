#include "ebirah.h"

ebirah::ebirah(string n)
{
	my_name = n;
	my_health=200;
	defense_mode=false;
    numWins = 0;
    numTies = 0;
    numLosses = 0;
}

string ebirah::getName() const
{
	return my_name;
}
string ebirah::getDescription() const
{
	return "The ebirah is ferocious.";
}
void ebirah::basicAttack(monster * enemy)
{
	defense_mode=true;
	enemy->doDamage(30);
}
string ebirah::basicName() const
{
	return "Ass Kick";
}
void ebirah::defenseAttack(monster * enemy)
{
	defense_mode=true;
}
string ebirah::defenseName() const
{
	return "Mind Control";
}
void ebirah::specialAttack(monster * enemy)
{
	defense_mode=true;
	enemy->doDamage(40);
}
string ebirah::specialName() const
{
	return "Fire";
}
int ebirah::getHealth() const
{
	return my_health;
}
void ebirah::doDamage(int damage)
{
	if(defense_mode)
	{
		//Defense mode cuts damage in half
		my_health=my_health-(damage/2);
	}else
	{
		my_health=my_health-damage;
	}
}
void ebirah::resetHealth()
{
	my_health=200;
}

int ebirah::getWins() const
{
	return numWins;
}
void ebirah::addWin()
{
	numWins++;
}

int ebirah::getTies() const
{
	return numTies;
}
void ebirah::addTie()
{
	numTies++;
}

int ebirah::getLosses() const
{
	return numLosses;
}
void ebirah::addLoss()
{
	numLosses++;
}



