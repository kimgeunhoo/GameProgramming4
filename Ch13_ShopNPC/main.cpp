/*
	목표 : (1) 콘솔 창에서 플레이어를 움직인다. 
	(2) 특정 위치에서 상점 NPC아 조우할 때 상점의 항목을 보여준다. 
	(3) 상점을 이용한다.

	Game Object: Player, NPC, Shop
	자료구조. Item 어떠한 컨테이너에 보관하여 사용할 것인가?
	File Input & output 메모장에 있는 데이터를 NPC에 전달하는 기능.
*/

// 클래스 구현 -> 테스트 -> 헤더 옮기기

#include <iostream>
#include <map>
#include <conio.h>
#include "ConsoleUtility.h"

#include <fstream> // ifsteram ofstream input output
#include <iomanip> // 입출력 조작 헤더
#include <utility>


const int total_width = 60;		// 전체
const int field1_width = 30;	// 이름 길이
const int field2_width = 15;	// 가격
const int field3_width = 15;	// 타입

#pragma region 상점 코드

class Item 
{
public:
	std::string name;
	int price;
	std::string type;
public:
	Item() = default;
	Item(std::string name, int price, std::string type) : name(name), price(price), type(type) {}

	// 원래는 보안상 이게 맞음
	// std::string Getname() { return name } const;
};

class Shop
{
private:
	std::map<int, Item> items;	// 자료구조 클래스를 보관한다.

public:	
	Shop()	// 데이터를 초기화한다.
	{
		// 3가지 insert 방식
		items.insert({ 0, Item("롱소드", 100, "무기") });
		items.insert(std::make_pair(1, Item("체력포션", 5, "소비")));
		std::pair<int, Item> p1(2, Item("나무방패", 50, "무기"));
		items.insert(p1);
		// 추가하거나 제거해서 종류별로 상점 만드는 것도 가능하다.
		items.insert({ 3, Item("대검", 200, "무기") });
		items.insert({ 4, Item("스피어", 150, "무기") });
		//items.insert({ 5, Item("엘릭서", 50, "소비") });
		//items.insert({ 6, Item("철갑옷", 200, "갑옷") });
		//items.insert({ 7, Item("가죽갑옷", 100, "갑옷") });
		//items.insert({ 8, Item("본쇼텔", 150, "무기") });
		//items.insert({ 8, Item("철강옥", 100, "강화재료") });
		//items.insert({ 9, Item("체인아머", 250, "갑옷") });
	}

	Shop(std::string filename)
	{
		LoadShopData(filename);
	}

	void LoadShopData(std::string filename)
	{
		std::ifstream in_file;
		in_file.open(filename);

		std::string name;
		int price;
		std::string type;

		if (!in_file)
		{
			std::cerr << "파일을 여는 데 실패했습니다." << std::endl;
			std::exit(1);
		}

		int index = 0;
		
		while (!in_file.eof()) // end of file (파일의 끝에 도달했을 떄)
		{
			in_file >> name >> price >> type;					// 파일에서 name, price type 읽기
			items.insert({index, Item(name, price, type) });	// map 자료구조에 저장
			index++;											// 다음 index 넘어가기
		}
		

		in_file.close();

	}

	void SaveShopData(std::string filename)
	{
		std::ofstream out_file;
		out_file.open(filename);

		std::string name;
		int price;
		std::string type;

		if (!out_file)
		{
			std::cerr << "파일을 여는 데 실패했습니다." << std::endl;
			std::exit(1);
		}

		for (int i = 0; i < items.size(); i++) // 인덱스 기반 접근이 가능한 자료구조여야만 한다. vector, map.
		{
			out_file << std::setw(field1_width) << std::left << items[i].name
				<< std::setw(field2_width) << std::right << items[i].price
				<< std::setw(field3_width) << std::right << items[i].type
				<< std::endl;
		}

		out_file.close();
	}


	// 데이터를 사용하여 기능을 구현한다.
	void ShowItems()
	{
		//std::string headersize = "012345678901234567890123456789012345678901234567890123456789";
		// 아이템의 머릿말
		//std::cout << headersize << std::endl;

		std::cout << std::setw(field1_width) << std::left << "이름"
			<< std::setw(field2_width) << std::right << "가격"
			<< std::setw(field3_width) << std::right << "타입"
			<< std::endl;
		// 라인 긋는 코드
		std::cout << std::setw(total_width)		// 길이 성정
			<< std::setfill('-')				// 공백 '-' 설정
			<< ""								// 길이 설정2
			<< std::endl;
		
		std::cout << std::setfill(' ');			// 라인 기존 설정으로
		// 아이템을 출력하라
		// const auto & elem : items 도 가능  // 인덱스 기반이 아니라면 이것을 사용
		for (int i = 0; i < items.size() - 1; i++) // 인덱스 기반 접근이 가능한 자료구조여야만 한다. vector, map.
		{
			std::cout << std::setw(field1_width) << std::left << items[i].name
				<< std::setw(field2_width) << std::right << items[i].price
				<< std::setw(field3_width) << std::right << items[i].type
				<< std::endl;
		}


	}

	// 아이템을 판매한다.

};

#pragma endregion

#pragma region NPC 코드
// 상인이 존재하는 위치에 플레이어가 도달했을때 출력

class NPC
{
private:
	Shop shop;
public:
	// 원래는 private 해서 Get 해야함
	int posX;
	int posY;

	NPC() = default;
	NPC(std::string filename, int posX, int posY) : posX(posX), posY(posY)
	{
		shop = Shop(filename);
	}

	void ShowItem()
	{
		shop.ShowItems();
	}

	void ShowNPC()
	{
		ConsoleUtil::GotoXY(posX, posY);
		std::cout << "$";
	}
};

void Interact(int x1, int y1, NPC& npc) // Player, NPC
{
	if (x1 == npc.posX && y1 == npc.posY)
	{
		npc.ShowItem();
	}
}

void ShowPhase(Shop& shop)
{
	shop.ShowItems();
}

#pragma endregion

#pragma region Player 코드

class Player
{
	// 좌표
	// 돈	<< 

	// Shop코드와 연동 하여... money,  Shop.items[i].price 비교   money -= price;
	// 인벤토리 (어떤 컨테이너를 선택하면 좋을까?)	shop-> player.inventory

	// 현재 플레이어가 가지고 있느 ㄴ아이템 정보를 저장. LEVEL
	// 게임 종료
};


#pragma endregion



int main()
{
	ConsoleUtil::setCursorVisible(false);

	int playerX = 10;
	int playerY = 10;

	//상점 랜덤 출력이 필요할 때
	//int randnum = 0;
	//std::string npcloadfile = "shop" + randnum;
	//npcloadfile.append(".txt");

	NPC npc1("shop1.txt", 3, 5);
	NPC npc2("shop2.txt", 10, 2);
	NPC npc3("shop3.txt", 8, 6);

	//shop.SaveShopData("shop1.txt");

	//shop.SaveShopData("shop2.txt");

	//shop.SaveShopData("shop3.txt");

	while (true)
	{
		// 입력을 받았을 때 좌표가 변하는 코드
		if (_kbhit())
		{
			system("cls");

			if (GetAsyncKeyState(VK_UP))
			{
				if (playerY <= 0) { playerY = 0; }
				else { playerY--; }
				
			}
			if (GetAsyncKeyState(VK_DOWN))
			{
				playerY++;
			}
			if (GetAsyncKeyState(VK_LEFT))
			{
				if (playerX <= 0) { playerX = 0; }
				else { playerX--;}
				
			}
			if (GetAsyncKeyState(VK_RIGHT))
			{
				playerX++;
			}
		}

		npc1.ShowNPC();
		npc2.ShowNPC();
		npc3.ShowNPC();

		Interact(playerX, playerY, npc1);
		Interact(playerX, playerY, npc2);
		Interact(playerX, playerY, npc3);

	//	shop.ShowItems();
		ConsoleUtil::GotoXY(playerX, playerY);
		std::cout << "a";

		_getch();
	}

	
}