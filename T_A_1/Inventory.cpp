#include <vector>
#include <iostream>
#include <format>
#include <map>

#include "Inventory.h"

using namespace std;

vector<Item> inventory;

int inventoryMaximum = 20;

void getitem(Item& item)//전역 아이템 획득시 발생하는 함수. push_back 사용함.
{

	if (inventory.size() < inventoryMaximum)
	{
		cout << format("-> Got {}!\n", item.name);
		inventory.push_back(item);
	}

	else
	{
		cout << format("-> Inventory is Full! Inventory Automaticaly Expanded(x2)\n");
		inventoryMaximum *= 2;
		cout << format("-> Got {}!\n", item.name);
		inventory.push_back(item);
	}

}

void checkInventory()
{
	cout << format("\n[ Inventory ({}/{}) ]\n", inventory.size(), inventoryMaximum);

	int index = 1;
	for (const auto& item : inventory)
	{
		cout << format("{}. ", index);
		item.PrintInfo();
		cout << "\n";
		index++;
	}
}

map<string, int> getUsableItems()
{
	map<string, int> usableItems;
	for (const auto& item : inventory)
	{
		if (item.usable)
		{
			usableItems[item.name]++;
		}
	}
	return usableItems;
}

