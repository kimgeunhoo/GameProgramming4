#pragma once

#include "ConsoleUtility.h"
#include <iostream>

// ����. ���� ���. �Լ� �����ͷ� ǥ���ϱ�

#pragma region ��ȭ(1). �Լ� �����Ϳ� �Ϲ�ȭ ���α׷��� Generic Programming ����

// ��ȭ 1. �Լ� �����Ϳ� �Ϲ�ȭ ���α׷��� Generic Programming ����

template <typename T>
void Plus(T a, T b)
{
	std::cout << "���ϱ� ��� : ";
	std::cout << a + b << std::endl;
}

template <typename T>
void Minus(T a, T b)
{
	std::cout << "���� ��� : ";
	std::cout << a - b << std::endl;
}

template <typename T>
void Multiply(T a, T b)
{
	std::cout << "���� ��� : ";
	std::cout << a * b << std::endl;
}

template <typename T>
void Division(T a, T b)
{
	if (b == 0)
	{
		return;
	}
	else 
	{
		std::cout << "������ ��� : ";
		std::cout << a / b << std::endl;
	}
	
}

template <typename T> // �Լ��� ���ڷ� ���� // �ܺ� ���ڸ� ����
void Calculate(void (*Func)(T a, T b), T outA, T outB)
{
	Func(outA, outB);
}

#pragma endregion

#pragma region ��ȭ(2). �������� Ŭ������ �Լ� ������ Ȱ��

// �������� �̸��� �׻� �빮�ڷ� �ۼ��Ͽ�, �̸����� Ÿ���� �˾ƺ� �� �ְ� �����Ѵ�.
// �Լ��� ù ���ڰ� �빮�ڷ� ǥ���ϰ� �����Ͽ���. << �� �κ��� ������� �ٸ�. C#�� ��ü�� �빮��
enum ActorAction
{
	MOVE, TALK
};

class Actor
{
private:
	static void Move()
	{
		std::cout << "�����Դϴ�." << std::endl;
	}

	static void Talk()
	{
		std::cout << "��ȭ�մϴ�." << std::endl;
	}

public:

	Actor() = default;

	void (*Action)();
	
	void ActionMove()
	{
		Action = Move;
	}

	void ActionTalk()
	{
		Action = Talk;
	}

	void Think()
	{

		// ������ ���ڸ� �޾Ƽ�, 0�� ������ ��������. 1�� ������ Talk, 2�� ������ ..
		int select = ConsoleUtil::GetRandomInt(2); // �׼��� �þ�� �׼� �������� ������ �ȴ�
		// ConsoleUtil���� ������� +1�� �Ǿ� �ֱ⿡ switch ���� select ���� -1�� �ؾ���
		ActorAction aaction = static_cast<ActorAction>(select - 1);

		switch (aaction)
		{
		case MOVE: ActionMove();
			break;
		case TALK: ActionTalk();
			break;
		default:
			std::cout << "�߸��� �Է��� �޾ƿԽ��ϴ�" << std::endl;
			return;
		}
	}

};


#pragma endregion

#pragma region ���������� ���� �����

enum RSP_TYPE
{
	ROCK, SCISSORS, PAPER
};

class RSPGame
{
private:
	static void Rock()
	{
		std::cout << "CP : ���� " << std::endl;
	}
	static void Scissors()
	{
		std::cout << "CP : ���� " << std::endl;
	}
	static void Paper()
	{
		std::cout << "CP : �� " << std::endl;
	}

	RSP_TYPE computertype;
	RSP_TYPE usertype;

	int userScore;
	int computerScore;

	void Result()
	{
		// ���� ��ǻ�� ����: ���

		// ���� > ��ǻ�� �̱�

		// �ƴ϶�� ��
		if (usertype == computertype)
		{
			std::cout << "�����ϴ�." << std::endl;
		}
		else if (usertype == ROCK && computertype == SCISSORS ||
			usertype == SCISSORS && computertype == PAPER ||
			usertype == PAPER && computertype == ROCK)
		{
			std::cout << "�̰���ϴ�." << std::endl;
			userScore += 1;
		}
		else 
		{
			std::cout << "�����ϴ�." << std::endl;
			computerScore += 1;
		}
		std::cout << "���� ���ھ� : " << userScore << " ��ǻ�� ���ھ� : " << computerScore << std::endl;
	}

public:

	RSPGame() : userScore(0), computerScore(0) {}
	// �Լ� ������ ����
	//RSPGame() = default;

	void (*Action)();
	// switch(RSP_TYPE) �� Ÿ�Կ� �°� �Լ��������� �Լ��� �ִ� �ڵ带 ������

	void StartGame()
	{
		std::cout << "���� ���� �� ���� " << std::endl;
		while (true) {
			std::cout << "�ش��ϴ� ���ڸ� �Է��ϼ���. 0_����, 1_����, 2_�� : ";
			int input = 0;
			std::cin >> input;
			std::cout << std::endl;
			usertype = static_cast<RSP_TYPE>(input);

			// ��ǻ�Ͱ� ������ ��ȣ�� �������� �޽��ϴ�.
			int select = ConsoleUtil::GetRandomInt(3);
			computertype = static_cast<RSP_TYPE>(select - 1);
			// swicth���� ����Ѵ�. �Լ������͸� �����Ѵ�.
			switch (computertype)
			{
			case ROCK:
				Action = Rock;
				break;
			case SCISSORS:
				Action = Scissors;
				break;
			case PAPER:
				Action = Paper;
				break;
			default:
				std::cout << "�߸��� �Է��� �޾ƿԽ��ϴ�" << std::endl;
				return;
			}
			Action();
			Result();

			if (userScore >= 3 || computerScore >= 3)
			{
				break;
			}
		}
		// �Լ��������� �Լ��� �����Ѵ�.
		if (userScore == 3)
		{
			std::cout << "������ �¸��Ͽ����ϴ�." << std::endl;
		}
		else 
		{
			std::cout << "��ǻ�Ͱ� �¸��Ͽ����ϴ�." << std::endl;
		}
	}
};

#pragma endregion

void FPTest()
{
	Calculate(Plus, 5, 6);
	Calculate(Plus, 5.6, 6.1);
	Calculate(Minus, 7, 6);
	Calculate(Minus, 7.1, 6.0);
	Calculate(Multiply, 5, 6);
	Calculate(Division, 6, 2);
	Calculate(Division, 6, 0);
}
void FPTest2()
{
	//Actor actor;
	// actor. �ǻ������ �Ѵ�. Think
	// actor.ActionMove();
	//actor.Think();
	//actor.Action();

	RSPGame game;

	game.StartGame();

}
