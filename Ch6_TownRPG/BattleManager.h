#pragma once

#include "GameModel.h"

class BattleManager : public Combat
{
	// BattleManager battlemanager(player, monster); battleManaget.Battle();
	Player& player;
	Monster& monster;

	// 체력이 0보다 크면 반복하기	-> while 탈출조건을 먼저 작성하기
public:
	BattleManager(Player& player, Monster& monster) : player(player),  monster(monster) {}

	void Battle(Player& player, Monster& monster)
	{
		while (player.getHealth() > 0 && monster.getHealth() > 0)
		{
			player.attack(monster);
			if (monster.getHealth() > 0)
			{
				monster.attack(player);
			}
		}

		std::cout << "전투가 종료되었습니다." << std::endl;
	}
	
};