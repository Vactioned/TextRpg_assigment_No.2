#include <format>
#include <iostream>
#include <string>

#include "GameUI.h"

using namespace std;


const string SEPARATOR = "====================================";
//자주 사용하는 구분줄(Separator)을 상수 string으로 저장하여 전역에서 사용할 예정


void printStatus(string player_name, int stat[])
{

	cout << format("{}\n", SEPARATOR);
	cout << format("  {}'s Stat\n", player_name);
	cout << format("{}\n", SEPARATOR);
	cout << format("HP: {}    MP: {}\n", stat[0], stat[1]);
	cout << format("Attack: {}     Defense: {}\n", stat[2], stat[3]);
	cout << format("{}\n", SEPARATOR);

}

void printCharacterUpgrade(int HP_Potion, int MP_Potion)
{
	cout << format("{}\n", SEPARATOR);
	cout << format("< Character Upgrade >\n");
	cout << format("1. HP UP x {}    2. MP UP x {}    3. Attack x 2\n", HP_Potion, MP_Potion);
	cout << format("4. Defense x 2  5. Show Stats  0. Start Game\n");
	cout << format("{}\n", SEPARATOR);
}

