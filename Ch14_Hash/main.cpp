#include <iostream>
#include <map>
#include <unordered_map>
#include "ConsoleUtility.h"

#pragma region �ؽ� �Լ��� �����ΰ�?
/*
	Hash Function : Hashing�ϴ� �ǹ�?
	- �����ϴ� Ÿ���� Ư���� ��Ģ����, �ٸ� Ÿ������ ��ȯ�ϴ� �۾�.
	Hashing ����� �����͸� �������ؼ� ����� �� �ִ�.
*/

/*
	Hash ���� �ڷᱸ���� ����
	map���� ������ ������ ������, ������ Ž���� ������.
*/


int HashFunction(int input)
{
	return input % 10; // 0 ~ 9

}

void Test1()
{
	HashFunction(25233425); // 25233425 -> 9
	// unordered_map : [key - value]  ::  9��� �ؽ������� 25233425 ���ڰ� ��� �ִ�.

	std::unordered_map <std::string, int> umap;

	umap.insert({ "�ٳ���", 5 });
	umap.insert({ "���", 3 });
	
	std::cout << "���� 1" << std::endl;
	std::cout << "�ٳ����� ���� : " << umap["�ٳ���"] << std::endl;

	std::cout << "���� 2" << std::endl;
	std::cout << "���ξ����� �����ϳ���? " << std::endl;

	auto it = umap.find("���ξ���");

	if (it != umap.end())
	{
		std::cout << "ã�ҽ��ϴ�." << std::endl;
	}
	else
	{
		std::cout << "ã�� ���Ͽ����ϴ�" << std::endl;
	}

}


#pragma endregion

#pragma region map�� unordered_map ��

/*
	Ž���ϴµ� unordered_map�� map���� ������.
	�������� ���� ������ �������� unordered_map�� �����ϴ�.
	unordered_map�� �����ϴ�.

	�� �����Ѱ�? - 
	�����͸� �ʱ�ȭ�� �� �ɸ��� �ð�
	���� �����̳� > ���� �����̳� (map) > unordered_map (�ؽ��Լ��� �����Ǿ���, �ؽ��Լ��� �����ϴ� ���� ������)

	�ؽ��Լ��� ����
	 - �ؽ��浹�� �߻��� �� ���� ���ϰ� �߻��� �� �ִ�.

*/
void MapTimeTest()
{
	std::map<std::string, int> map;

	map.insert({ "A", 1 });
	map.insert({ "B", 1 });
	map.insert({ "C", 1 });
	map.insert({ "D", 1 });
	map.insert({ "E", 1 });

	for (int i = 0; i < 1000000; i++)
	{
		map.find("A");
	}

}

void UMapTimeTest()
{
	std::map<std::string, int> umap;

	umap.insert({ "A", 1 });
	umap.insert({ "B", 1 });
	umap.insert({ "C", 1 });
	umap.insert({ "D", 1 });
	umap.insert({ "E", 1 });

	for (int i = 0; i < 1000000; i++)
	{
		umap.find("A");
	}

}

void Test2()
{
	std::cout << "ù ��° �� - ������ �Է� �ð� ��" << std::endl;

	ConsoleUtil::TimeCheck(MapTimeTest);
	ConsoleUtil::TimeCheck(UMapTimeTest);

	std::cout << "map ���� : �������� �ڵ� ������ �߻��Ѵ�." << std::endl;
	std::cout << "������ �� �����͸� �ʿ��� �� map�� �����ϴ�." << std::endl;
	std::cout << "�� �̿��� �����̳� �ȿ� ������ �����͸� ã�� �����ϰ� �ʹ�." << std::endl;
	std::cout << "�ι�° �� - ������ �˻� �ð�ǥ" << std::endl;

	ConsoleUtil::TimeCheck(MapTimeTest);
	ConsoleUtil::TimeCheck(UMapTimeTest);

}

#pragma endregion

int main()
{
	Test1();
	Test2();
}