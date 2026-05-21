#include <format>
#include <iostream>

#include "Magician.h"
#include "Monster.h"

using namespace std;

void Magician::attack(Monster* monster)
{
	int damage = this->power - monster->getdefense();//데미지 세팅
	if (damage < 1) damage = 1;
	monster->sethp(monster->gethp() - damage);

	cout << format("\nThrows a Fireball!\n");
	cout << format("{} Damages to {}!\n", damage, monster->getname());
	cout << format("{}'s HP: {}/{}", monster->getname(), monster->gethp(), monster->getmaxhp());//체력 변경 출력

}