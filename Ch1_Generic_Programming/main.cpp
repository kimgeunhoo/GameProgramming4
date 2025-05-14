/*
	�ڷ� ����
	- �Ϲ�ȭ ���α׷���(Generic Programming)
	- �Ϲ����̴�? : � Ÿ���̵� ��� ����� �� �ִ� �������� �ڵ� (template ��)
	
	������ T, N, Q ������ ���ε�, ��ǻ�Ͱ� ��� �������� �� �� �ֵ���
	Ű���带 ����ؾ� �Ѵ�.

	���ſ��� ��� �Ϲ�ȭ ���α׷����� ������?
	- macro�� �Ϲ�ȭ ���α׷��� �ۼ��ϴ� ���� �����Ѵ�(����õ)
	- ������ üũ�� �������� �ʴ´�.

*/

/*
	Legacy �ڵ带 �а�, ���� �ڵ����� ������ �� �ִ� ��
	����1. �ǵ����� ���� ����� �߻��� �� �ִ�.
	����2. ������ üũ�� �������� �ʴ´�
*/

/*
	������ Ÿ��(compile time) : �������ϴ� ����. ��ǻ�Ͱ� �� �����ؼ� �����ϴ� ����. ������ �����ϴ� �ܰ踦 ��ģ��.
	��Ÿ��     (run time)	  : ���α׷��� �����ϴ� ����. 
*/

/*
	template Ű����
	<Type���� ������ �̸�>
	Ÿ�� ��ü�� �޾ƿ��� Ű���� : typename, class <- ��ü�� class �ƴ� typename ���Ұ� ����
*/

/*
	Ÿ�� �߷� : �����Ϸ� �� �� �ڵ带 ����, ��õ��� ���� Ÿ���� �����ϴ� ��

	auto �̸� = 10;
*/

/*
	������ �Լ� ���� template Ű���带 ����Ͽ� �Ϲ�ȭ �Լ�
	�Լ� template

	Ŭ���� ���� template< > ����Ͽ� �Ϲ�ȭ Ŭ����
	���ø� Ŭ����

	�ڷ� ����. STL
	���ø� Ŭ������ �����Ǿ� �ִ�.
*/

#define Max(a,b) ( (a>b) ? a:b );
#define Square(a) a * a;
#include <iostream>
#include <array>					// #include <�����̳� �̸�>
//include <vector>

#pragma region ���� �ڵ�
#pragma endregion
template<typename T1>

T1 MaxFunc(T1 a, T1 b) 
{
	return (a > b) ? a : b;
}

template<typename T1, typename T2>
void Func(T1 a, T2 b) 
{
	std::cout << "No." << a << " " << b << std::endl;
}

template<int N>
void Func2()
{
	std::cout << N << std::endl;
}

template<int N, typename T>
void Func3()
{
	for (int i = 0; i < N; i++)
	{
		std::cout << typeid(T).name() << std::endl;
	}
}

template <class T>
T Min(T a, T b)
{
	return a < b ? a : b;
}

template <class T>
T Multiply(T a, T b)
{
	return a * b;
}

struct person
{
	int age;
	std::string name;

	bool operator<(const person& other)
	{
		return this->age < other.age;
	}
};

struct Pokemon
{
	int age;
	std::string name;

};

// int sums[10]; sums[0]

// �츮�� ���� ���� person Ŭ������ �����ϴ� ��ü�� �������.
// person�� �����ϴ� �Լ����� ������ �ڵ��̴�.
// ���������� ����ϴ� �����͸� �ٷ�� Ŭ�����̴�.
// Standard Template Library

// class �⺻������ private �ʵ忡 ����
// struct �⺻������ public �ʵ忡 ����

// person�� ���� �迭�� �䳻�� Ŭ����
template<int N>
class People //
{
private:
	int size = N;			// N�� ũ�⸦ �Ϲ�ȭ�ϰ� �ʹ�.
	person HumanInCity[N];

	// ������ �����ε��� ���ؼ� �迭 ��� �䳻������
public:
	person& operator[](int index)
	{
		return HumanInCity[index];
	}

	void at(int index) 
	{
		// person �迭�� n��° �����ϴ� ��� �Լ�
		std::cout << "����: " << HumanInCity[index].age << " "
			<< "�̸� : " << HumanInCity[index].name << std::endl;
	}
};

template<int N, typename T>
class Array
{
private:
	int size = N;
	T value[N];
public:
	// ������ �����ε�
	T& operator[](int index)
	{
		return value[index];
	}

	T& at(int index)
	{
		return value[index];
	}
};

/*
	Min �Լ�. 

	Multiply �Լ�
*/

/*
	�ڷ� �������� �����ؾ� �� �� : �ڵ带 �ۼ��� �� ���� ȿ������ �ڷᱸ���� �����ΰ�?
	������ ����,
	�����͸� ����, '�迭' - ũ�Ⱑ �����Ǿ� �ִ� �����̳�
	�����̳� ���� ������� �����Ѵ�.

	�迭�� ������ ����
	Ư¡ : ũ�Ⱑ �����Ǿ� �ִ�.
	���� : ������ �ִ� ��Ģ�� ���������� ������ �� �ִ�. ������
	���� : �迭�� ũ�⸦ ������ �� ��� ����� ũ��. ��Ƽ 4��, ���̵� 8��,
	��ų 4�� QWER

	ũ�⸦ ������ų �� ����? ������ų ���� �ִ�.

	���ϸ� 4�� �迭
	1200�� �迭�� �ٽ� �����. -> 1000�� �迭 1200�� �迭�� �ű�� -> 4�� �迭�� �����Ѵ�.

	vector

*/
void Ex1()
{
	int result1 = Max(5, 1);// ((5>1)?5:1)
	double result2 = Max(1.1, 2.2); // ((1.1>2.2)?1.1:2.2)
	int result3 = 100 / Square(5); // 100 / 5 * 5

	std::cout << result1 << std::endl;
	std::cout << result2 << std::endl;
	std::cout << result3 << std::endl;

	std::cout << MaxFunc<int>(1.2, 2.4) << std::endl;
	std::cout << MaxFunc<double>(1.2, 2.4) << std::endl;

	// Ÿ�� �߷�: <> ������. �Ϻ��ϰ� �۵����� ����
	std::cout << MaxFunc(1.2, 2.4) << std::endl;
	std::cout << MaxFunc(0.1, 0.2) << std::endl;

	int select = 0;

	if (select == 0)
	{

	}

	Func<int, std::string>(1, "��ī��");

	Func2<155>();

	Func3<2, int>();

	std::cout << "Min ����" << std::endl;
	std::cout << Min(1.1, 2.4) << std::endl;
	std::cout << Min(1, 2) << std::endl;
	std::cout << Min('a', 'd') << std::endl;

	std::cout << "Multiply ����" << std::endl;
	std::cout << Multiply(1, 5) << std::endl;
	std::cout << Multiply(3, 2) << std::endl;

	Func3<3, int>();
}

int main()
{
	Ex1(); // �Լ� ���ø� ����

	// ���� ����
	person p1{ 10, "A"};
	person p2{ 20, "B" };

	person p3 = Min<person>(p1, p2);

	std::cout << p3.name << " ���̰� �� ���." << std::endl;

	People<5> busan;
	busan[0] = { 15, "�̼���" };
	busan.at(0);
	busan[1] = { 20, "������" };
	busan.at(1);

	std::cout << "���� ���� �迭 Ŭ���� ����" << std::endl;

	Array<5, person> seoul;
	seoul[0] = { 13, "�庸��" };
	seoul.at(1) = { 15, "���ָ�" };

	std::cout << seoul[0].name << std::endl;
	std::cout << seoul[1].name << std::endl;

	// �迭 Ŭ���� ������ ����
	std::cout << seoul.at(0).name << std::endl;
	std::cout << seoul.at(1).name << std::endl;

	Array<10, Pokemon> MyPokemons;
	MyPokemons[0] = {1, "�̻��ؾ�" };
	std::cout << MyPokemons.at(0).name << std::endl;

	//MyPokemons[11]; // out of range

	// STL�� ��ϵǾ� �ִ� �迭 Ŭ������ ����ϼ���.

	std::array<Pokemon, 10> MPokemons;
	MPokemons[0] = { 1, "�̻��ؾ�" };
	MPokemons.at(1) = {25, "��ī��"};
	std::cout << MPokemons.at(0).name << std::endl;
	std::cout << MPokemons.at(1).name << std::endl;


}