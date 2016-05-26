#include "wraith.h"

wraith::wraith(string n)
{
    my_name = n;
    my_health = 150;
    defense_mode = false;
    numWins = 0;
    numTies = 0;
    numLosses = 0;
}

string wraith::getName() const
{
    return my_name;
}
string wraith::getDescription() const
{
    return "The wraith seems to glow dimly.";
}
void wraith::basicAttack(monster * enemy)
{
    defense_mode = false;//Can't defend and attack
    enemy->doDamage(10);
}
string wraith::basicName() const
{
    return "Scratch";
}
void wraith::defenseAttack(monster * enemy)
{
    defense_mode = true;
}
string wraith::defenseName() const
{
    return "Disincorporate";
}
void wraith::specialAttack(monster * enemy)
{
    defense_mode = false;//Can't defend and attack
    enemy->doDamage(35);
}
string wraith::specialName() const
{
    return "Hex";
}
int wraith::getHealth() const
{
    return my_health;
}
void wraith::doDamage(int damage)
{
    if(defense_mode)
    {
        //Defense mode cuts damage in half
        my_health = my_health - (damage / 4);
    }else
    {
        my_health = my_health - damage;
    }
}
void wraith::resetHealth()
{
    my_health = 150;
}

int wraith::getWins() const {
    return numWins;
}

void wraith::addWin() {
    numWins++;
}

int wraith::getTies() const {
    return numTies;
}

void wraith::addTie() {
    numTies++;
}

int wraith::getLosses() const {
    return numLosses;
}

void wraith::addLoss() {
    numLosses++;
}


