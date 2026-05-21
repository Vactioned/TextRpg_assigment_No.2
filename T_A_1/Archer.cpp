#include <format>
#include <iostream>

#include "Archer.h"
#include "Monster.h"


using namespace std;

void Archer::attack(Monster* monster)
{
	int damage = (this->power - monster->getdefense()) / 3;//데미지 세팅
	if (damage < 1) damage = 1;
	monster->sethp(monster->gethp() - (damage * 3));

	cout << format("\nShoots an Arrow!\n");
	cout << format("{} x 3 Damages to {}!\n", damage, monster->getname());
	cout << format("{}'s HP: {}/{}", monster->getname(), monster->gethp(), monster->getmaxhp());//체력 변경 출력

}