#include "GameModel.h"
#include "BattleManager.h"

/*
	GameModel���� ���� ��� �׽�Ʈ
	BattleManager - Player, Monster
*/


int main()
{
	Player player(100, 10);
	Monster monster(80, 5);

	BattleManager battlemanager();

	battlemanager.Battle(player, monster);
	
	std::cout << "������ ����Ǿ����ϴ�." << std::endl;
}