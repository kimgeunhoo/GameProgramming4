#pragma once

#include <iostream>

/*
	1. �Լ� ���� ( (��ȯ��)(*ȣ���� �Լ� �̸�)() )
	2. ȣ���� �Լ��� ���ڰ� �ִ� ���
	�Լ� ���� ( (��ȯ��)(*ȣ���� �Լ� �̸�)(����) )
*/

void Add(int a, int b)
{
	std::cout << "���ϱ� ����" << std::endl;
	std::cout << a + b << std::endl;
}

void Minus(int a, int b)
{
	std::cout << "���� ����" << std::endl;
	std::cout << a - b << std::endl;
}

void Multiply(int a, int b)
{
	std::cout << "���ϱ� ����" << std::endl;
	std::cout << a * b << std::endl;
}

void Division(int a, int b)
{
	if (b == 0)
	{
		return;
	}
	std::cout << "������ ����" << std::endl;
	std::cout << a / b << std::endl;
}

// ���ϱ� ������ �߰�

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