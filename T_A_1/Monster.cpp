#include <format>
#include <iostream>
#include "Monster.h"
#include "Player.h"

using namespace std;

void Monster::attack(Player* player)
{
	cout << format("\nMonster's attack!\n");
}