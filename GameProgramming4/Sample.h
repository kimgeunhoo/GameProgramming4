#pragma once

// int array[100];
// 1. vector<int> vec; vector<타입>은 자료형 말고도 클래스, 스트럭쳐도 가능

// 2. template 간단한 코드로 구현해볼 것


// vector< > 직접 정의한 클래스를 한번 저장하고, 정렬하고, 출력하는 예제를 만들어보시오
// 은행 계좌
// 게임에 데이터를 클래스로 표현
// vector<<< >>> 가능은 한데 머리아플듯


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class PocketMonster 
{
private:
	int _number;
	string _name;

public:
	PocketMonster(int number, string name)
		: _number(number), _name(name) {}

	int Get_Number() const
	{
		return _number;
	}
	
	string Get_Name() const
	{
		return _name;
	}

	bool operator<(const PocketMonster& other)
	{
		// this->_number : 자신의 도감 번호
		// other.Get_number() : 비교 대상의 도감 번호

		return this->_number < other.Get_Number();
	}

	bool operator>(const PocketMonster& other)
	{
		// this->_number : 자신의 도감 번호
		// other.Get_number() : 비교 대상의 도감 번호

		return this->_number > other.Get_Number();

		//return this->_name > other.Get_Name();
	}

	bool operator=(const PocketMonster& other)
	{
		// this->_number : 자신의 도감 번호
		// other.Get_number() : 비교 대상의 도감 번호

		return this->_number = other.Get_Number();

		//return this->_name > other.Get_Name();
	}

};

//

class Player 
{
	vector<PocketMonster> myPocketmon;
};


void Example1() 
{
	PocketMonster pikachu(25, "피카츄");
	PocketMonster Bulbasaur(1, "이상해씨");
	PocketMonster Ivysaur(2, "이상해풀");
	PocketMonster Venusaur(3, "이상해꽃");
	PocketMonster Charmander(4, "파이리");
	PocketMonster Charmeleon(5, "리자드");
	PocketMonster Charizard(6, "리자몽");
	PocketMonster Squirtle(7, "꼬부기");
	PocketMonster Wartortle(8, "어니부기");
	PocketMonster Blastoise(9, "거북왕");

	//cout << "No." << pikachu.Get_Number() << " " << pikachu.Get_Name() << endl;

	bool result = pikachu < Bulbasaur;
	cout << "이상해씨가 피카츄보다 도감 번호가 큰가? : " << endl;
	if (Bulbasaur > pikachu) {
		cout << "네" << endl;
	}
	else {
		cout << "아니오" << endl;
	}

	vector<PocketMonster> pocketDataBase;

	// 데이터 입력

	pocketDataBase.push_back(pikachu);
	pocketDataBase.push_back(Bulbasaur);
	pocketDataBase.push_back(Ivysaur);
	pocketDataBase.push_back(Venusaur);
	pocketDataBase.push_back(Charmander);
	pocketDataBase.push_back(Charmeleon);
	pocketDataBase.push_back(Charizard);
	pocketDataBase.push_back(Squirtle);
	pocketDataBase.push_back(Wartortle);
	pocketDataBase.push_back(Blastoise);

	// 데이터 알고리즘 (정렬)
	sort(pocketDataBase.begin(), pocketDataBase.end());
	
	// 데이터 출력
	for (auto& pocketmon : pocketDataBase)
	{
		cout << "No." << pocketmon.Get_Number() << " " << pocketmon.Get_Name() << endl;
	}

	// 데이터 출력(검색)
	for (auto& pocketmon : pocketDataBase)
	{
		if (pocketmon.Get_Number() == 1)
		{
			cout << "No." << pocketmon.Get_Number() << " " << pocketmon.Get_Name() << endl;
			cout << pocketmon.Get_Number() << "번 몬스터를 찾았다" << endl;
			cout << endl;
		}

		else {
			cout << "No." << pocketmon.Get_Number() << " " << pocketmon.Get_Name() << endl;
			cout << "찾지 못하였다." << endl;
		}
	}
}

