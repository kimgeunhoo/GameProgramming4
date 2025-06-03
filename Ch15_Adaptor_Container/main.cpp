/*
	adapt 컨테이너
	(Vector, list, Deque) 만들어진 특별한 컨테이너

	stack, queuem, priority_queue
	스택, 큐, 우선순위 큐
*/

#include <iostream>

#pragma region 스택
/*
	메모리 구조 LIFO 이다. Last In First Out
	데이터를 사용하는 규칙을 제한하는 것으로 효율을 얻는 자료구조이다.
	Iterator 지원하지 않는다 ( 내부적으로 iterator 클래스 없다. )
	Ctrl + z (History - 특정 위치로 돌아갈 수 있다.)
*/
#include <stack>

void Test1() {
	std::cout << "스택 사용 예시" << std::endl;

	std::stack<int> nums;

	for (int i = 0; i < 10; ++i) {
		nums.push(i); 
	}

	std::cout << "nums의 데이터 출력" << std::endl;
	//stack은 iterator를 지원하지 않는다. 범위 기반 for loop 사용 불가
	//for (const auto& num : nums) {
	//	std::cout << num << " "; // 
	//}
	
	while (!nums.empty()) // 자료구조가 비어있지 않을 때 반복
	{ 
		std::cout << nums.top() << " "; // top 젤 위에 데이터를 출력하라.
		nums.pop();						// top에 데이터를 삭제하라.
	}
	// size() = nums의 최대값을 반환

	/*for(int i = 0; i < nums.size(); ++i) 
	{
		std::cout << nums.top() << " "; 
		nums.pop(); // size -1
	}*/
}

#pragma endregion

#include <queue>

#pragma region 큐
/*
	메모리 구조 FIFO 이다. First In First Out
*/

void Test2() {
	std::cout << "\n\n큐 사용 예시" << std::endl;

	std::queue<int> nums;

	for (int i = 0; i < 10; ++i) {
		nums.push(i);
	}

	std::cout << "nums의 데이터 출력" << std::endl;

	while (!nums.empty()) // 자료구조가 비어있지 않을 때 반복
	{
		std::cout << nums.front() << " "; // top 젤 위에 데이터를 출력하라.
		nums.pop();						  // top에 데이터를 삭제하라.
	}
}

#pragma endregion

#pragma region 우선순위 큐

// 큐 : 들어온 순서대로 나간다.(x) 먼저 나가야 할 사람이 빨리 나간다..
// 사람, 일반 초대권, 특별 초대권
// 시간, 돈
// 다 똑같은 시간에 왔을 때, 

// #incldue <queue> 포함되어 있다.
// heap 알고리즘으로 구현되어 있다. 가장 작은(큰) 값 트리 구조의 맨 위로 보내는 형태.
// heapify

void Test3() {
	std::cout << "\n\n우선 순위 큐 사용 예시" << std::endl;

	std::priority_queue<int> nums;

	nums.push(0);
	nums.push(5);
	nums.push(7);
	nums.push(3);
	nums.push(9);


	std::cout << "nums의 데이터 출력" << std::endl;

	while (!nums.empty()) // 자료구조가 비어있지 않을 때 반복
	{
		std::cout << nums.top() << " "; // top 젤 위에 데이터를 출력하라.
		nums.pop();						  // top에 데이터를 삭제하라.
	}
}

#pragma endregion

#include <vector>
#include <deque>

template <typename T>
class MuQueue
{
private:
	int _size;
	std::deque<T> data;

public:
	MuQueue() : _size(0) {}

	void push(T& e) 
	{
		_size++;
		data.push_back(e);
	}
	T front()
	{
		return data[0];
	}
	void pop()
	{
		_size--;
		data.pop_front();
	}
	int size()
	{
		return _size;
	}
	bool empty()
	{
		return _size == 0;
	}

};

template <typename T>
class MyStack
{
private:
	int _size;
	std::vector<T> data;
public:
	MyStack() : _size(0) {}

	void push(T& e)
	{
		_size++;
		data.push_back(e);	
	}
	T top()
	{
		return data[_size - 1];
	}
	void pop()
	{
		_size--;
		data.pop_back();
	}
	int size()
	{
		return _size;
	}
	bool empty()
	{
		return _size == 0;
	}
	// push, top, pop, size, empty
};
void Test4() 
{
	// queue가 어떻게 만들어 질까
	// vector 이용해서 queue 만드는 방법

	std::cout << "\n\n직접 만든 큐 사용 예시" << std::endl;
	MuQueue<int> nums;

	for (int i = 0; i < 10; ++i)
	{
		nums.push(i);
	}

	while (!nums.empty()) 
	{
		std::cout << nums.front() << " ";
		nums.pop();
	}
}

void Test5()
{
	std::cout << "\n\n 직접 만든 스택 사용 예시" << std::endl;

	MyStack<int> nums;

	for (int i = 0; i < 10; ++i) {
		nums.push(i);
	}

	std::cout << "nums의 데이터 출력" << std::endl;
	//stack은 iterator를 지원하지 않는다. 범위 기반 for loop 사용 불가
	//for (const auto& num : nums) {
	//	std::cout << num << " "; // 
	//}
	while (!nums.empty()) // 자료구조가 비어있지 않을 때 반복
	{
		std::cout << nums.top() << " "; // top 젤 위에 데이터를 출력하라.
		nums.pop();						// top에 데이터를 삭제하라.
	}
	
}

int main() {
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
}

