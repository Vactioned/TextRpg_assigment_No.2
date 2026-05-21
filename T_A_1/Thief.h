#ifndef THIEF_H_
#define THIEF_H_

#include <string>
#include "Player.h"

class Monster;

class Thief : public Player
{
public:
	Thief(std::string name, int hp, int mp, int power, int defense)
		: Player(name, hp, mp, power, defense + 30) 
	{
		this->job = "Rogue";
	};

	void attack(Monster* monster);

};

#endif