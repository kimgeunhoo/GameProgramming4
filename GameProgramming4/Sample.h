#pragma once

// int array[100];
// 1. vector<int> vec; vector<Ÿ��>�� �ڷ��� ���� Ŭ����, ��Ʈ���ĵ� ����

// 2. template ������ �ڵ�� �����غ� ��


// vector< > ���� ������ Ŭ������ �ѹ� �����ϰ�, �����ϰ�, ����ϴ� ������ �����ÿ�
// ���� ����
// ���ӿ� �����͸� Ŭ������ ǥ��
// vector<<< >>> ������ �ѵ� �Ӹ����õ�


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
		// this->_number : �ڽ��� ���� ��ȣ
		// other.Get_number() : �� ����� ���� ��ȣ

		return this->_number < other.Get_Number();
	}

	bool operator>(const PocketMonster& other)
	{
		// this->_number : �ڽ��� ���� ��ȣ
		// other.Get_number() : �� ����� ���� ��ȣ

		return this->_number > other.Get_Number();

		//return this->_name > other.Get_Name();
	}

	bool operator=(const PocketMonster& other)
	{
		// this->_number : �ڽ��� ���� ��ȣ
		// other.Get_number() : �� ����� ���� ��ȣ

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
	PocketMonster pikachu(25, "��ī��");
	PocketMonster Bulbasaur(1, "�̻��ؾ�");
	PocketMonster Ivysaur(2, "�̻���Ǯ");
	PocketMonster Venusaur(3, "�̻��ز�");
	PocketMonster Charmander(4, "���̸�");
	PocketMonster Charmeleon(5, "���ڵ�");
	PocketMonster Charizard(6, "���ڸ�");
	PocketMonster Squirtle(7, "���α�");
	PocketMonster Wartortle(8, "��Ϻα�");
	PocketMonster Blastoise(9, "�źϿ�");

	//cout << "No." << pikachu.Get_Number() << " " << pikachu.Get_Name() << endl;

	bool result = pikachu < Bulbasaur;
	cout << "�̻��ؾ��� ��ī�򺸴� ���� ��ȣ�� ū��? : " << endl;
	if (Bulbasaur > pikachu) {
		cout << "��" << endl;
	}
	else {
		cout << "�ƴϿ�" << endl;
	}

	vector<PocketMonster> pocketDataBase;

	// ������ �Է�

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

	// ������ �˰��� (����)
	sort(pocketDataBase.begin(), pocketDataBase.end());
	
	// ������ ���
	for (auto& pocketmon : pocketDataBase)
	{
		cout << "No." << pocketmon.Get_Number() << " " << pocketmon.Get_Name() << endl;
	}

	// ������ ���(�˻�)
	for (auto& pocketmon : pocketDataBase)
	{
		if (pocketmon.Get_Number() == 1)
		{
			cout << "No." << pocketmon.Get_Number() << " " << pocketmon.Get_Name() << endl;
			cout << pocketmon.Get_Number() << "�� ���͸� ã�Ҵ�" << endl;
			cout << endl;
		}

		else {
			cout << "No." << pocketmon.Get_Number() << " " << pocketmon.Get_Name() << endl;
			cout << "ã�� ���Ͽ���." << endl;
		}
	}
}

