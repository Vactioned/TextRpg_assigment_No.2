#ifndef ITEM_H_
#define ITEM_H_

#include <iostream>
#include <string>
#include <format>

struct Item
{

	Item(std::string name, int price, bool usable = false)
		:name(name), price(price), usable(usable) {};

	Item() : name(""), price(0), usable(false) {};

	std::string name;
	int price;
	bool usable;
	void PrintInfo() const
	{
		std::cout << std::format("{} ({}G)", name, price);
	}


};



//벡터에서 찾아야돼, 그리고 사용해야돼, 근데 그게 객체 대상이고, 객체가 안만들어져 있어. 그럼 애초에 벡터 내부에서 찾는다는 행위 자체가 불가능하지 않느냐?

#endif