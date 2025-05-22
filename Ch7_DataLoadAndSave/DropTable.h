#pragma once

#include <iostream>
#include <vector>
#include "ConsoleUtility.h"

/*
	1. DropItem 생성자 만들기
	2. Monster에 데이터를 받아올 수 있게 Private 필드 선언
	3. public 레이블에 생성자, vector의 DropTable을 추가하기
*/


struct DropItem
{
	int index;
	int exp;
	int money;
	std::string Item;
	// Item(코드, 이미지, 스탯)
	
	DropItem() = default;
	DropItem(int index, int exp, int money) : index(index), exp(exp), money(money) {}

};


class Monster
{
private:
	// 2
	int index;
	int exp;
	int money;
	std::vector<DropItem> drop;
	DropItem currentDropItem;
public:
	Monster(int exp, int money) : exp(exp), money(money)
	{
		// 3. 자료구조를 생성하여 만들기
		drop.emplace_back(1, 10, 100);
		drop.emplace_back(2, 20, 200);
		drop.emplace_back(3, 30, 300);
		drop.emplace_back(4, 40, 400);
		drop.emplace_back(5, 50, 500);

		// 내가 어떤 경험치 테이블을 선택했는가?
		SetDropItem();
	}

	void SetDropItem()
	{
		int index = ConsoleUtil::GetRandomInt(drop.size() - 1);	//index 0부터 시작한다.	size() - 1

		currentDropItem = drop[index];
	}

	void Drop()
	{
		std::cout << "획득한 경험치 : " << currentDropItem.exp << std::endl;
		std::cout << "획득한 돈 : " << currentDropItem.money << std::endl;
		std::cout << "획득한 아이템 : " << currentDropItem.Item << std::endl;
		// player.GetDropItem(); player의 exp를 증가시킨다. money 증가시킨다.
	}

};

