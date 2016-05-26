#include "minotaur.h"

minotaur::minotaur(string n)
{
    my_name = n;
    my_health = 220;
    defense_mode = false;
    numWins = 0;
    numTies = 0;
    numLosses = 0;
}

string minotaur::getName() const
{
    return my_name;
}
string minotaur::getDescription() const
{
    return "The minotaur is rearing his bull head.";
}
void minotaur::basicAttack(monster * enemy)
{
    defense_mode = false;//Can't defend and attack
    enemy->doDamage(15);
}
string minotaur::basicName() const
{
    return "Headbutt";
}
void minotaur::defenseAttack(monster * enemy)
{
    defense_mode = true;
}
string minotaur::defenseName() const
{
    return "Dodge";
}
void minotaur::specialAttack(monster * enemy)
{
    defense_mode = false;//Can't defend and attack
    enemy->doDamage(25);
}
string minotaur::specialName() const
{
    return "Horn Spear";
}
int minotaur::getHealth() const
{
    return my_health;
}
void minotaur::doDamage(int damage)
{
    if(defense_mode)
    {
        //Defense mode cuts damage in half
        my_health = my_health - (damage / 2);
    }else
    {
        my_health = my_health - damage;
    }
}
void minotaur::resetHealth()
{
    my_health = 220;
}

int minotaur::getWins() const {
    return numWins;
}

void minotaur::addWin() {
    numWins++;
}

int minotaur::getTies() const {
    return numTies;
}

void minotaur::addTie() {
    numTies++;
}

int minotaur::getLosses() const {
    return numLosses;
}

void minotaur::addLoss() {
    numLosses++;
}


