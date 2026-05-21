#ifndef WARRIOR_H_
#define WARRIOR_H_

#include <string>
#include "Player.h"

class Monster;

class Warrior : public Player 
{
public:
	Warrior(std::string name, int hp, int mp, int power, int defense)
		: Player(name, hp + 30, mp, power, defense) 
	{
		this->job = "Warrior";
	};

	void attack(Monster* monster);

};

#endif