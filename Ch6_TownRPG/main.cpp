#include "GameModel.h"
#include "BattleManager.h"

/*
	GameModel에서 만든 기능 테스트
	BattleManager - Player, Monster
*/


int main()
{
	Player player("플레이어", 100, 10);
	Monster monster("몬스터", 80, 5);

	BattleManager battlemanager(player, monster);

	battlemanager.Battle();
	
	std::cout << "전투가 종료되었습니다." << std::endl;
}