#include "omni.h"

omni::omni(string n) {
	my_name = n;
	my_health = 200;
	basic_dmg = 15;
	divine_shield = false;
    numWins = 0;
    numTies = 0;
    numLoses = 0;
}

string omni::getName() const
{
	return my_name;

}
string omni::getDescription() const{
	return "I'm omniknight , the paladin sent by GOD ";
}

void omni::basicAttack(monster * enemy){
	divine_shield = false;
	enemy->doDamage(basic_dmg);
}

string omni::basicName() const{
	return "Hammer Hit";
}
void omni::defenseAttack(monster * enemy) {
	divine_shield = true;
}
string omni::defenseName() const{
	return "Divine shield on";
}

void omni::specialAttack(monster * enemy){
	my_health += 8;
}
string omni::specialName() const{
	return "Hand of life";
}
int omni::getHealth() const{
	return my_health;
}
void omni::doDamage(int damage){

	if (divine_shield)
	{
		my_health = my_health - (damage * 0.2);
	}
	else
	{
		my_health = my_health - damage;
	}
}
void omni::resetHealth() {
	my_health = 200;
}

int omni::getWins() const {
    return numWins;
}

void omni::addWin() {
    numWins++;
}

int omni::getTies() const {
    return numTies;
}

void omni::addTie() {
    numTies++;
}

int omni::getLosses() const {
    return numLoses;
}

void omni::addLoss() {
    numLoses++;
}