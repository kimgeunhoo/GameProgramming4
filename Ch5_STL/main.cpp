#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <algorithm> // 90�� ������ �Լ��� �����Ǿ� �ִ�.
#include "algo.h"

/*
	int Ÿ���� �����͸� �����ϴ� vector Ŭ������ ����
	1,2,3,4,5 �����غ���

*/

/*
	iterator (�ݺ���)
	������ ������ �ϴ� Ŭ����
	�ڷᱸ��::iterator
*/

/*
	iterator�� ����ؼ� �ڷᱸ���� element�� ����� �� �ִ�.
	begin(), cbegin(), rbegin(), crbegin()
	end()  , cend()  , rend()  , crend()
*/

//iterator�� �⺻ ����
void test1()
{
	std::vector<int> nums = { 1,2,3,4,5 };
	std::list<int> intlist = { 2,4,6,8,10 };
	std::vector<int>::iterator it = nums.begin(); // begin�� vector �迭�� ������

	std::cout << "iterator Ȱ���� �ڷᱸ�� ��ü ������ ���" << std::endl;
	while (it != nums.end())  // vector.end
	{
		std::cout << *it << " "; // iterator ����� �ּ��� ���� �������ؼ� ���


		it++;
	}
	std::cout << std::endl;

	std::cout << "for �ݺ��� Ȱ���� �ڷᱸ�� ��ü ������ ���" << std::endl;
	for (int i = 0; i < nums.size(); i++)
	{
		std::cout << nums[i] << " ";
	}
	std::cout << std::endl;
	// vector�� �ƴ� �ٸ� �ڷ� �������� ����Ʈ�� ��ȭ, ���
	std::list<int>::iterator it2 = intlist.begin();

	std::cout << "list Ȱ���� �ڷᱸ�� ��ü ������ ���" << std::endl;
	while (it2 != intlist.end())
	{
		std::cout << *it2 << " ";
		it2++;
	}
}

//�������� ����ϴ� ���
void test2()
{
	std::cout << "\n============================================================" << std::endl;
	std::vector<int> vec = { 1,2,3,4,5,6,7,8,9 };
	//std::vector<int>::reverse_iterator it = vec.rbegin();
	auto it = vec.rbegin(); // auto�� �տ� �� �ڵ带 �߷�, 

	while (it != vec.rend())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;

	std::list<int> lis = { 2,4,5,6,7,8,9 };
	//std::list<int>::reverse_iterator it2 = lis.rbegin();
	auto it2 = lis.rbegin();
	std::cout << "list�� �������� ���" << std::endl;
	while (it2 != lis.rend())
	{
		std::cout << *it2 << " ";
		it2++;
	}
}

//auto Ű����
void test3()
{
	std::cout << "\n=======================================" << std::endl;

	//���� 1
	auto x = 5;
	
	//���� 2 ���� ����ϸ� ����? Ÿ�� �̸��� �ſ� �� ������.
	std::vector<int> nums = { 1,2,3,4,5 };
	auto it = nums.rbegin();

	//int score = 1.1 * 10 + 1.23 * 200;
	// ������ ���� : ���� ������ �����ʿ� ���� value ��Ư���� �������϶� ����� X

	// ����3.

	// ������ �ڷ����� �ſ� ���� ��.

	/*
		auto		:	int, double, primitive type ����� �� ���ϰ� ��� (�����ؼ� ����� ����.)
		auto&		:	�޸𸮿� �����ؼ� �����͸� ������ �� �ִ�.
		const auto& :	�޸𸮿� �����͸� ���������� �������� ���ϰ� �Ѵ�.
	*/

	for (const auto& num : nums)
	{
		std::cout << num << " ";
	}
	
	for (auto& i : nums)
	{
		i = 0;
	}

	for (auto num : nums)
	{
		std::cout << num << " ";
	}

}

// ��� iterator
// 

void test4()
{
	std::cout << "\n============================================================" << std::endl;
	std::vector<int> vec = { 1,2,3,4,5,6,7,8,9 };

	//std::vector<int>::const_iterator it = vec.cbegin();
	auto it = vec.cbegin();// const Ÿ���� begin

	while (it != vec.cend())
	{
		std::cout << *it << " ";
		it++;
	}

}

// iterator ���뿹��
void test5()
{
	std::cout << "\n============================================================" << std::endl;
	std::vector<int> vec = { 1,2,3,4,5,6,7,8,9 };

	auto start = vec.begin() + 2; // 3��° element���� ����Ű�� �ȴ�.
	auto finish = vec.end() - 3;  // 

	while (start != finish)
	{
		std::cout << *start << " ";
		start++;
	}
}

int main() 
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();

	//find_test();
	//find_test2();
	//each_of_test();
	all_of_test();
}