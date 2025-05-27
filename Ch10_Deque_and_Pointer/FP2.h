#pragma once

#include "ConsoleUtility.h"
#include <iostream>

// 복습. 계산기 기능. 함수 포인터로 표현하기

#pragma region 심화(1). 함수 포인터에 일반화 프로그래밍 Generic Programming 적용

// 심화 1. 함수 포인터에 일반화 프로그래밍 Generic Programming 적용

template <typename T>
void Plus(T a, T b)
{
	std::cout << "더하기 결과 : ";
	std::cout << a + b << std::endl;
}

template <typename T>
void Minus(T a, T b)
{
	std::cout << "빼기 결과 : ";
	std::cout << a - b << std::endl;
}

template <typename T>
void Multiply(T a, T b)
{
	std::cout << "곱셈 결과 : ";
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
		std::cout << "나눗셈 결과 : ";
		std::cout << a / b << std::endl;
	}
	
}

template <typename T> // 함수를 인자로 받음 // 외부 인자를 받음
void Calculate(void (*Func)(T a, T b), T outA, T outB)
{
	Func(outA, outB);
}

#pragma endregion

#pragma region 심화(2). 열거형과 클래스로 함수 포인터 활용

// 열거형의 이름은 항상 대문자로 작성하여, 이름으로 타입을 알아볼 수 있게 설정한다.
// 함수는 첫 들자가 대문자로 표현하게 설정하였다. << 이 부분은 사람마다 다름. C#은 대체로 대문자
enum ActorAction
{
	MOVE, TALK
};

class Actor
{
private:
	static void Move()
	{
		std::cout << "움직입니다." << std::endl;
	}

	static void Talk()
	{
		std::cout << "대화합니다." << std::endl;
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

		// 랜덤한 숫자를 받아서, 0이 나오면 움직여라. 1이 나오면 Talk, 2가 나오면 ..
		int select = ConsoleUtil::GetRandomInt(2); // 액션이 늘어나면 액션 가짓수를 넣으면 된다
		// ConsoleUtil에서 만든것은 +1이 되어 있기에 switch 내의 select 값에 -1을 해야함
		ActorAction aaction = static_cast<ActorAction>(select - 1);

		switch (aaction)
		{
		case MOVE: ActionMove();
			break;
		case TALK: ActionTalk();
			break;
		default:
			std::cout << "잘못된 입력을 받아왔습니다" << std::endl;
			return;
		}
	}

};


#pragma endregion

#pragma region 가위바위보 예제 만들기

enum RSP_TYPE
{
	ROCK, SCISSORS, PAPER
};

class RSPGame
{
private:
	static void Rock()
	{
		std::cout << "CP : 바위 " << std::endl;
	}
	static void Scissors()
	{
		std::cout << "CP : 가위 " << std::endl;
	}
	static void Paper()
	{
		std::cout << "CP : 보 " << std::endl;
	}

	RSP_TYPE computertype;
	RSP_TYPE usertype;

	int userScore;
	int computerScore;

	void Result()
	{
		// 유저 컴퓨터 같다: 비김

		// 유저 > 컴퓨터 이김

		// 아니라면 짐
		if (usertype == computertype)
		{
			std::cout << "비겼습니다." << std::endl;
		}
		else if (usertype == ROCK && computertype == SCISSORS ||
			usertype == SCISSORS && computertype == PAPER ||
			usertype == PAPER && computertype == ROCK)
		{
			std::cout << "이겼습니다." << std::endl;
			userScore += 1;
		}
		else 
		{
			std::cout << "졌습니다." << std::endl;
			computerScore += 1;
		}
		std::cout << "유저 스코어 : " << userScore << " 컴퓨터 스코어 : " << computerScore << std::endl;
	}

public:

	RSPGame() : userScore(0), computerScore(0) {}
	// 함수 포인터 선언
	//RSPGame() = default;

	void (*Action)();
	// switch(RSP_TYPE) 각 타입에 맞게 함수포인터의 함수를 넣는 코드를 만들어보기

	void StartGame()
	{
		std::cout << "가위 바위 보 게임 " << std::endl;
		while (true) {
			std::cout << "해당하는 숫자를 입력하세요. 0_바위, 1_가위, 2_보 : ";
			int input = 0;
			std::cin >> input;
			std::cout << std::endl;
			usertype = static_cast<RSP_TYPE>(input);

			// 컴퓨터가 선택할 번호를 랜덤으로 받습니다.
			int select = ConsoleUtil::GetRandomInt(3);
			computertype = static_cast<RSP_TYPE>(select - 1);
			// swicth문을 사용한다. 함수포인터를 결정한다.
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
				std::cout << "잘못된 입력을 받아왔습니다" << std::endl;
				return;
			}
			Action();
			Result();

			if (userScore >= 3 || computerScore >= 3)
			{
				break;
			}
		}
		// 함수포인터의 함수를 실행한다.
		if (userScore == 3)
		{
			std::cout << "유저가 승리하였습니다." << std::endl;
		}
		else 
		{
			std::cout << "컴퓨터가 승리하였습니다." << std::endl;
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
	// actor. 의사결정을 한다. Think
	// actor.ActionMove();
	//actor.Think();
	//actor.Action();

	RSPGame game;

	game.StartGame();

}
