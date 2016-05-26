#include "veron.h"

veron::veron(string n)
{
	my_name = n;
	my_health=200;
	defense_mode=false;
	numWins = 0;
	numTies = 0;
	numLosses = 0;
}

string veron::getName() const
{
	return my_name;
}
string veron::getDescription() const
{
	return "The veron is angry.";
}
void veron::basicAttack(monster * enemy)
{
	defense_mode=true;
	enemy->doDamage(30);
}
string veron::basicName() const
{
	return "Falcon Punch";
}
void veron::defenseAttack(monster * enemy)
{
	defense_mode=true;
}
string veron::defenseName() const
{
	return "Titan Transformation";
}
void veron::specialAttack(monster * enemy)
{
	defense_mode=true;//Defend and attack
	enemy->doDamage(40);
}
string veron::specialName() const
{
	return "Burning Slash";
}
int veron::getHealth() const
{
	return my_health;
}
void veron::doDamage(int damage)
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
void veron::resetHealth()
{
	my_health=200;
}

int veron::getWins() const
{
	return numWins;
}
void veron::addWin()
{
	numWins++;
}

int veron::getTies() const
{
	return numTies;
}
void veron::addTie()
{
	numTies++;
}
int veron::getLosses() const
{
	return numLosses;
}
void veron::addLoss()
{
	numLosses++;
}


