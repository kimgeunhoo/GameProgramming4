/*
	adapt �����̳�
	(Vector, list, Deque) ������� Ư���� �����̳�

	stack, queuem, priority_queue
	����, ť, �켱���� ť
*/

#include <iostream>

#pragma region ����
/*
	�޸� ���� LIFO �̴�. Last In First Out
	�����͸� ����ϴ� ��Ģ�� �����ϴ� ������ ȿ���� ��� �ڷᱸ���̴�.
	Iterator �������� �ʴ´� ( ���������� iterator Ŭ���� ����. )
	Ctrl + z (History - Ư�� ��ġ�� ���ư� �� �ִ�.)
*/
#include <stack>

void Test1() {
	std::cout << "���� ��� ����" << std::endl;

	std::stack<int> nums;

	for (int i = 0; i < 10; ++i) {
		nums.push(i); 
	}

	std::cout << "nums�� ������ ���" << std::endl;
	//stack�� iterator�� �������� �ʴ´�. ���� ��� for loop ��� �Ұ�
	//for (const auto& num : nums) {
	//	std::cout << num << " "; // 
	//}
	
	while (!nums.empty()) // �ڷᱸ���� ������� ���� �� �ݺ�
	{ 
		std::cout << nums.top() << " "; // top �� ���� �����͸� ����϶�.
		nums.pop();						// top�� �����͸� �����϶�.
	}
	// size() = nums�� �ִ밪�� ��ȯ

	/*for(int i = 0; i < nums.size(); ++i) 
	{
		std::cout << nums.top() << " "; 
		nums.pop(); // size -1
	}*/
}

#pragma endregion

#include <queue>

#pragma region ť
/*
	�޸� ���� FIFO �̴�. First In First Out
*/

void Test2() {
	std::cout << "\n\nť ��� ����" << std::endl;

	std::queue<int> nums;

	for (int i = 0; i < 10; ++i) {
		nums.push(i);
	}

	std::cout << "nums�� ������ ���" << std::endl;

	while (!nums.empty()) // �ڷᱸ���� ������� ���� �� �ݺ�
	{
		std::cout << nums.front() << " "; // top �� ���� �����͸� ����϶�.
		nums.pop();						  // top�� �����͸� �����϶�.
	}
}

#pragma endregion

#pragma region �켱���� ť

// ť : ���� ������� ������.(x) ���� ������ �� ����� ���� ������..
// ���, �Ϲ� �ʴ��, Ư�� �ʴ��
// �ð�, ��
// �� �Ȱ��� �ð��� ���� ��, 

// #incldue <queue> ���ԵǾ� �ִ�.
// heap �˰������� �����Ǿ� �ִ�. ���� ����(ū) �� Ʈ�� ������ �� ���� ������ ����.
// heapify

void Test3() {
	std::cout << "\n\n�켱 ���� ť ��� ����" << std::endl;

	std::priority_queue<int> nums;

	nums.push(0);
	nums.push(5);
	nums.push(7);
	nums.push(3);
	nums.push(9);


	std::cout << "nums�� ������ ���" << std::endl;

	while (!nums.empty()) // �ڷᱸ���� ������� ���� �� �ݺ�
	{
		std::cout << nums.top() << " "; // top �� ���� �����͸� ����϶�.
		nums.pop();						  // top�� �����͸� �����϶�.
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
	// queue�� ��� ����� ����
	// vector �̿��ؼ� queue ����� ���

	std::cout << "\n\n���� ���� ť ��� ����" << std::endl;
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
	std::cout << "\n\n ���� ���� ���� ��� ����" << std::endl;

	MyStack<int> nums;

	for (int i = 0; i < 10; ++i) {
		nums.push(i);
	}

	std::cout << "nums�� ������ ���" << std::endl;
	//stack�� iterator�� �������� �ʴ´�. ���� ��� for loop ��� �Ұ�
	//for (const auto& num : nums) {
	//	std::cout << num << " "; // 
	//}
	while (!nums.empty()) // �ڷᱸ���� ������� ���� �� �ݺ�
	{
		std::cout << nums.top() << " "; // top �� ���� �����͸� ����϶�.
		nums.pop();						// top�� �����͸� �����϶�.
	}
	
}

int main() {
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
}

