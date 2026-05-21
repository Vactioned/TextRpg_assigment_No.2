#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>

class Monster;

class Player
{
public:

	//이하 생성자
	Player(std::string name, int maxhp, int maxmp, int power, int defense)
		: name(name), maxhp(maxhp), maxmp(maxmp), power(power), defense(defense)
	{
		hp = maxhp; mp = maxmp;
	}

	//이하 가상 소멸자
	virtual ~Player() {};

	//이하 순수 가상함수
	virtual void attack(Monster* monster) = 0;

	//이하 멤버함수
	void gainExp(int amount);

	//이하 setter
	void setname(std::string name)
	{
		this->name = name;
	}
	void setjob(std::string job)
	{
		this->job = job;
	}
	void setlevel(int level)
	{
		this->level = level;
	}
	void sethp(int hp)
	{
		this->hp = hp;
	}
	void setmaxhp(int maxhp)
	{
		this->maxhp = maxhp;
	}
	void setmp(int mp)
	{
		this->mp = mp;
	}
	void setmaxmp(int maxmp)
	{
		this->maxmp = maxmp;
	}
	void setpower(int power)
	{
		this->power = power;
	}
	void setdefense(int defense)
	{
		this->defense = defense;
	}
	void setexp(int exp)
	{
		this->exp = exp;
	}
	void setmaxexp(int maxexp)
	{
		this->maxexp = maxexp;
	}

	//이하 getter
	std::string getname() 
	{
		return name;
	}
	std::string getjob() 
	{
		return job;
	}
	int getlevel() 
	{
		return level;
	}
	int gethp() 
	{
		return hp;
	}
	int getmaxhp()
	{
		return maxhp;
	}
	int getmp() 
	{
		return mp;
	}
	int getmaxmp()
	{
		return maxmp;
	}
	int getpower() 
	{
		return power;
	}
	int getdefense() 
	{
		return defense;
	}
	int getexp()
	{
		return exp;
	}
	int getmaxexp()
	{
		return maxexp;
	}

//이하 멤버 함수
	void printPlayerStatus();

//이하 멤버 변수	
protected:
	std::string name;
	std::string job; 
	int level = 1;
	int hp;
	int maxhp;
	int mp;
	int maxmp;
	int power;
	int defense;
	int exp = 0;
	int maxexp = 100;

};
#endif