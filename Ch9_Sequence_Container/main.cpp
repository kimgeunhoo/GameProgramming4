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
	(목표) Vector, List 의 차이점을 직접 비교

	1. vector push_back() 추가, List push_back() 추가한 시간 비교 결과<> 누가 더 빨랏다. 그 이유는?
	2. 임의의 데이터에 접근하는 데 걸리는 시간		: 결과 vector가 더 빠르다. list 개수가 많아지면 시간이 더 걸린다
	3. 임의의 데이터를 치우는 데 걸리는 시간		: list가 더 빠르다.

	데이터 삭제는 적고 접근이 많을 때: vector 유리
	데이터 삭제가 빈번하다 : list 유리

	(★★★★★) 데이터 삭제도 많고 접근도 많은 경우 : ?? unordered_map

	vector
	unordered_map
*/

/*
	Vector, List 크게 차이점은 없다.
	Vector [ ] 인덱스로 데이터를 출력할 수 있다.
	List   [ ] 인덱스로 접근할 수 없다.				// 배열이 아니면 어떻게 표현하지?

	차이점을 눈으로 확인하기 위해서 환경설정을 진행한다.


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

	std::cout << "임의의 데이터 접근 시간" << std::endl;

//	std::cout << nums[900] << std::endl;

	// erase함수. n번 사용하는 예제

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

	std::cout << "임의의 데이터 접근 시간" << std::endl;

	

	// erase함수. n번 사용하는 예제
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

	// 자료구조 시간 테스트
	//TimeCheckTest();
	//TimeCheckTest2();

	// 함수 포인터 예제
	//Test();

	// ConsoleUtil::TimeCheck() 실행하기.

	ConsoleUtil::TimeCheck(VectorExample);
	ConsoleUtil::TimeCheck(ListExample);

	// double 변환
	//double a1 = ConsoleUtil::TimeCheck(VectorExample);
	
}