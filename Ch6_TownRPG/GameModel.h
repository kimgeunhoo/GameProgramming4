#pragma once

#include <iostream>

/*
	virtual Ű���带 ����ϸ� �ش� Ŭ������ ����ϴ� �ڽ� Ŭ������ �ʿ��ϴ�.
	Combat - Player, Monster
	override ����� ����Ͽ� Combat Ÿ���ӿ��� Player�� Comnbat�� Monster�� Combat ��� ����

	virtual �Լ�() = 0; ���� �����Լ�
	�ڽĿ��� �ش� �Լ��� override ���Ѷ�
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
		std::cout << "player�� " << damage << "�� ���ظ� �Ծ����ϴ�." << std::endl;
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
		std::cout << name <<"�� " << damage << "�� ���ظ� �Ծ����ϴ�." << std::endl;
	}

	int getHealth() override
	{
		return health;
	}


};


