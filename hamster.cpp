#include "hamster.h"

hamster::hamster(string n)
{
	my_name = n;
	my_health=20;
	defense_mode=false;
}

string hamster::getName() const
{
	return my_name;
}
string hamster::getDescription() const
{
	return "The hamster is both fluffy and friendly.";
}
void hamster::basicAttack(monster * enemy)
{
	defense_mode=false;//Can't defend and attack
	enemy->doDamage(2);
}
string hamster::basicName() const
{
	return "Bite";
}
void hamster::defenseAttack(monster * enemy)
{
	defense_mode=true;
}
string hamster::defenseName() const
{
	return "Hide";
}
void hamster::specialAttack(monster * enemy)
{
	defense_mode=false;//Can't defend and attack
	enemy->doDamage(3);
}
string hamster::specialName() const
{
	return "Ravenous Fury";
}
int hamster::getHealth() const
{
	return my_health;
}
void hamster::doDamage(int damage)
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
void hamster::resetHealth()
{
	my_health=20;
}