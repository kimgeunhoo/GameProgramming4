/*
	�����͸� �����ϴ� Ŭ����	
	T value, pointer
*/
#include "CustomVector.h"
#include "RandomEncount.h"
#include <conio.h>

int main() {
	//test1();
	//test2();

	Player player;

	while (true)
	{
		Battle(player);
		player.display();
		std::cout << "Ű�� �Է��ϸ� ���� ������ ����˴ϴ�. " << std::endl;
		_getch();
	}
	
}
