#ifndef _veron_
#define _veron_

#include <string>
#include "monster.h"

using namespace std;

//This is a Veron.
//It is very dangerous.

class veron : public monster
{
	private:
		string my_name;
		int my_health;
		bool defense_mode;
		int numWins;
		int numTies;
		int numLosses;
	public:
		veron(string n="No Name");
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
		
		int getWins() const;
		void addWin();
	
		int getTies() const;
		void addTie();

		int getLosses() const;
		void addLoss();
};

#endif
