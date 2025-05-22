#pragma once

#include <iostream>

/*
	virtual 키워드를 사용하면 해당 클래스를 상속하는 자식 클래스가 필요하다.
	Combat - Player, Monster
	override 기능을 사용하여 Combat 타입임에도 Player의 Comnbat과 Monster의 Combat 사용 가능

	virtual 함수() = 0; 순수 가상함수
	자식에서 해당 함수를 override 시켜라
*/

class Combat
{
public:
	virtual ~Combat() = default;

	virtual void attack(Combat& target) = 0;
	virtual void takeDamage(int damage) = 0;
	virtual int getHealth() = 0;
};

class Player : public Combat
{
private:
	int health;
	int ATK;
	std::string name;
public:
	Player(std::string name, int health, int ATK) : name(name), health(health), ATK(ATK) {}

	void attack(Combat& target) override
	{
		target.takeDamage(ATK);
	}

	void takeDamage(int damage) override
	{
		health -= damage;
		std::cout << "player가 " << damage << "의 피해를 입었습니다." << std::endl;
	}

	int getHealth() override
	{
		return health;
	}

};

class Monster : public Combat
{
private:
	int health;
	int ATK;
	std::string name;
public:
	Monster(std::string name, int health, int ATK) : name(name), health(health), ATK(ATK) {}
	void attack(Combat& target) override
	{
		target.takeDamage(ATK);
	}

	void takeDamage(int damage) override
	{
		health -= damage;
		std::cout << name <<"가 " << damage << "의 피해를 입었습니다." << std::endl;
	}

	int getHealth() override
	{
		return health;
	}


};


