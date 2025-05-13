/*
	�ڷᱸ�� (Data Stutcure)

	Data	  : ���ӿ� �����ϴ� ���� ��ǻ�Ͱ� �ؼ��� �� �ֵ��� �ۼ��� ��
	Structure : ����, ���� - ���꼺, ������

	�����͸� �����ؾ� �ϴ� ����?
	STL ( Standard Templete Library )
	ǥ��	   : �ſ��� �� �ִ�. ���������� ���� ����Ѵ�.
	���ø�	   : �Ϲ�ȭ ���α׷����� �����ϱ� ���� ����
	���̺귯�� : ������� �Լ�, Ŭ����

	�����̳� : Ư���� ������ ���� ��Ƴ��� Ŭ����
	�˰��� : �����̳� �ȿ� �ִ� �����͸� ����ϴ� �Լ� ���̺귯��
	�ݺ��� : �˰��� �ڵ带 �����ϰ� ����ϱ� ���� ����
*/

/*
	array, vector, list, stack, queue, priority queue, hash-set, map 
	� ��쿡 ������ ����ؾ� �ϴ°�?
	- �� �� �ڵ忡�� �� �ڷᱸ���� ����߳���? << 
*/

#include <iostream>
#include <vector>	
#include <algorithm> 
#include "Template.h"
#include "Sample.h"
using namespace std; // std ������ ��

int main() 
{
	cout << "�ڷᱸ�� ����" << endl;
	
	std::vector<int> nums = {1, 5, 3, 10, 2 ,4}; // ������ ������ 3�� �����ϰ� �ִ� 'nums' vector

	// ������ ��� 1. 1, 5, 3
	cout << "������ ��� 1" << endl;
	for (auto& num : nums) // �ݺ���. 'nums' �ȿ� �ִ� ������ Ÿ�� ���� ��ҵ� ��θ� �����϶�
	{
		cout << num << " ";
	}
	cout << endl;

	std::sort(nums.begin(), nums.end()); // �����͸� �����Ѵ�.
	
	// ������ ��� 2. 1, 3, 5
	cout << "������ ��� 2" << endl;
	for (auto& num : nums) // �ݺ���. 'nums' �ȿ� �ִ� ������ Ÿ�� ���� ��ҵ� ��θ� �����϶�
	{
		cout << num << " ";
	}
	cout << endl;

	cout << "���ø� ����" << endl;;

	// Ÿ�� ���� 

	int num = Add<int>(2, 5);
	cout << num << endl;

	int num1 = Add(1, 4); // template �����ؼ�, ���������� int�� ����, �ٸ� ���µ� ��������
	double num2 = Add(1.5, 4.2);
	char num3 = Add('A', '1');
	cout << num1 << endl;
	cout << num2 << endl;
	cout << num3 << endl;

	Example1();
}