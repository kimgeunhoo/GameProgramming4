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
#include <string>
#include <unordered_map>

const int total_width = 60;		// 전체
const int field1_width = 30;	// 이름 길이
const int field2_width = 15;	// 가격
const int field3_width = 15;	// 타입




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

	virtual void Use() = 0; // 순수 가상 함수: Item을 상속하는 클래스가 이 함수를 반드시 구현을 하시오.
};

class Weapon : public Item
{
public:
	Weapon(std::string name, int price, std::string type) : Item(name, price, type) {}

	void Use() override
	{
		std::cout << "무기를 사용합니다." << std::endl;
	}
};

/// <summary>
/// 아이템을 Use했을 때 사라지는 종류의 아이템
/// Player 클래스의 RemoveItem을 사용.
/// </summary>
class UseableItem : public Item
{
public:
	UseableItem(std::string name, int price, std::string type) : Item(name, price, type) {}

	void Use() override
	{
		std::cout << "소비성 아이템을 사용합니다." << std::endl;
		// Remove 되는 아이템을 호출
	}
};

// 좌표
// 돈	<< 

// Shop코드와 연동 하여... money,  Shop.items[i].price 비교   money -= price;
// 인벤토리 (어떤 컨테이너를 선택하면 좋을까?)	shop-> player.inventory

// 현재 플레이어가 가지고 있는 아이템 정보를 저장. LEVEL
// 게임 종료
#pragma region Player 코드
class Player
{

private:
	//Item items[100]; 다음 코드의 문제점. 1억 100 1억 - 100 vector ??
	std::unordered_map<std::string, Item*> inventory; // Item을 아이템의 이름으로 찾는 컨테이너

public:
	int posX, posY, money;

	
#pragma region 인벤토리 코드
	// (1) 플레이어가 소유한 인벤토리를 자료구조를 한가지 선택해서 그 자료구조에 구매한 아이템을 저장해보기
	// (2) 저장한 자료구조를 사용하는 함수를 만들기

	void AddItem(Item* item)
	{
		inventory.insert({ item->name, item }); 
	}

	void RemoveItem(std::string name)
	{
		// 제거할 수 없는 경우에는?

		if (inventory.find(name) != inventory.end()) // 컨테이너 데이터가 존재할 때만 실행
		{
			inventory.erase(name);
		}
		else {
			std::cout << "인벤토리에 해당 아이템이 존재하지 않습니다." << std::endl;
		}

		inventory.erase(name);
	}	

	void RemoveItem(Item* item)
	{
		inventory.erase(item->name);
	}

/*
	상점은 전부 다 아이템을 팔아야 한다. (공통된 클래스 -> item)
	해당 아이템 같은 함수 Use() 갖고 있지만 다른 기능으로 사용하고 싶다. (클래스의 다형성)
	Item을 주소로 받아오면, 다형성을 사용할 수 있다.	
*/

	// 특정 키를 눌렀을 때 (게임 입력 Player Input)

	// PushOne 함수 포인터 PushOne();

	void Use(Item* item)
	{
		// 소비 아이템 -> 회복...
		// 장비 아이템 -> 장비 장착...
		item->Use();

	}

#pragma endregion

	Player() = default;
	Player(int posX, int posY, int money) : posX(posX), posY(posY), money(money) {}

	// 좌상단에 플레리어 UI 띄우기.

	void ShowPlayerUI()
	{
		ConsoleUtil::GotoXY(70, 5);
		std::cout << "플레이어의 정보";
		ConsoleUtil::GotoXY(70, 6);
		std::cout << "돈 : " << money;
		ConsoleUtil::GotoXY(70, 7);
		// (2) 보유 아이템....
		std::cout << "보유 아이템";
		ConsoleUtil::GotoXY(70, 8);
		for (const auto& item : inventory) 
		{
			std::cout << item.first << " ";
		}
	}

	void BuyItem(Item* item)
	{
		money -= item->price;
		AddItem(item);
		//Use(item); // 사용 테스트

		//	vector.push_back(item);;
		//	map.insert(?, item);	// 아이템의 이름으로 검색할 수 있게 map<string, item>
		//	unordered_map<string, item>
	}

};


#pragma endregion

#pragma region 상점 코드


class Shop
{
private:
	/*
		Item 추상 클래스 만들면 item 자체를 클래스로 생성할 수 없다.
		주소로 받아와야 하는데, enum 타입에 따라 클래스를 다르게 사용하게끔 코드를 작성해야 한다.
		"팩토리 패턴" - 팩토리 클래스를 만들어서 생성자를 다르게 구현할 수 있다.
	*/

	std::map<int, Item*> items;	// 자료구조 클래스를 보관한다.

public:	
	Shop()	// 데이터를 초기화한다.
	{
		// 3가지 insert 방식
		items.insert({ 0, new Weapon("롱소드", 100, "무기") });
		items.insert(std::make_pair(1, new UseableItem("체력포션", 5, "소비")));
		std::pair<int, Item*> p1(2, new Weapon("나무방패", 50, "무기"));
		items.insert(p1);
		// 추가하거나 제거해서 종류별로 상점 만드는 것도 가능하다.
		items.insert({ 3, new Weapon("대검", 200, "무기") });
		items.insert({ 4, new Weapon("스피어", 150, "무기") });
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
			
			if (type == "무기")
			{
				items.insert({index, new Weapon(name, price, type) });	// 무기라면 무기 아이템으로 저장
				index++;
			}
			else if (type == "소비")
			{
				items.insert({index, new UseableItem(name, price, type) });	// 소비 아이템이라면 소비 아이템으로 저장
				index++;
			}
			else if (type == "갑옷")
			{
				items.insert({ index, new Weapon(name, price, type) });	// 소비 아이템이라면 소비 아이템으로 저장
				index++;
			}
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
			out_file << std::setw(field1_width) << std::left << items[i]->name
				<< std::setw(field2_width) << std::right << items[i]->price
				<< std::setw(field3_width) << std::right << items[i]->type
				<< std::endl;
		}

		out_file.close();
	}


	// 데이터를 사용하여 기능을 구현한다.
	void ShowItems(int x, int y)
	{
		//std::string headersize = "012345678901234567890123456789012345678901234567890123456789";
		// 아이템의 머릿말
		//std::cout << headersize << std::endl;

		ConsoleUtil::GotoXY(x, y);

		std::cout << std::setw(field1_width) << std::left << "이름"
			<< std::setw(field2_width) << std::right << "가격"
			<< std::setw(field3_width) << std::right << "타입"
			<< std::endl;

		ConsoleUtil::GotoXY(x, y + 1);
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
			ConsoleUtil::GotoXY(x, y + 2 + i);
			std::cout << std::setw(field1_width) << std::left << items[i]->name
				<< std::setw(field2_width) << std::right << items[i]->price
				<< std::setw(field3_width) << std::right << items[i]->type
				<< std::endl;
		}


	}

	// 아이템을 판매한다. (플레이어가 돈이 없으면...)
	bool BuyItem(int index, Player& player)
	{
		if (items.find(index) != items.end()) // 해당하는 아이템을 찾았다.
		{
			

			Item* itemInstance = items[index];
			if (player.money >= itemInstance->price) // 플레이어가 소지금이 충분할 때
			{
				player.BuyItem(itemInstance);
				return true;
			}
			else
			{
				std::cout << "소지금이 부족합니다" << std::endl;
			}
		}
		else
		{
			std::cout << "아이템을 찾지 못했습니다." << std::endl;
		}

	}

	void Interact(Player& player)
	{
		int select;
		std::cout << "번호를 입력하여 아이템을 구매할 수 있습니다." << std::endl;

		std::cin >> select;

		BuyItem(select, player);
		
	}

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
	bool isActivate;

	NPC() = default;
	NPC(std::string filename, int posX, int posY) : posX(posX), posY(posY), isActivate(true)
	{
		shop = Shop(filename);
	}

	void ShowItem(int x, int y)
	{
		shop.ShowItems(x, y);
	}

	void Interact(Player& player)
	{
		shop.Interact(player);
		isActivate = false;
	}

	void ShowNPC()
	{
		if (isActivate == false) return;

		ConsoleUtil::GotoXY(posX, posY);
		std::cout << "$";
	}
};

void Interact(Player& player, NPC& npc, int UI_X, int UI_Y) // Player, NPC
{
	if (player.posX == npc.posX && player.posY == npc.posY)
	{
		// npc.isActivate == false 
		if (!npc.isActivate) { return; } // 상점이 비활성화 되면 사용 불가

		npc.ShowItem(UI_X, UI_Y);
		npc.Interact(player);
	}
}

void ShowPhase(Player& player, Shop& shop)
{
	shop.ShowItems(player.posX, player.posY);
}

#pragma endregion





int main()
{
	ConsoleUtil::setCursorVisible(false);

	Player player(10, 10, 1000);	// 플레이어의 시작 설정

	/*int playerX = 10;
	int playerY = 10;*/

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
				if (player.posY <= 0) { player.posY = 0; }
				else { player.posY--; }
				
			}
			if (GetAsyncKeyState(VK_DOWN))
			{
				player.posY++;
			}
			if (GetAsyncKeyState(VK_LEFT))
			{
				if (player.posX <= 0) { player.posX = 0; }
				else { player.posX--;}
				
			}
			if (GetAsyncKeyState(VK_RIGHT))
			{
				player.posX++;
			}
		}

		player.ShowPlayerUI();

		npc1.ShowNPC();
		npc2.ShowNPC();
		npc3.ShowNPC();

		Interact(player, npc1, 0, 10);
		Interact(player, npc2, 0, 10);
		Interact(player, npc3, 0, 10);

	//	shop.ShowItems();
		ConsoleUtil::GotoXY(player.posX, player.posY);
		std::cout << "a";

		_getch();
	}

	
}