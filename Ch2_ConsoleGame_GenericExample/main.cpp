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
	std::cout << "랜덤 좌표 생성" << std::endl;
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
			std::cout << "▣ ";
		}
		else {
			std::cout << "□ ";
		}
	}
	
}
template<int N>
void Display2D(int index)
{
	int height = index / N;	// 세로
	int width = index % N;	// 가로


	for (int y = 0; y < N; y++)
	{
		for (int i = 0; i < N; i++)
		{
			if (i == width && y == height)
			{
				std::cout << "▣ ";
			}
			else {
				std::cout << "□ ";
			}
		}
		std::cout << std::endl;
	}

}


/*
	std::array (고정 배열) Fixed size Array
	- 특징 : 크기가 고정되어 있고, 규칙을 명확히 표현할 수 있다.
	- 의문 : 크기가 변경할 수 있는 배열로 만들면 되지 않을까?	vector(가변 배열)
*/

int main() 
{
	int selectedIndex = 0;
	char input;
	// 키보드 상하좌우 입력을 받아서 아이템을 선택하는 그림 출력

	// 포켓몬 데이터를 세팅

	// PokeMon  (값 타입)			: 데이터 복사, 크기가 작은 경우. 값 자체가 상태를 표현할 때.
	// PokeMon* (참조 타입, 주소값) : 복사를 안하고 데이터를 가져온다.

	// 몬스터 종류가 많고 크기가 크다. PokeMon*
	// 몬스터 볼 갯수가 적고, 상태가 존재하기 때문에 값으로 표현
	ConsoleUtil::setCursorVisible(false);

	std::array<PokeMon*, 36> pokeballs;

	PokeMon defaultMonster(0, "");

	pokeballs.fill(&defaultMonster);

	pokeballs[0] = new PokeMon(1, "이상해씨");
	pokeballs[1] = new PokeMon(2, "이상해풀");
	pokeballs[2] = new PokeMon(3, "이상해꽃");
	pokeballs[3] = new PokeMon(4, "꼬부기");


	while (true)
	{
		
		const int size = 6;
		int sizePow = size * size;

		

		ConsoleUtil::GotoXY(0,0);
		Display2D<size>(selectedIndex);			// 현재 선택한 아이템을 보여주는 Display 함수 만든다

		if (_kbhit) 
		{
			input = _getch();
			if (input == LEFT)
			{
				//std::cout << "왼쪽 화살키를 입력" << endl; 작동된다
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
			system("cls"); // 화면 지우기
		}

		
		//std::cout << selectedIndex << std::endl;


		ConsoleUtil::GotoXY(31, 0);
		std::cout << "몬스터 UI";
		ConsoleUtil::GotoXY(31, 1);
		std::cout << "NO."<< pokeballs[selectedIndex]->get_number() << pokeballs[selectedIndex]->get_name() << std::endl;


		
	}
	//selectedIndex;

	std::cout << pokeballs[selectedIndex]->get_name() << std::endl;
	
}