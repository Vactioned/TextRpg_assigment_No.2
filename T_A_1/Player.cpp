#include <format>
#include <iostream>

#include "Player.h"
#include "GameUI.h"

using namespace std;

void Player::printPlayerStatus() 
{

		cout << format("\n{}\n", SEPARATOR);
		cout << format("  {}'s Stat\n", name);
		cout << format("{}\n", SEPARATOR);
		cout << format("Name: {}    Job: {}    Level: {}    Exp: {}/{}\n", name, job, level, exp, maxexp);
		cout << format("HP: {}/{}    MP: {}/{}    Attack: {}    Defense: {}\n", hp, maxhp, mp, maxmp, power, defense);
		cout << format("{}\n", SEPARATOR);

}

void Player::gainExp(int amount)
{
	exp += amount;
	cout << format("\n+{}EXP (EXP: {}/{})\n", amount, exp, maxexp);
	int upamount = 0;
	while (exp >= maxexp)
	{
		exp -= maxexp;
		++level;
		maxexp += 50;
		++upamount;
		maxhp += 10;
		maxmp += 10;
		power += 5;
		defense += 5;
		hp = maxhp;
		mp = maxmp;
	}

	if (upamount > 0)
	{
		cout << format("\nLevel Up! Lv.{} -> Lv.{}\n", level - upamount,level);
		cout << format("\nEXP: {}/{}\n", exp, maxexp);
		cout << format("\n Max HP +{}, Max MP +{}, Atk +{}, Def +{}\n", 10 * upamount, 10 * upamount, 5 * upamount, 5 * upamount);
		cout << format("\nHP and MP Fully Healed!\n");
		upamount = 0;
	}
}