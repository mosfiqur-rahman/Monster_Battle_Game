#include "rat_style.h"

rat::rat(string n) {
	my_name = n;
	my_health = 120;
	basic_dmg = 8;
	sneaky_counter = false;
    numWins = 0;
    numTies = 0;
    numLoses = 0;
}

string rat::getName() const 
{
	return my_name;
	
	}
string rat::getDescription() const{
	return "I'm the shadow in the dark. I'm here but you cant see me. KIAAAAAAAAA!!!!!!!!";
}

void rat::basicAttack(monster * enemy){
	sneaky_counter = false;
	enemy->doDamage(basic_dmg);
}

string rat::basicName() const{
	return "Mighty Bite";
}
void rat::defenseAttack(monster * enemy) {
	sneaky_counter = true;
}
string rat::defenseName() const{
	return "Missed. Rat_style counter attacks";
}

void rat::specialAttack(monster * enemy){
	basic_dmg += 4;
}
string rat::specialName() const{
	return "Rat's teeth have got deeper in your flesh";
}
int rat::getHealth() const{
	return my_health;
}
void rat::doDamage(int damage){

	if (sneaky_counter)
	{
		//Damage is neglected
		
		// Evade and invrease dmg by 1
		basic_dmg++;
	}
	else
	{
		my_health = my_health - damage;
	}
}
void rat::resetHealth() {
	my_health = 120;
}

int rat::getWins() const {
    return numWins;
}

void rat::addWin() {
    numWins++;
}

int rat::getTies() const {
    return numTies;
}

void rat::addTie() {
    numTies++;
}

int rat::getLosses() const {
    return numLoses;
}

void rat::addLoss() {
    numLoses++;
}