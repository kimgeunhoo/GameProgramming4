// 연관 컨테이너:	(multi, unordered) set, map
#include <set>
#include <map>
#include <algorithm>

#include <iostream>
#include <iomanip>
#include "ConsoleUtility.h"
#include <utility>

// set을 사용했을 때 무슨 일이 발생하는가?
#pragma region 연관 컨테이너 사용하기

void Test1()
{
	std::set<int> nums;

	// 데이터를 어떻게 저장할 수 있나? push
	// 연관 컨테이너는? insert 사용
	// 연관 컨테이너에 데이터를 입력하면 자동으로 정렬이 된다.
	// 탐색을 할 때 정렬된 결과로 사용하면 효과적이다.
	nums.insert(1);
	nums.insert(5);
	nums.insert(2);
	nums.insert(7);		// {1, 5, 2, 7}

	std::cout << "특징1. Set의 데이터가 자동으로 정렬됨." << std::endl;
	for (const auto& num : nums)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;
	// set의 특징. 중복이 안된다.

	nums.insert(1);
	nums.insert(5);
	nums.insert(2);
	nums.insert(7); // {1,1,2,2,5,5,7,7}
	std::cout << "특징2. Set의 데이터는 중복이 안된다." << std::endl;
	for (const auto& num : nums)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;

	
}

void Test2()
{
	std::cout << "연관 컨테이너 앞에 특정 키워드를 붙이면 성질이 변한다." << std::endl;

	std::cout << "Multi Set"<< std::endl;

	std::multiset<int> nums;

	// 데이터를 어떻게 저장할 수 있나? push
	// 연관 컨테이너는? insert 사용
	// 연관 컨테이너에 데이터를 입력하면 자동으로 정렬이 된다.
	// 탐색을 할 때 정렬된 결과로 사용하면 효과적이다.
	nums.insert(1);
	nums.insert(5);
	nums.insert(2);
	nums.insert(7);		// {1, 5, 2, 7}

	std::cout << "특징1. Set의 데이터가 자동으로 정렬됨." << std::endl;
	for (const auto& num : nums)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;
	// set의 특징. 중복이 안된다.

	nums.insert(1);
	nums.insert(5);
	nums.insert(2);
	nums.insert(7); // {1,1,2,2,5,5,7,7}
	std::cout << "특징2. Set의 데이터는 중복이 안된다." << std::endl;
	for (const auto& num : nums)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;
}

#pragma endregion

#pragma region 커스텀 클래스를 set에 넣는 방법

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
	std::cout << "커스텀 객체를 Set으로 출력하기" << std::endl;
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

	std::cout << "중복을 허용 안함" << std::endl;
	items.insert(Item(3, "투구"));

	for (const auto& item : items)
	{
		std::cout << item.id << " " << item.name << std::endl;
	}

	std::cout << "Set을 사용하면 데이터의 크기에 따라 자동으로 정렬한 결과를 얻을 수 있다." << std::endl;
	std::cout << "find 함수를 사용해서 빠르게 데이터를 찾을 수 있다." << std::endl;

	// item 전체를 items 안에서 찾아야 한다.
	// item의 id가 n번인 데이터를 찾고 싶다.
	// map을 사용하면 위의 문제점을 쉽게 해결 가능
	
}
#pragma endregion

#pragma region map 사용하기


void Test4()
{
	std::cout << "map 자료구조 사용하기" << std::endl;

	std::map<int, Item> items;
	//        1.    2.
	// map에 데이터를 넣는 방법, pair클래스를 선언하는 방법 (1) {타입, 타입} 중괄호로 사용

	items.insert({ 0, Item(100, "Potion") });

	// (2) make_pair 함수 사용하기
	items.insert(std::make_pair(10, Item(1000, "롱소드")));
	// (3) pair 클래스를 직접 설정하기 (헤더가 필요 utility)

	std::pair<int, Item> p1(5, Item(101, "빨간 물약"));
	items.insert(p1);
	std::cout << "특징1. map은 pair로 이루어진 데이터를 저장하는 컨테이너이다" << std::endl;
	std::cout << "특징2. map은 key값으로 자동 정렬이 이루어 진다" << std::endl;

	for (const auto& item : items)
	{
		std::cout << item.first << " " << "ID : " << item.second.id << " 이름 : " << item.second.name << std::endl;
	}

	std::cout << "특징3. 사전(Dictionary)형 자료구조이다." << std::endl;

	std::cout << items[0].id << items[0].name << std::endl;



}

#pragma endregion

#pragma region 연관 컨테이너 실습

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
	map1.insert({ "김", 0 });
	map1.insert({ "임", 1 });
	map1.insert(std::make_pair("다", 2));
	map1.insert(std::pair<std::string, int>("라", 3));
	// std::make_pair
	// std::pair<T1, T2>

	for (const auto& e : map1)
	{
		std::cout << " [";
		std::cout << e.first << " " << e.second << " ";
		std::cout << "]" << " ";
	}

	std::cout << "김 키워드에는 어떠한 숫자가 들어있습니까? " << map1["김"] << std::endl;

	std::map<int, int> map2;
	// 플레이어의 id번호(고유) , 해당 플레이어의 레벨
	// id번호가 ???인 유저의 레벨은 얼마인가?
	// 레벨 -> user 타입으로 저장하면 user의 모든 정보는 id 번호로 찾을 수 있다.
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

	std::cout << "map2 컨테이너 안의 0이라는 키워드에는 어떤 숫자가 들어있습니까? " << map2[100] << std::endl;

	//std::pair<int, Item> p1(5, Item(101, "빨간 물약"));
	std::map<std::string, NewItem> map3;
	map3.insert({ "롱소드", NewItem("롱소드", 50, 100) });
	map3.insert({ "스피어", NewItem("롱소드", 50, 100) });
	
	std::cout << "만약에 map3안에 들어있는 이름이 롱소드인 데이터를 불러와 줘" << std::endl;

	NewItem itemInstance = map3["롱소드"];
	std::cout << " 이름 :" << itemInstance.name <<
		" 공격력 :" <<	itemInstance.ATK <<
		" 가격 :" << itemInstance.price << std::endl;
	// void ButItem(NewItem item) item 가격, player 돈 비교하여 구입한다.

}

#pragma endregion

#pragma region 상점 UI 및 기능 구현하기

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

	// 상점의 아이템을 획득했다.
	void BuyItem(NewItem item)
	{

	}
};

// 상인이 많은 아이템을 팔고 싶다.
// 아이템을 컨테이너 형태로 저장을 해야한다.
// map을 사용해서 컨테이너 저장을 하겠다.

class Shop
{
private:
	// 1단계
	// 타입 <int , NewItme> items 컨테이너 만들기
	std::map<int, NewItem> items;
public:
	//	타입<int ,NewItem>	items 컨테이너를 선언하기
	Shop()
	{
		// 2단계
		// 5개의 상점 데이터 만들어서 넣기
		items.insert({ 0, NewItem("철퇴", 5, 100) });
		items.insert({ 1, NewItem("도끼", 3, 90) });
		items.insert({ 2, NewItem("창", 6, 80) });
		items.insert({ 3, NewItem("칼", 8, 70) });
		items.insert({ 4, NewItem("활", 2, 120) });
		// (0, NewItem("이름", 가격, 공격력)));
	}

	void ShowItem()
	{
		std::cout << std::left;
		std::cout << std::setw(10) << "인덱스" << std::setw(20) 
			<< "이름" << std::setw(10) << "공격력" << std::setw(10) << "가격" << std::endl;

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
		// 3단계
	}
};

void ShopTest()
{
	// 1. Item 데이터를 만든다.
	// 2. 정의한 데이터를 사용할 클래스.
	// 3. Shop 클래스 안에 map 자료구조 추가하기
	// 4. items 데이터를 초기화 해주세요.
	
	std::cout << std::endl;
	std::cout << "상점 기능 테스트" << std::endl;

	Shop shop1;
	shop1.ShowItem();
}

#pragma endregion




// set으로 데이터를 정렬했을 때의 불편한 점, 그것을 개선한 map
// pair를 정의 해야한다.

int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	//Test5();
	ShopTest();
}