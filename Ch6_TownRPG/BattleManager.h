#pragma once

#include "GameModel.h"

class BattleManager : public Combat
{
	// BattleManager battlemanager(player, monster); battleManaget.Battle();
	Player& player;
	Monster& monster;

	// ü���� 0���� ũ�� �ݺ��ϱ�	-> while Ż�������� ���� �ۼ��ϱ�
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

		std::cout << "������ ����Ǿ����ϴ�." << std::endl;
	}
	
};