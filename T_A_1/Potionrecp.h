#ifndef POTIONRECP_H_
#define POTIONRECP_H_

#include <iostream>
#include <string>
#include <format>

struct Potionrecp
{
	
	Potionrecp(std::string name, std::string ingredient1, std::string ingredient2)
		:name(name), ingredient1(ingredient1), ingredient2(ingredient2) {};

	void PrintInfo() const
	{
		std::cout << std::format("{}: {}, {}", name, ingredient1, ingredient2);
	}

	std::string name;
	std::string ingredient1;
	std::string ingredient2;

};

#endif