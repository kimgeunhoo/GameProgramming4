
#include "ConsoleUtility.h"

// ���� �����̳� Sequence Container : vector, list, deque
// #include <�����̳�>

#include <vector>
#include <list>
#include <deque>

// ���� �����̳� associate Container : (multi, unordered) set, map

#include <set>
#include <map>
#include <algorithm> // �����̳ʿ� �����͸� ó���ϴ� ��ɵ��� ����Ǿ� �ִ� ���̺귯��

// 1�ܰ�. ���� �����̳� ������ �Է� �ð� ��
// 2�ܰ�. ���� �����̳� �߰� ������ �Է� �ð� ��
// 3�ܰ�. ������, �߰� ������ ������ ���Ͽ� ������ ���� �����̳� ����ϱ�

#pragma region (1)�ܰ�. ���� �����̳��� ������ �Է� �ð� ��

void DataPushByVector()
{
	std::vector<int> nums;

	for (int i = 0; i < 1000; i++)
	{
		nums.push_back(i);
	}
}

void DataPushByList()
{
	std::list<int> nums;

	for (int i = 0; i < 1000; i++)
	{
		nums.push_back(i);
	}
}

void DataPushByDeque()
{
	std::deque<int> nums;

	for (int i = 0; i < 1000; i++)
	{
		nums.push_back(i);
	}
}

void Test1()
{
	std::cout << "������ �Է� �ð� ��" << std::endl;
	std::cout << "vector�� �ð� : " ;
	ConsoleUtil::TimeCheck(DataPushByVector);
	std::cout << "list�� �ð� : ";
	ConsoleUtil::TimeCheck(DataPushByList);
	std::cout << "deque�� �ð� : ";
	ConsoleUtil::TimeCheck(DataPushByDeque);
	// vector�� ���� ������, list deque�� ����ϳ� deque�� �ټ��ϰ� ���� ����
	std::cout << "���: �ܼ� �����͸� �Է��� �� vector�� ���� ������." << std::endl;
	std::cout << std::endl;
}

#pragma endregion

#pragma region (2)�ܰ�. ���� �����̳� �߰� ������ �Է� �ð� ��

void InsertDataByVector()
{
	std::vector<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push_back(i);
	}

	for (int i = 0; i < 10000; i++)
	{
		auto it = nums.begin() + 5;
		nums.insert(it, i);
	}
}

void InsertDataByList()
{
	std::list<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push_back(i);
	}

	for (int i = 0; i < 10000; i++)
	{
		// list�� �ּҰ� ��� ���� �ּҸ� ����Ŵ. �迭�� �����ϸ� ���ϱⰡ �Ұ���
		auto it = std::next(nums.begin(), 5);
		nums.insert(it, i);
	}

	
}

void InsertDataByDeque()
{
	std::deque<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push_back(i);
	}

	for (int i = 0; i < 10000; i++)
	{
		auto it = nums.begin() + 5;
		nums.insert(it, i);
	}
	
}

void Test2()
{
	std::cout << "�߰� ������ �Է� �ð� ��" << std::endl;
	std::cout << "vector�� �ð� : ";
	ConsoleUtil::TimeCheck(InsertDataByVector);
	std::cout << "list�� �ð� : ";
	ConsoleUtil::TimeCheck(InsertDataByList);
	std::cout << "deque�� �ð� : ";
	ConsoleUtil::TimeCheck(InsertDataByDeque);
	// ��Ȳ�� ���� �޶���. �߰� ���� ������ �������� list�� vector���� ������ ���Ѵ�. deque�� ���� ������
	std::cout << "��� : ó���� ������ �Է����� �� vector�� ������." << std::endl;
	std::cout << "���2 : �߰� ����(����) ������ ������ �������� list�� ��������." << std::endl;
	std::cout << std::endl;
}
#pragma endregion

#pragma region (2-2)�ܰ�. ���� �����̳� �����͸� �� �տ� �߰��� �� �ɸ��� �ð� ��

void FrontPushByVector()
{
	std::vector<int> nums;

	for (int i = 0; i < 10000; i++) 
	{
		auto it = nums.begin();
		nums.insert(it, i);
	}
}

void FrontPushByList()
{
	std::list<int> nums;

	for (int i = 0; i < 10000; i++)
	{
		nums.push_front(i);
	}
}

// double ended queue
// block

void FrontPushByDeque()
{
	std::deque<int> nums;

	for (int i = 0; i < 10000; i++)
	{
		nums.push_front(i);
	}
}

void Test2_2()
{
	std::cout << "ù ��° ��ġ�� ������ �Է� �ð� ��" << std::endl;
	std::cout << "vector�� �ð� : ";
	ConsoleUtil::TimeCheck(FrontPushByVector);
	std::cout << "list�� �ð� : ";
	ConsoleUtil::TimeCheck(FrontPushByList);
	std::cout << "deque�� �ð� : ";
	ConsoleUtil::TimeCheck(FrontPushByDeque);
	// deque�� ù��° Ȥ�� ������ ���Ҹ� �ִ� ��쿡 ����������.
	std::cout << "��� : ù��° ���Ҹ� �ִ� ��쿡 vector�� ������ ������ deque�� �ذ��� �� �ִ�." << std::endl;
	std::cout << std::endl;
}
#pragma endregion

#pragma region (2-3) ���� ���� ���ٿ� �ɸ��� �ð� ��

void RandomAccessByVector()
{
	std::vector<int> nums;

	for (int i = 0; i < 100; i++)
	{
		nums.push_back(i);
	}
	
	for (int i = 0; i < 50; i++)
	{
		nums[i] = 0;
	}

}

void RandomAccessByList()
{
	std::list<int> nums;

	for (int i = 0; i < 100; i++)
	{
		nums.push_back(i);
	}

	for (int i = 0; i < 50; i++)
	{
		auto it = std::next(nums.begin(), i);
		*it = 0;
	}
}

void RandomAccessByDeque()
{
	std::deque<int> nums;

	for (int i = 0; i < 100; i++)
	{
		nums.push_back(i);
	}

	for (int i = 0; i < 50; i++)
	{
		nums[i] = 0;
	}
}

void Test2_3() 
{
	std::cout << "���� ������ �Է� �ð� ��" << std::endl;
	std::cout << "vector�� �ð� : ";
	ConsoleUtil::TimeCheck(RandomAccessByVector);
	std::cout << "list�� �ð� : ";
	ConsoleUtil::TimeCheck(RandomAccessByList);
	std::cout << "deque�� �ð� : ";
	ConsoleUtil::TimeCheck(RandomAccessByDeque);
	// ��Ȳ�� ���� �޶���. �߰� ���� ������ �������� list�� vector���� ������ ���Ѵ�. deque�� ���� ������
	std::cout << "��� : �迭 ������ �ڷᱸ��(vector, deque) �ٷ� ������ �� �ִ�." << std::endl;
	std::cout << "list�� ��쿡�� ���۰� �Ÿ��� �ָ� �ּ��� �ð��� ���� �ɸ���." << std::endl;
	std::cout << std::endl;
}

#pragma endregion

#pragma region ���� �����̳� ��

/*		  |   Vector             |    List              |    Deque       |
	push  |    1.                |    3                 |     2          |
  insert  |    2.                |    1                 |     3          |
   front  |    3.                |    2                 |     1          |
  access  |    1.                |    3                 |     2          |
*/

/*
	Case 1. ��Ȳ �ο�, �������� �Է��� (����) �߻��ϰ�, �߰� ������ �Է��� (������), �տ� ������ (������), ���� ������ (����) ���.
	case 1�� Vector�� ������ ���δ�.
	Case 2. ������ �Է� (����) �߻�, �߰� ������ �Է� (����) �߻�, �տ� ������ (������), ���� ����(������) ���
	case 2�� List�� ������ ���δ�.
*/

#pragma endregion

#pragma region (3)�ܰ�. ���� �����̳ʿ� ���� �����̳�

// �����͸� �����ϴ� �������� �����̳ʸ� �������.
// std::vector<monster> nums;	int monster = nums[?];
// �����̳� �ȿ� �ش��ϴ� �����Ͱ� ������? ������ ����Ѵ�.	if(�����Ͱ� ������ ��) -> ����.
bool Find(int value)
{
	int nums[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (int i = 0; i < 10; i++)
	{
		if (nums[i] == value)
		{
			std::cout << nums[i] << " ���� ã�ҽ��ϴ�," << std::endl;
			return true;
		}
	}
	std::cout << "���� ã�� ���߽��ϴ�" << std::endl;
	return false;
}

void FindByVector()
{
	std::vector<int> nums;

	for (int i = 10; i > 0; i--)
	{
		nums.push_back(i);
	}
	
	for (auto num : nums)
	{
		std::cout << num << " ";
	}

	for (int i = 0; i < 1000; i++)
	{
		std::find(nums.begin(), nums.end(), 5);
	}
}

void FindByList()
{
	std::list<int> nums;

	for (int i = 10; i > 0; i--)
	{
		nums.push_back(i);
	}

	for (auto num : nums)
	{
		std::cout << num << " ";
	}

	for (int i = 0; i < 1000; i++)
	{
		std::find(nums.begin(), nums.end(), 5);
	}
}

void FindByDeque()
{
	std::deque<int> nums;

	for (int i = 10; i > 0; i--)
	{
		nums.push_back(i);
	}

	for (auto num : nums)
	{
		std::cout << num << " ";
	}

	for (int i = 0; i < 1000; i++) 
	{
		std::find(nums.begin(), nums.end(), 5);
	}
	
}

void FindBySet() // set�� insert�� �ڵ� ������ �ش�. ���� �����̳�
{
	std::set<int> nums;
	
	for (int i = 10; i > 0; i--) {
		nums.insert(i);
	}

	nums.insert(50);
	nums.insert(100);

	nums.insert(1); // set�� �ߺ��� ���� ������ �ʴ´�

	for (auto num : nums)
	{
		std::cout << num << " ";
	}

	for (int i = 0; i < 1000; i++)
	{
		nums.find(i);
	}

}

void Test3()
{
	std::cout << "�����͸� �˻��ϴ� �ð� ��" << std::endl;
	std::cout << "vector�� �ð� : ";
	ConsoleUtil::TimeCheck(FindByVector);
	std::cout << "list�� �ð� : ";
	ConsoleUtil::TimeCheck(FindByList);
	std::cout << "deque�� �ð� : ";
	ConsoleUtil::TimeCheck(FindByDeque);
	std::cout << "set�� �ð� : ";
	ConsoleUtil::TimeCheck(FindBySet);
	// deque�� ù��° Ȥ�� ������ ���Ҹ� �ִ� ��쿡 ����������.
	std::cout << "��� : ���� �����̳ʴ� �����͸� �Է��ϴµ� ������." << std::endl;
	std::cout << "���� �����̳ʴ� ��ü������ �����͸� �Է��ϴ� ������ �����ϱ� ������ �ð��� �� �ɸ���." << std::endl;
	std::cout << "�����͸� ���������� �Է��ϴ� ��찡 �ƴϸ鼭, ���� �����͸� �˻��ؾ� �� �� ����Ѵ�." << std::endl;
	std::cout << std::endl;
}

#pragma endregion


int main()
{
	Test1();
	Test2();
	Test2_2();
	Test2_3();

	std::cout << std::boolalpha;
	std::cout << "boolalpha�� ���" << std::endl;
	std::cout << Find(10);
	std::cout << std::endl;
	std::cout << std::endl;

	Test3();

	FindByVector();
	std::cout << std::endl;
	FindByList();
	std::cout << std::endl;
	FindByDeque();
	std::cout << std::endl;
	FindBySet();
	std::cout << std::endl;

}