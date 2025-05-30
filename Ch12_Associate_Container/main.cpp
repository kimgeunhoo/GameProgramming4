// ���� �����̳�:	(multi, unordered) set, map
#include <set>
#include <map>
#include <algorithm>

#include <iostream>
#include <iomanip>
#include "ConsoleUtility.h"
#include <utility>

// set�� ������� �� ���� ���� �߻��ϴ°�?
#pragma region ���� �����̳� ����ϱ�

void Test1()
{
	std::set<int> nums;

	// �����͸� ��� ������ �� �ֳ�? push
	// ���� �����̳ʴ�? insert ���
	// ���� �����̳ʿ� �����͸� �Է��ϸ� �ڵ����� ������ �ȴ�.
	// Ž���� �� �� ���ĵ� ����� ����ϸ� ȿ�����̴�.
	nums.insert(1);
	nums.insert(5);
	nums.insert(2);
	nums.insert(7);		// {1, 5, 2, 7}

	std::cout << "Ư¡1. Set�� �����Ͱ� �ڵ����� ���ĵ�." << std::endl;
	for (const auto& num : nums)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;
	// set�� Ư¡. �ߺ��� �ȵȴ�.

	nums.insert(1);
	nums.insert(5);
	nums.insert(2);
	nums.insert(7); // {1,1,2,2,5,5,7,7}
	std::cout << "Ư¡2. Set�� �����ʹ� �ߺ��� �ȵȴ�." << std::endl;
	for (const auto& num : nums)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;

	
}

void Test2()
{
	std::cout << "���� �����̳� �տ� Ư�� Ű���带 ���̸� ������ ���Ѵ�." << std::endl;

	std::cout << "Multi Set"<< std::endl;

	std::multiset<int> nums;

	// �����͸� ��� ������ �� �ֳ�? push
	// ���� �����̳ʴ�? insert ���
	// ���� �����̳ʿ� �����͸� �Է��ϸ� �ڵ����� ������ �ȴ�.
	// Ž���� �� �� ���ĵ� ����� ����ϸ� ȿ�����̴�.
	nums.insert(1);
	nums.insert(5);
	nums.insert(2);
	nums.insert(7);		// {1, 5, 2, 7}

	std::cout << "Ư¡1. Set�� �����Ͱ� �ڵ����� ���ĵ�." << std::endl;
	for (const auto& num : nums)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;
	// set�� Ư¡. �ߺ��� �ȵȴ�.

	nums.insert(1);
	nums.insert(5);
	nums.insert(2);
	nums.insert(7); // {1,1,2,2,5,5,7,7}
	std::cout << "Ư¡2. Set�� �����ʹ� �ߺ��� �ȵȴ�." << std::endl;
	for (const auto& num : nums)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;
}

#pragma endregion

#pragma region Ŀ���� Ŭ������ set�� �ִ� ���

struct Item
{
	int id;
	std::string name;

	Item() = default;
	Item(int id, std::string name) : id(id), name(name) {}

	bool operator<(const Item& other) const
	{
		return id < other.id;
	}


};

void Test3() 
{
	std::cout << "Ŀ���� ��ü�� Set���� ����ϱ�" << std::endl;
	std::set<Item> items;

	Item item1 = { 1, "Glass" };
	Item item2 = { 2, "Apple" };
	Item item3 = { 3, "Dirt" };
	Item item4 = { 100, "Magma" };
	Item item5 = { 140, "sword" };
	items.insert(item1);
	items.insert(item2);
	items.insert(item3);
	items.insert(item4);
	items.insert(item5);

	std::cout << "�ߺ��� ��� ����" << std::endl;
	items.insert(Item(3, "����"));

	for (const auto& item : items)
	{
		std::cout << item.id << " " << item.name << std::endl;
	}

	std::cout << "Set�� ����ϸ� �������� ũ�⿡ ���� �ڵ����� ������ ����� ���� �� �ִ�." << std::endl;
	std::cout << "find �Լ��� ����ؼ� ������ �����͸� ã�� �� �ִ�." << std::endl;

	// item ��ü�� items �ȿ��� ã�ƾ� �Ѵ�.
	// item�� id�� n���� �����͸� ã�� �ʹ�.
	// map�� ����ϸ� ���� �������� ���� �ذ� ����
	
}
#pragma endregion

#pragma region map ����ϱ�


void Test4()
{
	std::cout << "map �ڷᱸ�� ����ϱ�" << std::endl;

	std::map<int, Item> items;
	//        1.    2.
	// map�� �����͸� �ִ� ���, pairŬ������ �����ϴ� ��� (1) {Ÿ��, Ÿ��} �߰�ȣ�� ���

	items.insert({ 0, Item(100, "Potion") });

	// (2) make_pair �Լ� ����ϱ�
	items.insert(std::make_pair(10, Item(1000, "�ռҵ�")));
	// (3) pair Ŭ������ ���� �����ϱ� (����� �ʿ� utility)

	std::pair<int, Item> p1(5, Item(101, "���� ����"));
	items.insert(p1);
	std::cout << "Ư¡1. map�� pair�� �̷���� �����͸� �����ϴ� �����̳��̴�" << std::endl;
	std::cout << "Ư¡2. map�� key������ �ڵ� ������ �̷�� ����" << std::endl;

	for (const auto& item : items)
	{
		std::cout << item.first << " " << "ID : " << item.second.id << " �̸� : " << item.second.name << std::endl;
	}

	std::cout << "Ư¡3. ����(Dictionary)�� �ڷᱸ���̴�." << std::endl;

	std::cout << items[0].id << items[0].name << std::endl;



}

#pragma endregion

#pragma region ���� �����̳� �ǽ�

struct NewItem
{
	std::string name;
	int ATK;
	int price;

	NewItem() = default;
	NewItem(std::string name, int ATK, int price) : name(name), ATK(ATK), price(price) {}

};

void Test5()
{
	std::map<std::string, int> map1;
	map1.insert({ "��", 0 });
	map1.insert({ "��", 1 });
	map1.insert(std::make_pair("��", 2));
	map1.insert(std::pair<std::string, int>("��", 3));
	// std::make_pair
	// std::pair<T1, T2>

	for (const auto& e : map1)
	{
		std::cout << " [";
		std::cout << e.first << " " << e.second << " ";
		std::cout << "]" << " ";
	}

	std::cout << "�� Ű���忡�� ��� ���ڰ� ����ֽ��ϱ�? " << map1["��"] << std::endl;

	std::map<int, int> map2;
	// �÷��̾��� id��ȣ(����) , �ش� �÷��̾��� ����
	// id��ȣ�� ???�� ������ ������ ���ΰ�?
	// ���� -> user Ÿ������ �����ϸ� user�� ��� ������ id ��ȣ�� ã�� �� �ִ�.
	map2.insert(std::make_pair(0, 100));
	map2.insert(std::make_pair(99, 9999));
	map2.insert({ 100, 999 });
	map2.insert({ 50, 50 });
	map2.insert({ 25, 100 });

	for (const auto& e : map2)
	{
		std::cout << " [";
		std::cout << e.first << " " << e.second << " ";
		std::cout << "]" << " ";
	}

	std::cout << "map2 �����̳� ���� 0�̶�� Ű���忡�� � ���ڰ� ����ֽ��ϱ�? " << map2[100] << std::endl;

	//std::pair<int, Item> p1(5, Item(101, "���� ����"));
	std::map<std::string, NewItem> map3;
	map3.insert({ "�ռҵ�", NewItem("�ռҵ�", 50, 100) });
	map3.insert({ "���Ǿ�", NewItem("�ռҵ�", 50, 100) });
	
	std::cout << "���࿡ map3�ȿ� ����ִ� �̸��� �ռҵ��� �����͸� �ҷ��� ��" << std::endl;

	NewItem itemInstance = map3["�ռҵ�"];
	std::cout << " �̸� :" << itemInstance.name <<
		" ���ݷ� :" <<	itemInstance.ATK <<
		" ���� :" << itemInstance.price << std::endl;
	// void ButItem(NewItem item) item ����, player �� ���Ͽ� �����Ѵ�.

}

#pragma endregion

#pragma region ���� UI �� ��� �����ϱ�

// iomanip setw left

class ShopItem
{
private:
	int id;
	std::string name;
	int price;
	int ATK;
public:
	ShopItem() = default;
	ShopItem(int id, std::string name, int price, int ATK) :
		id(id), name(name), price(price), ATK(ATK) {}

};

class Player
{
	int money;
public:
	Player(int money) : money(money) {}

	// ������ �������� ȹ���ߴ�.
	void BuyItem(NewItem item)
	{

	}
};

// ������ ���� �������� �Ȱ� �ʹ�.
// �������� �����̳� ���·� ������ �ؾ��Ѵ�.
// map�� ����ؼ� �����̳� ������ �ϰڴ�.

class Shop
{
private:
	// 1�ܰ�
	// Ÿ�� <int , NewItme> items �����̳� �����
	std::map<int, NewItem> items;
public:
	//	Ÿ��<int ,NewItem>	items �����̳ʸ� �����ϱ�
	Shop()
	{
		// 2�ܰ�
		// 5���� ���� ������ ���� �ֱ�
		items.insert({ 0, NewItem("ö��", 5, 100) });
		items.insert({ 1, NewItem("����", 3, 90) });
		items.insert({ 2, NewItem("â", 6, 80) });
		items.insert({ 3, NewItem("Į", 8, 70) });
		items.insert({ 4, NewItem("Ȱ", 2, 120) });
		// (0, NewItem("�̸�", ����, ���ݷ�)));
	}

	void ShowItem()
	{
		std::cout << std::left;
		std::cout << std::setw(10) << "�ε���" << std::setw(20) 
			<< "�̸�" << std::setw(10) << "���ݷ�" << std::setw(10) << "����" << std::endl;

		for (const auto& item : items) 
		{
			std::cout << std::left;
			std::cout << std::setw(10) << item.first << std::setw(20)  << item.second.name 
				<< std::setw(10) << item.second.ATK 
				<< std::setw(10) << item.second.price << std::endl;
		}
		
	}

	void SelItem(Player& player)
	{
		// 3�ܰ�
	}
};

void ShopTest()
{
	// 1. Item �����͸� �����.
	// 2. ������ �����͸� ����� Ŭ����.
	// 3. Shop Ŭ���� �ȿ� map �ڷᱸ�� �߰��ϱ�
	// 4. items �����͸� �ʱ�ȭ ���ּ���.
	
	std::cout << std::endl;
	std::cout << "���� ��� �׽�Ʈ" << std::endl;

	Shop shop1;
	shop1.ShowItem();
}

#pragma endregion




// set���� �����͸� �������� ���� ������ ��, �װ��� ������ map
// pair�� ���� �ؾ��Ѵ�.

int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	//Test5();
	ShopTest();
}