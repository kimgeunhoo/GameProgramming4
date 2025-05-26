#pragma once

#include <iostream>
#include <chrono>
#include <vector>
#include <list>

/*
	vector�� list�� ������

	1. ������ �����Ϳ� �����ϴ� �ð��� ���Ѵ�.

	���: vector�� �ٷ� ������ �����Ϳ� ������ �� �ִ�. ������ (0(1))
		List�� n��° �����Ϳ� �����ϴ� �� ���̿� ���ؼ�	�ð��� ���� �ɸ���. (liner)

	2. ù ��°�� ���� �����Ͱ� �ƴ� �����͸� ���� �Ǵ� �����ϴ� �� �ɸ��� �ð�
	- �����͸� ���� ���� �Ǵ� �����ϴ� ��쿡 vector�� �ð��� ��ȿ�����̴�.
	- 1 - N ������ -> 1 ~ N -1�� ������ �ű�� �۾�

	�����͸� ����ų� ������ �� �۾��� ������ �������� vector�� �ð��� ��ȿ�����̴�.

*/

/*
	(����) � �ڷᱸ���� ����� �� �� �𸣰����� vector�� ���
	vector ������ ���� �� �ð��� �� ���� �ɸ���?
*/

void TimeCheckTest()
{
	std::cout << "Ư�� ����� �󸶳� �ɸ����� �����ϴ� �ڵ�" << std::endl;

	auto Start = std::chrono::high_resolution_clock::now();
	//
	std::vector<int> nums;
	
	for (int i = 0; i < 1000000; i++)
	{
		nums.push_back(i);
	}

	for (int i = 0; i < 10000; i++) {
		auto it = nums.begin() + 50000;
		nums.erase(it);
	}
	
	//auto it2 = std::next(nums.begin() + 500);

	
	//
	auto End = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> duration = End - Start;

	std::cout << duration.count() << " ms" << std::endl;
}

void TimeCheckTest2()
{
	std::cout << "STL list�� �ð��� �����Ѵ�" << std::endl;

	auto Start = std::chrono::high_resolution_clock::now();
	//
	std::list<int> nums;
	
	for (int i = 0; i < 1000000; i++)
	{
		nums.push_back(i);
	}

	for (int i = 0; i < 10000; i++) {
		auto it = std::next(nums.begin(), 500);
		nums.erase(it);
	}

	

	//
	auto End = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> duration = End - Start;

	std::cout << duration.count() << " ms" << std::endl;
}