#ifndef MONSTER_H_
#define MONSTER_H_

#include <string>
#include "Player.h"
#include "Item.h"


class Monster
{
public:
	
	//이하 생성자
	Monster(std::string name, int maxhp, int power, int defense, std::string dropItemName, int dropItemPrice, int expRewaerd)
		: name(name), maxhp(maxhp), power(power), defense(defense), dropItemName(dropItemName), dropItemPrice(dropItemPrice), expRewaerd(expRewaerd), 
		dropItem(dropItemName, dropItemPrice) 
	{
		hp = maxhp;
	}


	//이하 setter
	void setname(std::string name)
	{
		this->name = name;
	}
	void sethp(int hp)
	{
		this->hp = hp;
	}
	void setmaxhp(int maxhp)
	{
		this->maxhp = maxhp;
	}
	void setpower(int power)
	{
		this->power = power;
	}
	void setdefense(int defense)
	{
		this->defense = defense;
	}
	void setdropItemName(std::string dropItemName)
	{
		this->dropItemName = dropItemName;
	}
	void setdropItemPrice(int dropItemPrice)
	{
		this->dropItemPrice = dropItemPrice;
	}
	void setexpRewaerd(int expRewaerd)
	{
		this->expRewaerd = expRewaerd;
	}

	//이하 getter
	std::string getname()
	{
		return name;
	}
	int gethp()
	{
		return hp;
	}
	int getmaxhp()
	{
		return maxhp;
	}
	int getpower()
	{
		return power;
	}
	int getdefense()
	{
		return defense;
	}
	std::string getdropItemName()
	{
		return dropItemName;
	}
	int getdropItemPrice()
	{
		return dropItemPrice;
	}
	int getexpRewaerd()
	{
		return expRewaerd;
	}

	//이하 멤버 함수
	void attack(Player* player);

	//이하 멤버 변수
	Item dropItem;

protected:

	std::string name;
	int maxhp;
	int hp;
	int power;
	int defense;
	std::string dropItemName;
	int dropItemPrice;
	int expRewaerd;

};
#endif