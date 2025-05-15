#include "ConsoleUtility.h"
#include <iostream>
#include <conio.h>	// _getch
#include "Pokeball.h"
#include <array>	// std::array<typename T, int N>

void Example ()
{
	while (true) {
		int random = ConsoleUtil::GetRandomInt(100);
		std::cout << random << std::endl;
		Sleep(100);
	}

	int x = ConsoleUtil::GetRandomInt(10);
	int y = ConsoleUtil::GetRandomInt(10);
	ConsoleUtil::GotoXY(x, y);
	std::cout << "���� ��ǥ ����" << std::endl;
}

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ENTER 13

template<int N>
void Display(int index)
{
	for (int i = 0; i < N; i++)
	{
		if (i == index)
		{
			std::cout << "�� ";
		}
		else {
			std::cout << "�� ";
		}
	}
	
}
template<int N>
void Display2D(int index)
{
	int height = index / N;	// ����
	int width = index % N;	// ����


	for (int y = 0; y < N; y++)
	{
		for (int i = 0; i < N; i++)
		{
			if (i == width && y == height)
			{
				std::cout << "�� ";
			}
			else {
				std::cout << "�� ";
			}
		}
		std::cout << std::endl;
	}

}


/*
	std::array (���� �迭) Fixed size Array
	- Ư¡ : ũ�Ⱑ �����Ǿ� �ְ�, ��Ģ�� ��Ȯ�� ǥ���� �� �ִ�.
	- �ǹ� : ũ�Ⱑ ������ �� �ִ� �迭�� ����� ���� ������?	vector(���� �迭)
*/

int main() 
{
	int selectedIndex = 0;
	char input;
	// Ű���� �����¿� �Է��� �޾Ƽ� �������� �����ϴ� �׸� ���

	// ���ϸ� �����͸� ����

	// PokeMon  (�� Ÿ��)			: ������ ����, ũ�Ⱑ ���� ���. �� ��ü�� ���¸� ǥ���� ��.
	// PokeMon* (���� Ÿ��, �ּҰ�) : ���縦 ���ϰ� �����͸� �����´�.

	// ���� ������ ���� ũ�Ⱑ ũ��. PokeMon*
	// ���� �� ������ ����, ���°� �����ϱ� ������ ������ ǥ��
	ConsoleUtil::setCursorVisible(false);

	std::array<PokeMon*, 36> pokeballs;

	PokeMon defaultMonster(0, "");

	pokeballs.fill(&defaultMonster);

	pokeballs[0] = new PokeMon(1, "�̻��ؾ�");
	pokeballs[1] = new PokeMon(2, "�̻���Ǯ");
	pokeballs[2] = new PokeMon(3, "�̻��ز�");
	pokeballs[3] = new PokeMon(4, "���α�");


	while (true)
	{
		
		const int size = 6;
		int sizePow = size * size;

		

		ConsoleUtil::GotoXY(0,0);
		Display2D<size>(selectedIndex);			// ���� ������ �������� �����ִ� Display �Լ� �����

		if (_kbhit) 
		{
			input = _getch();
			if (input == LEFT)
			{
				//std::cout << "���� ȭ��Ű�� �Է�" << endl; �۵��ȴ�
				selectedIndex = (selectedIndex - 1 + sizePow) % sizePow;	// 0 ~ 5  -1

			}
			else if (input == RIGHT)
			{
				selectedIndex = (selectedIndex + 1) % sizePow;	// 0 ~ 5  -1
			}
			else if (input == UP)
			{
				selectedIndex = (selectedIndex - size + sizePow) % sizePow;
			}
			else if (input == DOWN)
			{
				selectedIndex = (selectedIndex + size) % sizePow;
			}
			else if (input == ENTER)
			{
				break;
			}
			system("cls"); // ȭ�� �����
		}

		
		//std::cout << selectedIndex << std::endl;


		ConsoleUtil::GotoXY(31, 0);
		std::cout << "���� UI";
		ConsoleUtil::GotoXY(31, 1);
		std::cout << "NO."<< pokeballs[selectedIndex]->get_number() << pokeballs[selectedIndex]->get_name() << std::endl;


		
	}
	//selectedIndex;

	std::cout << pokeballs[selectedIndex]->get_name() << std::endl;
	
}