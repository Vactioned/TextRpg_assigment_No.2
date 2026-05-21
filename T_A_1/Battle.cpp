#include <format>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#include "Battle.h"
#include "Inventory.h"


using namespace std;


bool isPlayerWin;

bool battleItemUse(vector<Item>& inventory, Player* player)
{
	map<string, int> usable = getUsableItems();

	auto it = usable.begin();
	int index = 1;
	int select;

	for (const auto& nameNamount : usable)
	{
		cout << format("{}. {} x {}\n", index, nameNamount.first, nameNamount.second);
		index++;
	}
	cout << format("Else. Cancel\n");
	cout << format("Choose: ");
	cin >> select;
	if (select <= 0 || select > (int)usable.size())
	{
	return false;
	}
	else
	{
		advance(it, select - 1);
		string selectedName = it -> first;
		if (selectedName == "HP Potion")
		{
			int Emshihp = player->gethp();
			player->sethp(min(player->gethp() + 50, player->getmaxhp()));
			cout << format("HP Potion Used. HP: {}/{} -> {}/{}\n", Emshihp, player->getmaxhp(), player->gethp(), player->getmaxhp());
		}
		else if (selectedName == "MP Potion")
		{
			int Emshimp = player->getmp();
			player->setmp(min(player->getmp() + 50, player->getmaxmp()));
			cout << format("MP Potion Used. MP: {}/{} -> {}/{}\n", Emshimp, player->getmaxmp(), player->getmp(), player->getmaxmp());
		}
		else
		{
			cout << format("Wrong name.\n");			
			return false;
		}

		for (auto invIt = inventory.begin(); invIt != inventory.end(); ++invIt)
		{
			if (invIt->name == selectedName)
			{
				inventory.erase(invIt);
				break;
			}
		}

		return true;
	}
}




void battleStart(Player* player, Monster& monster)
{

	cout << format("\n[ Battle Start! ] {}({}) vs {}", player->getname(), player->getjob(), monster.getname());

	monster.sethp(monster.getmaxhp());

	while (player->gethp() > 0 && monster.gethp() > 0)
	{
		int Choice;
		cout << format("\n\n--- Player Turn ---"); //플레이어 턴
		while (true)
		{
			cout << format("\n1. Attack");
			cout << format("\n2. Use Item");
			cout << format("\nChoose: ");
			cin >> Choice;
			switch (Choice)
			{

			case 1:
				player->attack(&monster);
				break;

			case 2:
				if (battleItemUse(inventory, player))
					break;// 아이템 사용 -> 턴 소비

				else
					continue;// 취소 -> 다시 선택지

			default:
				cout << format("Wrong Number. Please try again.");
				continue;
			}
			break;
		}

		if (monster.gethp() <= 0)//몬스터 죽음 판정
		{
			cout << format("(Dead)\n");
			break;
		}
		else
		{
			cout << format("\n");
		}
		cout << format("\n\n--- Monster Turn ---");//몬스터 턴
		int damage = monster.getpower() - player->getdefense();//데미지 세팅
		if (damage < 1) damage = 1;
		player->sethp(player->gethp() - damage);

		monster.attack(player);
		cout << format("{} Damages to {}!\n", damage, player->getname());
		cout << format("{}'s HP : {}/{}", player->getname(), player->gethp(), player->getmaxhp());//체력 변경 출력

		if (player->gethp() <= 0)
		{
			cout << format("(Dead)\n");
		}//플레이어 죽음 판정
		else
		{
			cout << format("\n");
		}
	}

	if (player->gethp() > monster.gethp()) //플레이어 체력이 몬스터보다 많을시
	{
		cout << format("\nVictory!\n");
		getitem(monster.dropItem);
		player->gainExp(monster.getexpRewaerd());
		isPlayerWin = true;
	}
	else
	{
		cout << format("\nYOU DIED...\n");
		isPlayerWin = false;
	}

}