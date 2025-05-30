/*
	��ǥ : (1) �ܼ� â���� �÷��̾ �����δ�. 
	(2) Ư�� ��ġ���� ���� NPC�� ������ �� ������ �׸��� �����ش�. 
	(3) ������ �̿��Ѵ�.

	Game Object: Player, NPC, Shop
	�ڷᱸ��. Item ��� �����̳ʿ� �����Ͽ� ����� ���ΰ�?
	File Input & output �޸��忡 �ִ� �����͸� NPC�� �����ϴ� ���.
*/

// Ŭ���� ���� -> �׽�Ʈ -> ��� �ű��

#include <iostream>
#include <map>
#include <conio.h>
#include "ConsoleUtility.h"

#include <fstream> // ifsteram ofstream input output
#include <iomanip> // ����� ���� ���
#include <utility>


const int total_width = 60;		// ��ü
const int field1_width = 30;	// �̸� ����
const int field2_width = 15;	// ����
const int field3_width = 15;	// Ÿ��

#pragma region ���� �ڵ�

class Item 
{
public:
	std::string name;
	int price;
	std::string type;
public:
	Item() = default;
	Item(std::string name, int price, std::string type) : name(name), price(price), type(type) {}

	// ������ ���Ȼ� �̰� ����
	// std::string Getname() { return name } const;
};

class Shop
{
private:
	std::map<int, Item> items;	// �ڷᱸ�� Ŭ������ �����Ѵ�.

public:	
	Shop()	// �����͸� �ʱ�ȭ�Ѵ�.
	{
		// 3���� insert ���
		items.insert({ 0, Item("�ռҵ�", 100, "����") });
		items.insert(std::make_pair(1, Item("ü������", 5, "�Һ�")));
		std::pair<int, Item> p1(2, Item("��������", 50, "����"));
		items.insert(p1);
		// �߰��ϰų� �����ؼ� �������� ���� ����� �͵� �����ϴ�.
		items.insert({ 3, Item("���", 200, "����") });
		items.insert({ 4, Item("���Ǿ�", 150, "����") });
		//items.insert({ 5, Item("������", 50, "�Һ�") });
		//items.insert({ 6, Item("ö����", 200, "����") });
		//items.insert({ 7, Item("���װ���", 100, "����") });
		//items.insert({ 8, Item("������", 150, "����") });
		//items.insert({ 8, Item("ö����", 100, "��ȭ���") });
		//items.insert({ 9, Item("ü�ξƸ�", 250, "����") });
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
			std::cerr << "������ ���� �� �����߽��ϴ�." << std::endl;
			std::exit(1);
		}

		int index = 0;
		
		while (!in_file.eof()) // end of file (������ ���� �������� ��)
		{
			in_file >> name >> price >> type;					// ���Ͽ��� name, price type �б�
			items.insert({index, Item(name, price, type) });	// map �ڷᱸ���� ����
			index++;											// ���� index �Ѿ��
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
			std::cerr << "������ ���� �� �����߽��ϴ�." << std::endl;
			std::exit(1);
		}

		for (int i = 0; i < items.size(); i++) // �ε��� ��� ������ ������ �ڷᱸ�����߸� �Ѵ�. vector, map.
		{
			out_file << std::setw(field1_width) << std::left << items[i].name
				<< std::setw(field2_width) << std::right << items[i].price
				<< std::setw(field3_width) << std::right << items[i].type
				<< std::endl;
		}

		out_file.close();
	}


	// �����͸� ����Ͽ� ����� �����Ѵ�.
	void ShowItems()
	{
		//std::string headersize = "012345678901234567890123456789012345678901234567890123456789";
		// �������� �Ӹ���
		//std::cout << headersize << std::endl;

		std::cout << std::setw(field1_width) << std::left << "�̸�"
			<< std::setw(field2_width) << std::right << "����"
			<< std::setw(field3_width) << std::right << "Ÿ��"
			<< std::endl;
		// ���� �ߴ� �ڵ�
		std::cout << std::setw(total_width)		// ���� ����
			<< std::setfill('-')				// ���� '-' ����
			<< ""								// ���� ����2
			<< std::endl;
		
		std::cout << std::setfill(' ');			// ���� ���� ��������
		// �������� ����϶�
		// const auto & elem : items �� ����  // �ε��� ����� �ƴ϶�� �̰��� ���
		for (int i = 0; i < items.size() - 1; i++) // �ε��� ��� ������ ������ �ڷᱸ�����߸� �Ѵ�. vector, map.
		{
			std::cout << std::setw(field1_width) << std::left << items[i].name
				<< std::setw(field2_width) << std::right << items[i].price
				<< std::setw(field3_width) << std::right << items[i].type
				<< std::endl;
		}


	}

	// �������� �Ǹ��Ѵ�.

};

#pragma endregion

#pragma region NPC �ڵ�
// ������ �����ϴ� ��ġ�� �÷��̾ ���������� ���

class NPC
{
private:
	Shop shop;
public:
	// ������ private �ؼ� Get �ؾ���
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

#pragma region Player �ڵ�

class Player
{
	// ��ǥ
	// ��	<< 

	// Shop�ڵ�� ���� �Ͽ�... money,  Shop.items[i].price ��   money -= price;
	// �κ��丮 (� �����̳ʸ� �����ϸ� ������?)	shop-> player.inventory

	// ���� �÷��̾ ������ �ִ� �������� ������ ����. LEVEL
	// ���� ����
};


#pragma endregion



int main()
{
	ConsoleUtil::setCursorVisible(false);

	int playerX = 10;
	int playerY = 10;

	//���� ���� ����� �ʿ��� ��
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
		// �Է��� �޾��� �� ��ǥ�� ���ϴ� �ڵ�
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