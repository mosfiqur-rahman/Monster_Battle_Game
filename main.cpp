#include <iostream>
#include <string>
#include <stdlib.h> //This is where random numbers live
#include <time.h> //To set the random number generator
#include <vector>
#include <iomanip>
#include "hamster.h"
#include "minotaur.h"
#include "wraith.h"
#include "ebirah.h"
#include "veron.h"
#include "dragon.h"
#include "giant.h"
#include "omni.h"
#include "rat_style.h"
using namespace std;

monster* monster_battle(monster* m1, monster* m2);
void print_results(monster* attacker, monster* defender, string attack, int hchange);

int main()
{
	monster* m = new minotaur("Asterion");
    monster* w = new wraith("Nazgul");
    monster* e = new ebirah("Godzilla");
    monster* v = new veron("Gabara");
    monster* d = new dragon("Drogon");
    monster* g = new giant("Hodor");
    monster* o = new omni("Paladin");
    monster* r = new rat("Ursa");
    
    //Load monsters into vector
    vector<monster*> players;
    players.push_back(m);
    players.push_back(w);
    players.push_back(e);
    players.push_back(v);
    players.push_back(d);
    players.push_back(g);
    players.push_back(o);
    players.push_back(r);
    
    //Round Robbin tournament to determine bracket seeds
    for (int k = 0; k < players.size()-1; k++) {
        for (int j = k+1; j < players.size(); j++) {
            for (int n = 0; n < 3; n++) {
                monster* winner = monster_battle(players[k], players[j]);
                if (players[k] == winner) {
                    players[k]->addWin();
                    players[j]->addLoss();
                } else if (players[j] == winner) {
                    players[j]->addWin();
                    players[k]->addLoss();
                } else if (winner == NULL) {
                    players[k]->addTie();
                    players[j]->addTie();
                }
            }
        }
    }
    
    //Print Round Robin results
    cout << "Player         W   T   L" << endl;
    cout << "--------------------------" << endl;
    for (int k = 0; k < players.size(); k++) {
        cout << left << setw(13) << players[k]->getName()
        << setw(4) << players[k]->getWins()
        << setw(4) << players[k]->getTies()
        << setw(4) << players[k]->getLosses() << endl;
    }
    
    
    
}

//Monster Battle Happens below here
//---------------------------------------------------

//This function has two monsters fight
//it returns the winner
//or NULL on a tie
monster* monster_battle(monster* m1, monster* m2)
{
	//make sure both are at full health
	m1->resetHealth();
	m2->resetHealth();

	cout << "Starting Battle Between " << endl;
	cout << m1->getName() << ": " << m1->getDescription() << endl;
	cout << m2->getName() << ": " << m2->getDescription() << endl;
	//Every battle should be different, so we need to
	//start the random number generator somewhere "random".
	//The easiest way to do this is grab the current time in seconds
	//it is functionally a random starting point.
	srand(time(NULL));
	//Record start time
	//if 30 seconds pass then timeout
	int start_time = time(NULL);//I only case about nearest second
	bool timeout = false;
	
	//Whose turn is it currently
	monster* attacker=NULL;
	monster* defender=NULL;
	//Select Randomly
	if(rand()%2 == 0)
	{
		//m1 goes first
		attacker = m1;
		defender = m2;
	}else
	{
		//m2 goes first
		attacker = m2;
		defender = m1;
	}
	cout << attacker->getName() << " goes first. " << endl;
	//Loop until either 1 is unconscious or timeout
	while(m1->getHealth() > 0 && m2->getHealth() > 0 && !timeout)
	{
		//Determine what move the monster makes
		//Probabilities:
		//	60% chance of standard attack
		//	20% chance of defense move
		//	20% chance of special attack move

		//Pick a number between 1 and 100
		int move = rand() % 100 + 1;
		//It will be nice for output to record the damage done
		int before_health=defender->getHealth();
		
		if(move>=1 && move <= 60)
		{
			//Attack!
			attacker->basicAttack(defender);
			print_results(attacker,defender,
				attacker->basicName(),
				before_health-defender->getHealth()
				);
		}
		if(move>=61 && move <= 80)
		{
			//Defend!
			attacker->defenseAttack(defender);
			print_results(attacker,defender,
				attacker->defenseName(),
				before_health-defender->getHealth()
				);
		}
		if(move>=81 && move <= 100)
		{
			//Special attack
			attacker->specialAttack(defender);
			print_results(attacker,defender,
				attacker->specialName(),
				before_health-defender->getHealth()
				);
		}
		//Swap the attacker and defender
		monster* tmp = attacker;
		attacker=defender;
		defender=tmp;
		
		//check for a timeout
		if(time(NULL)-start_time > 30)
		{
			timeout=true;
		}
		cout << m1->getName() << " at " << m1->getHealth() << " health." << endl;
		cout << m2->getName() << " at " << m2->getHealth() << " health."<< endl;
	}
	if(m1->getHealth() < 1 && m2->getHealth() < 1)
	{
		cout << "Both Monsters are unconscious the match is a tie" << endl;
		return NULL;
	}
	if(m1->getHealth()<1)
	{
		cout << m2->getName() << " is victorious!" << endl;
		return m2;
	}
	if(m2->getHealth()<1)
	{
		cout << m1->getName() << " is victorious!" << endl;
		return m1;
	}
	if(timeout)
	{
		cout << "Battle is ended by timeout. It is a tie." << endl;
		return NULL;
	}
	cout << "A tie but not sure why??" << endl;
	return NULL;
}
void print_results(monster* attacker, monster* defender, string attack,int hchange)
{
	cout << attacker->getName() << " used " << attack;
	cout << " on " << defender->getName() << endl;
	cout << "The attack did " << hchange << " damage." << endl;
}
