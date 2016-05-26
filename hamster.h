#ifndef _HAMSTER_
#define _HAMSTER_

#include <string>
#include "monster.h"

using namespace std;

//This is a hamster.
//It is a very weak monster.

class hamster : public monster
{
	private:
		string my_name;
		int my_health;
		bool defense_mode;
	public:
		hamster(string n="No Name");
		//redefine all the Methods of monster
		//Note: we can make more methods if we want, but
		//we need to redfine the methods of monster
		//because those are the ones that will be used in the game.
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
};

#endif