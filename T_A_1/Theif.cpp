#include <format>
#include <iostream>
#include "Thief.h"
#include "Monster.h"

using namespace std;

void Thief::attack(Monster* monster)
{
	int damage = (this->power - monster->getdefense()) / 5;//데미지 세팅
	if (damage < 1) damage = 1;
	monster->sethp(monster->gethp() - (damage * 5));

	cout << format("\nStabs with Dagger!\n");
	cout << format("{} x 5 Damages to {}!\n", damage, monster->getname());
	cout << format("{}'s HP: {}/{}", monster->getname(), monster->gethp(), monster->getmaxhp());//체력 변경 출력

}