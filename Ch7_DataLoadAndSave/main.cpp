#include "GameModel.h"
#include "DropTable.h"
#include <conio.h>
#include "DataHandler.h"
/*
	����ġ ���̺� �����
	1���� - 100
	2���� - 100
	3���� - 100
	4���� - 150
	5���� - 150
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

	std::cout << "data�� level : " << data.level << " exp : " << data.exp << std::endl;


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