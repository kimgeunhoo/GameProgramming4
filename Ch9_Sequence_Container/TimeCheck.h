#pragma once

#include <iostream>
#include <chrono>
#include <vector>
#include <list>

/*
	vector와 list의 차이점

	1. 임의의 데이터에 접근하는 시간을 비교한다.

	결과: vector는 바로 임의의 데이터에 접근할 수 있다. 빠르다 (0(1))
		List는 n번째 데이터에 접근하는 데 길이에 비해서	시간이 오래 걸린다. (liner)

	2. 첫 번째와 끝의 데이터가 아닌 데이터를 삭제 또는 수정하는 데 걸리는 시간
	- 데이터를 자주 삭제 또는 수정하는 경우에 vector의 시간이 비효율적이다.
	- 1 - N 데이터 -> 1 ~ N -1개 대이터 옮기는 작업

	데이터를 지우거나 변경할 때 작업이 많으면 많을수록 vector는 시간이 비효율적이다.

*/

/*
	(번외) 어떤 자료구조를 써야할 지 잘 모르겟으면 vector를 사용
	vector 무엇을 했을 때 시간이 더 오래 걸리나?
*/

void TimeCheckTest()
{
	std::cout << "특정 기능이 얼마나 걸리는지 측정하는 코드" << std::endl;

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
	std::cout << "STL list의 시간을 측정한다" << std::endl;

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