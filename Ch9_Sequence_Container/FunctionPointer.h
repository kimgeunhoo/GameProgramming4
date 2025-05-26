#pragma once

#include <iostream>

/*
	1. 함수 선언 ( (반환값)(*호출할 함수 이름)() )
	2. 호출할 함수의 인자가 있는 경우
	함수 선언 ( (반환값)(*호출할 함수 이름)(인자) )
*/

void Add(int a, int b)
{
	std::cout << "더하기 실행" << std::endl;
	std::cout << a + b << std::endl;
}

void Minus(int a, int b)
{
	std::cout << "빼기 실행" << std::endl;
	std::cout << a - b << std::endl;
}

void Multiply(int a, int b)
{
	std::cout << "곱하기 실행" << std::endl;
	std::cout << a * b << std::endl;
}

void Division(int a, int b)
{
	if (b == 0)
	{
		return;
	}
	std::cout << "나누기 실행" << std::endl;
	std::cout << a / b << std::endl;
}

// 곱하기 나누기 추가

void Calculate(void(*Func)(int a, int b), int a, int b)
{
	Func(a,b);
}

void Test() {
	Calculate(Add, 150, 70);
	Calculate(Minus, 150, 70);
	Calculate(Multiply, 10, 9);
	Calculate(Division, 140, 7);
}