#ifndef _BATTLE_MONSTER_
#define _BATTLE_MONSTER_

#include <string>

using namespace std;

//This class defines a generic monster
//It doesn't actually DO anything.
//It just gives you a template for how a monster works.

//We can make any number of monsters and have them fight
//they just all need to INHERIT from this one so that work the same way

//Since this class is not intended to be used
//none of the methods do anything
//The virtual command means we want the children to override these.
//The =0 part means these function's won't even work if you tried.
//This class is impossible to use by itself.

class monster
{
	public:
		monster();
		//Name the monster we are fighting
		//The description is printed at the start to give
		//additional details
		virtual string getName() const=0;
		virtual string getDescription() const=0;
	
		//Basic Attack Move
		//This will be the most common attack the monster makes
		//You are passed a pointer to the monster you are fighting
		virtual void basicAttack(monster * enemy)=0;
		//Print the name of the attack used
		virtual string basicName() const=0;
	
		//Defense Move
		//This move is used less frequently to
		//let the monster defend itself
		virtual void defenseAttack(monster * enemy)=0;
		//Print out the name of the attack used
		virtual string defenseName() const=0;
	
		//Special Attack
		//This move is used less frequently
		//but is the most powerful move the monster has
		virtual void specialAttack(monster * enemy)=0;
		virtual string specialName() const=0;
	
		//Health Management
		//A monster at health <= 0 is unconscious
		//This returns the current health level
		virtual int getHealth() const=0;
		//This function is used by the other monster to
		//either do damage (positive int) or heal (negative int)
		virtual void doDamage(int damage) =0;
		//Reset Health for next match
		virtual void resetHealth() = 0;
    
        //Track the number of wins, ties, and losses
        virtual int getWins() const =0;
        virtual void addWin() =0;
        virtual int getTies() const =0;
        virtual void addTie() =0;
        virtual int getLosses() const =0;
        virtual void addLoss() =0;
};



#endif