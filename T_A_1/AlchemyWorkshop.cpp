#include <format>
#include <iostream>
#include <algorithm> // find 함수 포함

#include "AlchemyWorkshop.h"


using namespace std;

AlchemyWorkshop Potionworkshop;

void AlchemyWorkshop::ShowAllRecp()
{
    std::cout << "\n";
	for (const auto& item : recp)
	{
		item.PrintInfo();
		std::cout << "\n";
	}
    std::cout << "\n";
}

void AlchemyWorkshop::SearchByName(string name)
{
    bool didFoundRecp = false;
    std::cout << "\n";
    for (const auto& item : recp)
    {
        if (item.name.find(name) != string::npos)
        {
            item.PrintInfo();
            cout << "\n";
            didFoundRecp = true;
        }
    }
    if (!didFoundRecp)
    {
        cout << format("Potion Not Found\n\n");
    }
    else
    {
        cout << "\n";
    }
}

void AlchemyWorkshop::SearchByIngredient(string ingredient)
{
    bool didFoundRecp = false;
    std::cout << "\n";
    for (const auto& item : recp)
    {
        if (item.ingredient1.find(ingredient) != string::npos || item.ingredient2.find(ingredient) != string::npos)
        {
            item.PrintInfo();
            cout << "\n";
            didFoundRecp = true;
        }
    }
    if (!didFoundRecp)
    {
        cout << format("Potion Not Found\n\n");
    }
    else
    {
        cout << "\n";
    }
}

void Workshopentrence(AlchemyWorkshop& Potionworkshop)
{
	bool Jobdone = false;
	int choice;
	cout << format("\n=== Potion Workshop===\n");
	while (!Jobdone)
	{
		cout << format("1. Show all recipes\n");
		cout << format("2. Search by potion name\n");
		cout << format("3. Search by ingredient\n");
		cout << format("4. Dispense Potion \n");
		cout << format("5. Return Potion\n");
		cout << format("6. Check Stock\n");
		cout << format("0. Go back\n");
		cout << format("Choose: ");
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 1:
		{
			Potionworkshop.ShowAllRecp();
			break;
		}
		case 2:
		{
			string searchname;
			cout << format("Search potion name: ");
			cin >> searchname;
			Potionworkshop.SearchByName(searchname);
			break;
		}
		case 3:
		{
			string searchingredient;
			cout << format("Search potion ingredient: ");
			cin >> searchingredient;
			Potionworkshop.SearchByIngredient(searchingredient);
			break;
		}
		case 4:
		{
			string searchname;
			cout << format("Potion name: ");

			getline(cin, searchname);
			Potionworkshop.DispensePotion(searchname);
			break;
		}
		case 5:
		{
			string searchname;
			cout << format("Potion name: ");

			getline(cin, searchname);
			Potionworkshop.ReturnPotion(searchname);
			break;
		}
		case 6:
		{
			string searchname;
			cout << format("Potion name: ");

			getline(cin, searchname);
			Potionworkshop.GetStock(searchname);
			break;
		}
		case 0:
			Jobdone = true;
			break;

		default:
			cout << format("\nWrong number. Please Select between 0 to 6\n");
		}

	}

}

void AlchemyWorkshop::DispensePotion(std::string name)
{
	if (potionStock_.find(name) == potionStock_.end())
	{
		cout << format("Invalid potion name.\n");
		return;
	}
	else
	{
		if (potionStock_[name] <= 0)
		{
			cout << format("\nDispense failed: out of stock!\n\n");
		}

		else
		{
			potionStock_[name] -= 1;
			cout << format("\nDispense {} (stock: {})\n\n", name, potionStock_[name]);
		}
	}
}

void AlchemyWorkshop::ReturnPotion(string name)
{

	if (potionStock_.find(name) == potionStock_.end())
	{
		cout << format("Invalid potion name.\n");
		return;
	}
	else 
	{
		if (potionStock_[name] >= 3)
		{
			cout << format("\nReturn failed: Item {} has Reached to Max Stock!(3)\n\n", name);
		}
		else
		{
			potionStock_[name] += 1;
			cout << format("\nReturn {} (stock: {})\n\n", name, potionStock_[name]);
		}
	}
}

void AlchemyWorkshop::GetStock(string name)
{
	if (potionStock_.find(name) == potionStock_.end())
	{
		cout << format("Invalid potion name.\n");
		return;
	}
	else
	{
		cout << format("\n Remaining Potion Stock: {}\n\n", potionStock_[name]);
	}
}