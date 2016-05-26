#ifndef _OMNI_
#define _OMNI_

#include <string>
#include "monster.h"

using namespace std;

// This is Omni. It has low hp , but sneaky . It has increased dps( with evry special attack) and survival chance , because of the couter attack.  

class omni : public monster
{
private:
	string my_name;
	int my_health;
	int basic_dmg;
	bool divine_shield;
    int numWins;
    int numTies;
    int numLoses;

public:
	omni(string n = "No Name");

	string getName() const;
	string getDescription() const;
	void basicAttack(monster * enemy);
	string basicName() const;
	void defenseAttack(monster * enemy);
	string defenseName() const;
	void specialAttack(monster * enemy);
	string specialName() const;
	int getHealth() const;
	void doDamage(int damage);
	void resetHealth();
    int getWins() const;
    void addWin();
    int getTies() const;
    void addTie();
    int getLosses() const;
    void addLoss();
};

#endif
