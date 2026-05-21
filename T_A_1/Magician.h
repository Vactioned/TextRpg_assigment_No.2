#ifndef MAGICIAN_H_
#define MAGICIAN_H_

#include <string>
#include "Player.h"

class Monster;

class Magician : public Player
{
public:
	Magician(std::string name, int hp, int mp, int power, int defense)
		: Player(name, hp, mp + 30, power, defense) 
	{
		this->job = "Mage";
	};

	void attack(Monster* monster);

};

#endif