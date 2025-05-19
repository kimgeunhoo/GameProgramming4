#pragma once
/*
	벡터(가변 배열)의 특징
	- 길이가 변할 수 있다. 동적 크기 변환이 가능하다.
	- 자동으로 크기가 변경된다.


	int arr[20];
*/

/*
	int size크기;
	int capacity수용량;

	int arr = new int[5]; 수용량 5개 size0 capacity 5.
	size 6 int[6];
	arr = new int[10];

	resize();
	int size, capacity;

*/

// auto R = vector<int>;
// std::vector<int>::iterator << 너무 길 때, 등호 뒤 타입을 추론하는 auto 사용, auto AA 다만 위험성 있음


// value에 해당하는 타입을 T로 바꿔보시오
template<typename T> // int, double, string 타입 자료형 통합 제공
class MyVector 
{
private:	
	int size;		// 1 O double 1.1 X
	int capacity;	// 4.4 X 4 O
	T* vec;			// double* int* std::string* O

public:
	// 생성자
	MyVector() = default;
	MyVector(int startSize)
	{
		vec = new T[startSize];
		size = 0;
		capacity = startSize;
	}
	// 소멸자
	~MyVector()
	{
		delete[] vec; // 배열 소멸은 delete 뒤 대괄호 하고 
	}

	T& operator[](int idx) // vec [1.1] X
	{
		return vec[idx];
	}
	void resize(int nsize)
	{
		// size : 현재 배열에 들어있는 원소의 숙자
		// nsize : 변경하려는 사이즈의 크기

		// 원소의 갯수를 재정의
		if (size < nsize)
		{
			size = size;
		}
		else 
		{
			size = nsize;
		}
		/*capacity 어떻게 변경?*/
		capacity = nsize;

		T* arr = new T[nsize];

		// vec[0], vec[1] .... size
		for (int i = 0; i < size; i++) 
		{
			arr[i] = vec[i];
		}
		delete[] vec;	// 기존에 vec 가리키고 있는 공간을 메모리 해제한다.
		vec = arr;		// vec가 새로운 공간을 가리킨다.
		//delete arr[]; 조심할것

		//vec = new int[nsize]; 

	}
	void push_back(const T& element)	// vec.push_back(6)
	{
		// capacity <= size
		if (capacity <= size) 
		{
			capacity = capacity * 2;	// 
			resize(capacity);
		}

		vec[size] = element;
		size++;
	}
	void pop_back() 
	{
		size = size > 0 ? size - 1 : 0;
	}
	int Size() { return size; }
};

void test1()
{
	while (true)
	{
		MyVector<int>* myVec = new MyVector<int>(10);
		delete myVec;
	}
}

#include <iostream>

void test2()
{
	MyVector<int> vec(5);
	MyVector<double> vec2(5);

	for (int i = 0; i < 5; i++)
	{
		vec.push_back(i+1);

		std::cout << vec[i] << std::endl;
	}
	for (int i = 0; i < 5; i++)
	{
		vec2.push_back(i + 0.1);

		std::cout << vec2[i] << std::endl;
	}

	vec.push_back(6);

	for (int i = 0; i < vec.Size(); i++)
	{
		std::cout << vec[i] << " ";
	}
}