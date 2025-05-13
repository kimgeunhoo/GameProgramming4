/*
	자료구조 (Data Stutcure)

	Data	  : 게임에 등장하는 정보 컴퓨터가 해석할 수 있도록 작성한 것
	Structure : 구조, 설계 - 생산성, 안전성

	데이터를 설계해야 하는 이유?
	STL ( Standard Templete Library )
	표준	   : 신용할 수 있다. 대중적으로 많이 사용한다.
	템플릿	   : 일반화 프로그래밍을 구현하기 위한 문법
	라이브러리 : 만들어진 함수, 클래스

	컨테이너 : 특정한 목적에 따라 모아놓은 클래스
	알고리즘 : 컨테이너 안에 있는 데이터를 사용하는 함수 라이브러리
	반복자 : 알고리즘 코드를 용이하게 사용하기 위한 문법
*/

/*
	array, vector, list, stack, queue, priority queue, hash-set, map 
	어떤 경우에 무엇을 사용해야 하는가?
	- 왜 이 코드에서 이 자료구조를 사용했나요? << 
*/

#include <iostream>
#include <vector>	
#include <algorithm> 
#include "Template.h"
#include "Sample.h"
using namespace std; // std 지워도 됨

int main() 
{
	cout << "자료구조 예제" << endl;
	
	std::vector<int> nums = {1, 5, 3, 10, 2 ,4}; // 정수형 데이터 3개 저장하고 있는 'nums' vector

	// 데이터 출력 1. 1, 5, 3
	cout << "데이터 출력 1" << endl;
	for (auto& num : nums) // 반복자. 'nums' 안에 있는 데이터 타입 개별 요소들 모두를 실행하라
	{
		cout << num << " ";
	}
	cout << endl;

	std::sort(nums.begin(), nums.end()); // 데이터를 정렬한다.
	
	// 데이터 출력 2. 1, 3, 5
	cout << "데이터 출력 2" << endl;
	for (auto& num : nums) // 반복자. 'nums' 안에 있는 데이터 타입 개별 요소들 모두를 실행하라
	{
		cout << num << " ";
	}
	cout << endl;

	cout << "템플릿 예제" << endl;;

	// 타입 유추 

	int num = Add<int>(2, 5);
	cout << num << endl;

	int num1 = Add(1, 4); // template 설정해서, 묵시적으로 int로 설정, 다른 형태도 마찬가지
	double num2 = Add(1.5, 4.2);
	char num3 = Add('A', '1');
	cout << num1 << endl;
	cout << num2 << endl;
	cout << num3 << endl;

	Example1();
}