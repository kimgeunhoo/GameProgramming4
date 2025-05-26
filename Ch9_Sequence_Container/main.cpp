#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "TimeCheck.h"
#include "FunctionPointer.h"
#include "../UtilityProject/ConsoleUtility.h"
/*
	Sequence Container
	Vector
	Deque
	List
*/

/*
	(��ǥ) Vector, List �� �������� ���� ��

	1. vector push_back() �߰�, List push_back() �߰��� �ð� �� ���<> ���� �� ������. �� ������?
	2. ������ �����Ϳ� �����ϴ� �� �ɸ��� �ð�		: ��� vector�� �� ������. list ������ �������� �ð��� �� �ɸ���
	3. ������ �����͸� ġ��� �� �ɸ��� �ð�		: list�� �� ������.

	������ ������ ���� ������ ���� ��: vector ����
	������ ������ ����ϴ� : list ����

	(�ڡڡڡڡ�) ������ ������ ���� ���ٵ� ���� ��� : ?? unordered_map

	vector
	unordered_map
*/

/*
	Vector, List ũ�� �������� ����.
	Vector [ ] �ε����� �����͸� ����� �� �ִ�.
	List   [ ] �ε����� ������ �� ����.				// �迭�� �ƴϸ� ��� ǥ������?

	�������� ������ Ȯ���ϱ� ���ؼ� ȯ�漳���� �����Ѵ�.


*/

struct Node
{
	int value;
	Node* nextPtr;
	Node* prevPtr;
};

void Test1_Vector()
{
	std::vector<int> nums;
	nums.push_back(1);
	for (int i = 0; i < 1000; i++)
	{
		nums.push_back(i);
	}

	std::cout << nums[500] << std::endl;

}

void Test2_List()
{
	std::list<int> nums;

	nums.push_back(3);
	nums.push_front(2);
	nums.push_back(1);

	for (const auto& num: nums)
	{
		std::cout << num << " ";
	}
}

void VectorExample()
{
	std::vector<int> nums;

	for (int i = 0; i < 1000000; i++) 
	{
		nums.push_back(i);
	}

	std::cout << "������ ������ ���� �ð�" << std::endl;

//	std::cout << nums[900] << std::endl;

	// erase�Լ�. n�� ����ϴ� ����

	for (int i = 0; i < 1000; i++)
	{
		auto it = std::next(nums.begin() + 900);
		nums.erase(it);
	}
}

void ListExample()
{
	std::list<int> nums;

	for (int i = 0; i < 1000000; i++)
	{
		nums.push_back(i);
	}

	std::cout << "������ ������ ���� �ð�" << std::endl;

	

	// erase�Լ�. n�� ����ϴ� ����
	for (int i = 0; i < 1000; i++) 
	{
		auto it = std::next(nums.begin(), 900);
		nums.erase(it);
		//std::cout << *it << std::endl;
	}

}

int main()
{
	//Test1_Vector();
	//Test2_List();

	// �ڷᱸ�� �ð� �׽�Ʈ
	//TimeCheckTest();
	//TimeCheckTest2();

	// �Լ� ������ ����
	//Test();

	// ConsoleUtil::TimeCheck() �����ϱ�.

	ConsoleUtil::TimeCheck(VectorExample);
	ConsoleUtil::TimeCheck(ListExample);

	// double ��ȯ
	//double a1 = ConsoleUtil::TimeCheck(VectorExample);
	
}