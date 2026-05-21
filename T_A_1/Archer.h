#ifndef ARCHER_H_
#define ARCHER_H_

#include <string>
#include "Player.h"

class Monster;

class Archer : public Player
{
public:
	Archer(std::string name, int hp, int mp, int power, int defense)
		: Player(name, hp, mp, power + 30, defense) 
	{
		this->job = "Archer";
	};

	void attack(Monster* monster) override;

};

#endif