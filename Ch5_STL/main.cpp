#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <algorithm> // 90개 정도의 함수가 구현되어 있다.
#include "algo.h"

/*
	int 타입의 데이터를 저장하는 vector 클래스를 만들어서
	1,2,3,4,5 저장해보기

*/

/*
	iterator (반복기)
	포인터 역할을 하는 클래스
	자료구조::iterator
*/

/*
	iterator를 사용해서 자료구조의 element를 출력할 수 있다.
	begin(), cbegin(), rbegin(), crbegin()
	end()  , cend()  , rend()  , crend()
*/

//iterator의 기본 사용법
void test1()
{
	std::vector<int> nums = { 1,2,3,4,5 };
	std::list<int> intlist = { 2,4,6,8,10 };
	std::vector<int>::iterator it = nums.begin(); // begin은 vector 배열의 시작점

	std::cout << "iterator 활용한 자료구조 전체 데이터 출력" << std::endl;
	while (it != nums.end())  // vector.end
	{
		std::cout << *it << " "; // iterator 저장된 주소의 값을 역참조해서 출력


		it++;
	}
	std::cout << std::endl;

	std::cout << "for 반복을 활용한 자료구조 전체 데이터 출력" << std::endl;
	for (int i = 0; i < nums.size(); i++)
	{
		std::cout << nums[i] << " ";
	}
	std::cout << std::endl;
	// vector가 아닌 다른 자료 구조에서 데이트를 순화, 사용
	std::list<int>::iterator it2 = intlist.begin();

	std::cout << "list 활용한 자료구조 전체 데이터 출력" << std::endl;
	while (it2 != intlist.end())
	{
		std::cout << *it2 << " ";
		it2++;
	}
}

//역순으로 출력하는 방법
void test2()
{
	std::cout << "\n============================================================" << std::endl;
	std::vector<int> vec = { 1,2,3,4,5,6,7,8,9 };
	//std::vector<int>::reverse_iterator it = vec.rbegin();
	auto it = vec.rbegin(); // auto는 앞에 올 코드를 추론, 

	while (it != vec.rend())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;

	std::list<int> lis = { 2,4,5,6,7,8,9 };
	//std::list<int>::reverse_iterator it2 = lis.rbegin();
	auto it2 = lis.rbegin();
	std::cout << "list를 역순으로 출력" << std::endl;
	while (it2 != lis.rend())
	{
		std::cout << *it2 << " ";
		it2++;
	}
}

//auto 키워드
void test3()
{
	std::cout << "\n=======================================" << std::endl;

	//예시 1
	auto x = 5;
	
	//예시 2 언제 사용하면 좋나? 타입 이름이 매우 긴 예제들.
	std::vector<int> nums = { 1,2,3,4,5 };
	auto it = nums.rbegin();

	//int score = 1.1 * 10 + 1.23 * 200;
	// 주의할 사항 : 대입 연산자 오른쪽에 오는 value 불특정한 데이터일때 사용을 X

	// 예시3.

	// 데이터 자료형이 매우 작을 때.

	/*
		auto		:	int, double, primitive type 사용할 때 편하게 사용 (복사해서 만들어 진다.)
		auto&		:	메모리에 접근해서 데이터를 변경할 수 있다.
		const auto& :	메모리에 데이터를 문법적으로 변경하지 못하게 한다.
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

// 상수 iterator
// 

void test4()
{
	std::cout << "\n============================================================" << std::endl;
	std::vector<int> vec = { 1,2,3,4,5,6,7,8,9 };

	//std::vector<int>::const_iterator it = vec.cbegin();
	auto it = vec.cbegin();// const 타입의 begin

	while (it != vec.cend())
	{
		std::cout << *it << " ";
		it++;
	}

}

// iterator 응용예시
void test5()
{
	std::cout << "\n============================================================" << std::endl;
	std::vector<int> vec = { 1,2,3,4,5,6,7,8,9 };

	auto start = vec.begin() + 2; // 3번째 element부터 가리키게 된다.
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