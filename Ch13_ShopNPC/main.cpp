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
#include <string>
#include <unordered_map>

const int total_width = 60;		// ��ü
const int field1_width = 30;	// �̸� ����
const int field2_width = 15;	// ����
const int field3_width = 15;	// Ÿ��




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

	virtual void Use() = 0; // ���� ���� �Լ�: Item�� ����ϴ� Ŭ������ �� �Լ��� �ݵ�� ������ �Ͻÿ�.
};

class Weapon : public Item
{
public:
	Weapon(std::string name, int price, std::string type) : Item(name, price, type) {}

	void Use() override
	{
		std::cout << "���⸦ ����մϴ�." << std::endl;
	}
};

/// <summary>
/// �������� Use���� �� ������� ������ ������
/// Player Ŭ������ RemoveItem�� ���.
/// </summary>
class UseableItem : public Item
{
public:
	UseableItem(std::string name, int price, std::string type) : Item(name, price, type) {}

	void Use() override
	{
		std::cout << "�Һ� �������� ����մϴ�." << std::endl;
		// Remove �Ǵ� �������� ȣ��
	}
};

// ��ǥ
// ��	<< 

// Shop�ڵ�� ���� �Ͽ�... money,  Shop.items[i].price ��   money -= price;
// �κ��丮 (� �����̳ʸ� �����ϸ� ������?)	shop-> player.inventory

// ���� �÷��̾ ������ �ִ� ������ ������ ����. LEVEL
// ���� ����
#pragma region Player �ڵ�
class Player
{

private:
	//Item items[100]; ���� �ڵ��� ������. 1�� 100 1�� - 100 vector ??
	std::unordered_map<std::string, Item*> inventory; // Item�� �������� �̸����� ã�� �����̳�

public:
	int posX, posY, money;

	
#pragma region �κ��丮 �ڵ�
	// (1) �÷��̾ ������ �κ��丮�� �ڷᱸ���� �Ѱ��� �����ؼ� �� �ڷᱸ���� ������ �������� �����غ���
	// (2) ������ �ڷᱸ���� ����ϴ� �Լ��� �����

	void AddItem(Item* item)
	{
		inventory.insert({ item->name, item }); 
	}

	void RemoveItem(std::string name)
	{
		// ������ �� ���� ��쿡��?

		if (inventory.find(name) != inventory.end()) // �����̳� �����Ͱ� ������ ���� ����
		{
			inventory.erase(name);
		}
		else {
			std::cout << "�κ��丮�� �ش� �������� �������� �ʽ��ϴ�." << std::endl;
		}

		inventory.erase(name);
	}	

	void RemoveItem(Item* item)
	{
		inventory.erase(item->name);
	}

/*
	������ ���� �� �������� �Ⱦƾ� �Ѵ�. (����� Ŭ���� -> item)
	�ش� ������ ���� �Լ� Use() ���� ������ �ٸ� ������� ����ϰ� �ʹ�. (Ŭ������ ������)
	Item�� �ּҷ� �޾ƿ���, �������� ����� �� �ִ�.	
*/

	// Ư�� Ű�� ������ �� (���� �Է� Player Input)

	// PushOne �Լ� ������ PushOne();

	void Use(Item* item)
	{
		// �Һ� ������ -> ȸ��...
		// ��� ������ -> ��� ����...
		item->Use();

	}

#pragma endregion

	Player() = default;
	Player(int posX, int posY, int money) : posX(posX), posY(posY), money(money) {}

	// �»�ܿ� �÷����� UI ����.

	void ShowPlayerUI()
	{
		ConsoleUtil::GotoXY(70, 5);
		std::cout << "�÷��̾��� ����";
		ConsoleUtil::GotoXY(70, 6);
		std::cout << "�� : " << money;
		ConsoleUtil::GotoXY(70, 7);
		// (2) ���� ������....
		std::cout << "���� ������";
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
		//Use(item); // ��� �׽�Ʈ

		//	vector.push_back(item);;
		//	map.insert(?, item);	// �������� �̸����� �˻��� �� �ְ� map<string, item>
		//	unordered_map<string, item>
	}

};


#pragma endregion

#pragma region ���� �ڵ�


class Shop
{
private:
	/*
		Item �߻� Ŭ���� ����� item ��ü�� Ŭ������ ������ �� ����.
		�ּҷ� �޾ƿ;� �ϴµ�, enum Ÿ�Կ� ���� Ŭ������ �ٸ��� ����ϰԲ� �ڵ带 �ۼ��ؾ� �Ѵ�.
		"���丮 ����" - ���丮 Ŭ������ ���� �����ڸ� �ٸ��� ������ �� �ִ�.
	*/

	std::map<int, Item*> items;	// �ڷᱸ�� Ŭ������ �����Ѵ�.

public:	
	Shop()	// �����͸� �ʱ�ȭ�Ѵ�.
	{
		// 3���� insert ���
		items.insert({ 0, new Weapon("�ռҵ�", 100, "����") });
		items.insert(std::make_pair(1, new UseableItem("ü������", 5, "�Һ�")));
		std::pair<int, Item*> p1(2, new Weapon("��������", 50, "����"));
		items.insert(p1);
		// �߰��ϰų� �����ؼ� �������� ���� ����� �͵� �����ϴ�.
		items.insert({ 3, new Weapon("���", 200, "����") });
		items.insert({ 4, new Weapon("���Ǿ�", 150, "����") });
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
			
			if (type == "����")
			{
				items.insert({index, new Weapon(name, price, type) });	// ������ ���� ���������� ����
				index++;
			}
			else if (type == "�Һ�")
			{
				items.insert({index, new UseableItem(name, price, type) });	// �Һ� �������̶�� �Һ� ���������� ����
				index++;
			}
			else if (type == "����")
			{
				items.insert({ index, new Weapon(name, price, type) });	// �Һ� �������̶�� �Һ� ���������� ����
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
			std::cerr << "������ ���� �� �����߽��ϴ�." << std::endl;
			std::exit(1);
		}

		for (int i = 0; i < items.size(); i++) // �ε��� ��� ������ ������ �ڷᱸ�����߸� �Ѵ�. vector, map.
		{
			out_file << std::setw(field1_width) << std::left << items[i]->name
				<< std::setw(field2_width) << std::right << items[i]->price
				<< std::setw(field3_width) << std::right << items[i]->type
				<< std::endl;
		}

		out_file.close();
	}


	// �����͸� ����Ͽ� ����� �����Ѵ�.
	void ShowItems(int x, int y)
	{
		//std::string headersize = "012345678901234567890123456789012345678901234567890123456789";
		// �������� �Ӹ���
		//std::cout << headersize << std::endl;

		ConsoleUtil::GotoXY(x, y);

		std::cout << std::setw(field1_width) << std::left << "�̸�"
			<< std::setw(field2_width) << std::right << "����"
			<< std::setw(field3_width) << std::right << "Ÿ��"
			<< std::endl;

		ConsoleUtil::GotoXY(x, y + 1);
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
			ConsoleUtil::GotoXY(x, y + 2 + i);
			std::cout << std::setw(field1_width) << std::left << items[i]->name
				<< std::setw(field2_width) << std::right << items[i]->price
				<< std::setw(field3_width) << std::right << items[i]->type
				<< std::endl;
		}


	}

	// �������� �Ǹ��Ѵ�. (�÷��̾ ���� ������...)
	bool BuyItem(int index, Player& player)
	{
		if (items.find(index) != items.end()) // �ش��ϴ� �������� ã�Ҵ�.
		{
			

			Item* itemInstance = items[index];
			if (player.money >= itemInstance->price) // �÷��̾ �������� ����� ��
			{
				player.BuyItem(itemInstance);
				return true;
			}
			else
			{
				std::cout << "�������� �����մϴ�" << std::endl;
			}
		}
		else
		{
			std::cout << "�������� ã�� ���߽��ϴ�." << std::endl;
		}

	}

	void Interact(Player& player)
	{
		int select;
		std::cout << "��ȣ�� �Է��Ͽ� �������� ������ �� �ֽ��ϴ�." << std::endl;

		std::cin >> select;

		BuyItem(select, player);
		
	}

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
		if (!npc.isActivate) { return; } // ������ ��Ȱ��ȭ �Ǹ� ��� �Ұ�

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

	Player player(10, 10, 1000);	// �÷��̾��� ���� ����

	/*int playerX = 10;
	int playerY = 10;*/

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