#include <iostream>
#include <string>
#include <format>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "PlayerClasses.h"
#include "System.h"
#include "Monster.h"
#include "Item.h"

#include "MyInventory.h"//test

using namespace std;

void setPotion(int count, int* p_HP_Potion, int* p_MP_Potion)
{
	* p_HP_Potion = count;
	* p_MP_Potion = count;
}
/*
void setPotion(int count, int a, int b) <- 매개변수만 넘김
{
	a(기존 HP_Potion의 값을 복사한 값) = count;
	b(기존 MP_Potion의 값을 복사한 값) = count;
} -> 결과 : a와 b값만 count값으로 변경될 뿐, 기존 변수의 값은 변하지 않음.

포인터 사용시
1. 인자에 들어간 변수의 주소값을 받음(int* p_HP_Potion)
2. 해당 변수의 주소값에 등록된 데이터 값을 변경함.(* p_HP_Potion = count)
 * 주의점 : p_HP_Potion = count(*빼먹기)를 사용시, 포인터의 주소값이 변경됨.
*/



int main(void)
{
	srand(time(0));

	bool isGameStart = false;

	cout << format("{}\n", SEPARATOR);
	cout << format("   [ Dungeon Escape Text RPG ]\n");
	cout << format("{}\n", SEPARATOR);


	string player_name;
	cout << format("Enter your hero's name: ");
	cin >> player_name;
	
	const int SIZE = 4;
	int stat[SIZE] = {0};
	// Player_stat [0] = hp, [1] = mp, [2] = atk, [3] = def

	while (true)
	{
		cout << format("\nHP and MP: ");
		cin >> stat[0] >> stat[1];

		if (stat[0] >= 50 && stat[1] >= 50)
		{
			break;
		}
		else
		{
			cout << format("\nPlease set HP and MP both over 50.");
		}
	}

	while (true)
	{
		cout << format("\nAttack and Defense: ");
		cin >> stat[2] >> stat[3];

		if (stat[2] >= 10 && stat[3] >= 10)
		{
			break;
		}
		else
		{
			cout << format("\nPlease set Attack and Defense both over 10.");
		}
	}
	
	printStatus(player_name, stat);

	int HP_Potion=0;
	int MP_Potion=0;

	setPotion(5, &HP_Potion, &MP_Potion);

	cout << format("\n* You received 5 HP Potions and 5 MP Potions.\n");
	for (int i = 0; i < 5; i++)
	{
		inventory.push_back(Item("HP Potion", 50, true));
		inventory.push_back(Item("MP Potion", 50, true));
	}

	printCharacterUpgrade(HP_Potion, MP_Potion);


	while (!isGameStart)
	{
		int choice;

		cout << format("Choose act: ");
		cin >> choice;


		switch (choice)
		{

		case 1:
			if (HP_Potion > 0)
			{
				--HP_Potion;
				cout << format("\n* HP increased by 20. (Remaing HP Potions: {})\n\n", HP_Potion);
				stat[0] += 20;
			}
			else
				cout << format("\nYou don't have HP Potion!\n\n");
			break;

		case 2:
			if (MP_Potion > 0)
			{
				--MP_Potion;
				cout << format("\n* MP increased by 20. (Remaing MP Potions: {})\n\n", MP_Potion);
				stat[1] += 20;
			}
			else
				cout << format("\nYou don't have MP Potion!\n\n");
			break;

		case 3:
			stat[2] = stat[2] * 2;
			cout << format("\n{}'s Attack is now {}\n\n", player_name, stat[2]);
			break;

		case 4:
			stat[3] = stat[3] * 2;
			cout << format("\n{}'s Defense is now {}\n\n", player_name, stat[3]);
			break;

		case 5:
			printStatus(player_name, stat);
			printCharacterUpgrade(HP_Potion, MP_Potion);
			break;

		case 0:
			isGameStart = true;
			cout << format("\nStarting the game!\n");
			break;

		default:
			cout << format("\nWrong act number. Please Choose number between 0 to 5\n\n");
		}


	}


	cout << format("\n< Job Selection >\n");
	cout << format("{}, Choose your job!\n", player_name);
	cout << format("1. Warrior   2. Mage   3. Rogue   4. Archer\n");

	Player* player = nullptr;

	while (true)
	{
		int jobselection;

		cout << format("Choose: ");
		cin >> jobselection;

		switch (jobselection)
		{

		case 1:
			player = new Warrior(player_name, stat[0], stat[1], stat[2], stat[3]);
			cout << format("\nYou became a Warrior! (HP + 30)");
			break;

		case 2:
			player = new Magician(player_name, stat[0], stat[1], stat[2], stat[3]);
			cout << format("\nYou became a Mage! (MP + 30)");
			break;

		case 3:
			player = new Thief(player_name, stat[0], stat[1], stat[2], stat[3]);
			cout << format("\nYou became a Rogue! (Defense + 30)");
			break;

		case 4:
			player = new Archer(player_name, stat[0], stat[1], stat[2], stat[3]);
			cout << format("\nYou became a Archer! (Attack + 30)");
			break;

		default:
			cout << format("\nWrong job number. Please Choose number between 1 to 4\n\n");
			continue;
		}

		break;
	}

	vector<Monster> monsters = 
	{
	Monster("Slime", 30, 20, 10, "Slime Jelly", 30, 30),
	Monster("Goblin", 50, 30, 15, "Goblin Ear", 50, 50)
	};

	player->printPlayerStatus();

	vector<Monster> dungeonRooms =
	{
		Monster("Slime", 30, 15, 5, "Slime Jelly", 30, 30),
		Monster("Goblin", 50, 25, 10, "Goblin Ear", 50, 50),
		Monster("Orc", 80, 35, 15, "Orc Heart", 80, 80)
	};

	Monster boss("Dragon", 200, 60, 20, "Dragon Scale", 500, 500);

	int clearedRooms = 0;

	bool isRunning = true;

	while (isRunning)
	{
		cout << format("\n=== Main Menu ===\n");
		cout << format("1. Enter Dungeon\n");
		cout << format("2. Check Inventory\n");
		cout << format("3. Potion Alchemy Workshop\n");
		cout << format("4. Player Status\n");
		cout << format("0. Quit\n");

		int menuselect;
		cout << format("Choose: ");
		cin >> menuselect;

		switch (menuselect)
		{
		case 1:
		{
			if (clearedRooms < 3)
			{
				battleStart(player, dungeonRooms[clearedRooms]);
				++clearedRooms;
			}

			else if(clearedRooms == 3)
			{
				battleStart(player, boss);

				if (isPlayerWin)
				{

					cout << format("You Win! Evil Dragon Defeted!\n");
					return 0;
				}
				break;

			}

			if (!isPlayerWin)
			{
				return 0;
			}
			break;
		}

		case 2:
			checkInventory();
			break;

		case 3:
			Workshopentrence(Potionworkshop);
			break;

		case 4:
			player->printPlayerStatus();
			break;

		case 0:
			isRunning = false;
			break;

		default:
			cout << format("\nWrong number. Please Select between 0 to 3\n");
		}
	}	

	MyInventory<Item> inv1(20);
	inv1.additem(Item("HP Potion", 50, true));
	inv1.additem(Item("MP Potion", 50, true));

	MyInventory<Item> inv2 = inv1; // 복사 생성자 호출
	inv2.printallitems(); // inv1과 동일하게 출력되어야 함

	inv2.removeitemlast(); // inv2에서만 제거
	inv1.printallitems(); // inv1은 그대로여야 함
	inv2.printallitems(); // inv2만 변경되어야 함

	delete player;
	return 0;
}