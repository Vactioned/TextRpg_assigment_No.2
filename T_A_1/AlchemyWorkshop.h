#ifndef ALCHEMYWORKSHOP_H_
#define ALCHEMYWORKSHOP_H_

#include <iostream>
#include <string>
#include <format>
#include <vector>
#include <map>

#include "Potionrecp.h"

class AlchemyWorkshop
{
private:

	std::vector<Potionrecp> recp;
	std::map<std::string, int> potionStock_;

public:

	AlchemyWorkshop()
	{
		recp.push_back(Potionrecp("HP Potion", "Herb", "Clear Water"));
		recp.push_back(Potionrecp("MP Potion", "Mana Stone Powder", "Clear Water"));
		recp.push_back(Potionrecp("Power Powder", "Ogre Tendon", "Catalyst Dust"));
		recp.push_back(Potionrecp("Defense Powder", "Golem Stone Shard", "Catalyst Dust"));
		potionStock_["HP Potion"] = 3;
		potionStock_["MP Potion"] = 3;
		potionStock_["Power Powder"] = 3;
		potionStock_["Defense Powder"] = 3;
		potionStock_["Empty Bottle"] = 0;	
	}

	void ShowAllRecp();

	void SearchByName(std::string name);

	void SearchByIngredient(std::string ingredient);

	void DispensePotion(std::string name);

	void ReturnPotion(std::string name);

	void GetStock(std::string name);

};

extern AlchemyWorkshop Potionworkshop;

void Workshopentrence(AlchemyWorkshop& Potionworkshop);

#endif