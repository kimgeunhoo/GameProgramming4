#include "GameModel.h"
#include "DropTable.h"
#include <conio.h>
#include "DataHandler.h"
/*
	경험치 테이블 만들기
	1레벨 - 100
	2레벨 - 100
	3레벨 - 100
	4레벨 - 150
	5레벨 - 150
*/

int main()
{
	Player player(0, 100); // exp 0 level 1 max 100 defaultValue
	Monster monster(0, 0);
	player.LoadData("player.txt");
	monster.Drop();

	Data data;
	//data.SaveData("data.txt");
	data.LoadData("data.txt");

	std::cout << "data의 level : " << data.level << " exp : " << data.exp << std::endl;


	_getch();

	int count = 0;

	while (true)
	{
		system("cls");
		player.GetExp(50);
		player.Show();
		_getch();
		count++;
		if (count >= 4)
		{
			break;
		}
	}

	player.SaveData("player.txt");
	
}