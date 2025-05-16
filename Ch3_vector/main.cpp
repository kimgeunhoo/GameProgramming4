#include <iostream>
#include <vector>

using namespace std;

/*
	��ǥ: �迭�� ũ�⸦ �������� �����ϴ� �ڵ�
		
		  "�ڵ�" vector
*/

/*
	int 10�� �迭�� �����Ѵ�.
	�迭�� Ư¡ : ũ�Ⱑ ����. ���� �� ũ�⸦ ������� �Ѵ�. 40����Ʈ�� ������ Ȯ���ؾ��Ѵ�.
	41����Ʈ ������ �������� �޸𸮸� ���� - ������ �߻�
*/

// �迭�� ũ�⸦ N ���� �� �ְ� �ڵ带 �߰��غ���
// String, char, double �ڵ� �߰��غ���

/*
	vector Ŭ������ ���
	 push_back	  : ������ ���� �����͸� �߰��Ѵ�. (�����ϴ� ������)
	 size()		  : ������ ���̸� ��ȯ�Ѵ�.
	 emplace_back : ������ ���� ���� ������ ������ �߰�
	 pop_back()	  : ���� ���� ������ �ϳ��� �����
	 empty()	  : ������ ũ�Ⱑ 0�̸� true, �ƴϸ� false
	 insert()	  : �־��� ��ġ�� �����͸� �Է��Ѵ�. vec.insert(vec.begin() + 2 , 10);
	 erase()	  : �־��� ��ġ�� �����͸� �����Ѵ�. vec.erase(vec.begin())
*/

/*
	vec.0 = 1_������  <- erase �غ��ٴ���
*/



template<typename T, int N>
void MakeArray(T*& ptr, T value)
{
	// ����� �޸𸮸� ����
	// �迭�� ũ�⸦ �������� ����� �����ִ� ���� �ڵ�
	delete[] ptr; // delete�� [] �ϸ� �迭 ����
	ptr = new T[N];

	for (int i = 0; i < N; i++)
	{
		*(ptr + i) = value;
		cout << *(ptr + i) << " ";
	}

	cout << endl;
}

class MonsterHandle
{

};

// Ŭ���� �̸� Monster ��ȣ, �̸�
class Monster 
{
private:
	int _num;
	string _name;

public:
	Monster() = default;
	~Monster() = default;
	Monster(int num, string name) : 
		_num(num), _name(name) {}

	int get_num() const { return _num; }
	string get_name() const { return _name; }

	// "cout<< Monster ������� ���� ����"
	// friend: �ܺ� Ŭ������ private�� ������ �� �ְ� ���ִ� Ű���� (��ü���� ��Ŀ� ����Ǳ� �Ѵ�.)
	friend ostream& operator<<(ostream& os, Monster &obj) // obj �ּ� �����Ͽ� ��ȯ���� os�� ǥ��
	{
		os << "NO." << obj._num << "_" << obj._name << "";
		return os;
	}

};

template<typename T>
void Show(vector<T>& vec) 
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << endl;
	}
}

int main() 
{
	// �������� �迭�� ũ�⸦ �����ϰ� �����ϴ� �Լ� ���ø�
	// Ŭ���� ���ø�
	// �κ��丮 10��. -> 11��	(Array 10��.) -> 

	int* aPtr = new int[10];
	double* bPtr = new double[10];
	string* cPtr = new string[10];
	Monster* dPtr = new Monster[10];

	Monster sample(0, "���");
	Monster pika(25, "��ī��");

	MakeArray<int,10>(aPtr, 0); // aPtr ũ�� ������ ������.
	MakeArray<double, 15>(bPtr, 0.1);
	MakeArray<string, 10>(cPtr, "owo");
	MakeArray<Monster, 10>(dPtr, sample);
	MakeArray<Monster, 5>(dPtr, pika);

	int input;

	cout << "�迭�� ũ�⸦ �Է��� �ּ��� : " << endl;

	// vector�� ���� �迭�� �����ϰ� ����ϱ�


	cout << "vector ��� ���� " << endl;

	vector<int> nums; // vector int�� �����ϴ� �����迭 Ŭ����. (�迭 ũ�Ⱑ �����Ѵ�.)


	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);

	Show<int>(nums);

	vector<Monster> monsterDatabase;
	monsterDatabase.emplace_back(1, "���");
	monsterDatabase.emplace_back(2, "��");
	monsterDatabase.emplace_back(3, "������");
	monsterDatabase.clear();
	//monsterDatabase.pop_back();
	//monsterDatabase.pop_back(); // push pop ���� �����ϸ� �ȴ�.
	//monsterDatabase.pop_back(); 

	Show<Monster>(monsterDatabase);

	if(!monsterDatabase.empty())
	{
		cout << "�����Ͱ� �ֽ��ϴ�." << endl;
	}
	else
	{
		cout << "�����Ͱ� �����ϴ�." << endl;
	}


	cout << "int�� ������." << endl;
	vector<int> number;
	
	number.push_back(1);
	number.push_back(2);
	number.push_back(3);
	Show<int>(number);
	number.pop_back();
	Show<int>(number);
	number.insert(number.begin() + 0, 5); // �迭���� [0][1][2] ������ ���󰣴�.
	Show<int>(number);
	number.erase(number.begin() + 0);
	Show<int>(number);
	number.clear();

	cout << "�׿� ������." << endl;

	vector<double> dnumber;
	vector<string> keyword;
	vector<Monster> newMonster;

	for (int i = 0; i < 10; i++) 
	{
		number.push_back(0);
		dnumber.push_back(0.1);
		keyword.push_back("AAA");
		monsterDatabase.push_back(sample);
	}
	Show<int>(number);
	Show<double>(dnumber);
	Show<string>(keyword);
	Show<Monster>(monsterDatabase);

	// int Ÿ���� �����ϴ� �迭�� vector �����̳ʿ� �����ϴ� �ڵ带 �ۼ��Ͻÿ�.
	vector<int> nnn;
	nnn.push_back(1);
	nnn.pop_back();
	nnn.size();

	// ��Ʈ����. 4���� ��
	// vector<Block> blocks;

	// 4���� ����. ����, ������, ����, �ü�
	// vector<GameClass> gameClasses;

	// ��ü. Monster
	// �����ϴ� Ŭ���� MonsterManager
	// vector<Monster>


}
