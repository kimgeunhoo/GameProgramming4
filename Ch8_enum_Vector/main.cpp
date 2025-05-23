/*
	enum 선언

	class 안에 enum 활용하기
*/

/*
	enum: 열거형
	enum으로 상수를 저장할 수 있다.
*/

#include <vector>
#include <iostream>

enum Trait
{
	STRENGTH,
	DEXTERITY,
	INTELIGENCE,
	NONE,
};

enum Stat
{
	DAMAGE,
	HEALTH,
	MANA,
	STEMINA,
	SPEED
};

/*
	Trait - Stat 관계를 정의해야 한다.
	STR 1 올렸을 때 ? : Damage(기존 수치) * ( ); 합연산 or 곱연산

*/

/*
	Vector 타입의 한계점
	Stat, Trait
	Dex 올리면 Speed 증가하는 시스템?

	배열 형태로 저장되어 있는 자료구조이기 때문에, 자료의 삭제 및 추가를 할 때 문제가 발생할 수 있다.
	순서대로 정리되어 있지 않은 데이터의 변경이 발생하였을 때 문제가 예상된다.

	Map << 
*/

class TraitBonus
{
private:
	void IncreaseStat(Stat stat, int amount)
	{
		Stats[static_cast<int>(stat)] += amount;
	}

public:
	Trait trait;				//
	Stat stat;
	int additiveBonusPoint;
	std::vector<int> Stats;

	TraitBonus() : Stats(5, 0) {}
	TraitBonus(Trait trait, Stat stat, int additiveBonusPoint) 
		: trait(trait), stat(stat), additiveBonusPoint(additiveBonusPoint), Stats(5,0) {}

	void GetTrait(Trait trait)
	{
		switch (trait)
		{
			case Trait::STRENGTH:
			{
				IncreaseStat(DAMAGE, 5);
				IncreaseStat(HEALTH, 10);
				IncreaseStat(STEMINA, 5);
				break;
			}
			case Trait::DEXTERITY:
			{
				IncreaseStat(SPEED, 1);
				break;
			}
			case Trait::INTELIGENCE:
			{
				IncreaseStat(MANA, 5);
				break;
			}
		}
	}

	void ShowStat()
	{
		std::cout << "Damage : " << Stats[DAMAGE] << std::endl;
		std::cout << "Health : " << Stats[HEALTH] << std::endl;
		std::cout << "Mana : " << Stats[MANA] << std::endl;
		std::cout << "Stemina : " << Stats[STEMINA] << std::endl;
		std::cout << "Speed : " << Stats[SPEED] << std::endl;
	}
	
};

class Player
{
private:
	TraitBonus traitbonus;

public:
	Player() : traitbonus() {}

	TraitBonus GetTraits() const { return traitbonus; }

	void GetTrait(Trait trait)
	{
		traitbonus.GetTrait(trait);
	}

	void ShowStatus()

	{
		traitbonus.ShowStat();
	};
}
	/*
		C형태의 Casting 문제점
		- 여러가지 형변환을 동시에 할 수 있다. (casting을 한 코드로만 일괄처리함)
		CPP형태의 Casting
		- static_cast, const_cast, reinterpret_cast // dynamic_cast

		의도하지 않은 형변환이 발생할 수 있다. (static이 아닌 const가 된다던가 등...)

		Tip) int, double, std::string Primitive Type 타입을 변환하고 싶으면 static_cast 사용
		const_cast : 상수를 없애주는 형변환
		reinterpret_cast : 메모리에 접근하여 int* -> double* 재해석하여 변환하는 변환
		dynamic_cast : 클래스의 상속관계를 형변환하여, 실제 데이터가 존재하지 않으면 null 반환한다.

		if(dynamic_cast<Monster> d) {}

	*/;

void EnumTest1()
{
		// enum을 정수로, 정수를 enum으로 변환하는 예제

		int num = Stat::DAMAGE;

		Stat someType = (Stat)num;		// C형태의 형변환 문법
		Stat someType2 = static_cast<Stat>(num);	// CPP 형변환

		if (someType2 == Stat::DAMAGE) // someType 제대로 형변환 되었다면 코드가 실행
		{
			std::cout << "스탯 출력" << std::endl;
		}
}

	// Enum vector 타입으로 형변환하여 사용하는 예제
void EnumTest2()
{
		Player player;

		//

		//player.IncreaseStat(Stat::DAMAGE, 5); // 플레이어의 공격력 스탯을 5만큼 증가시켜라.
		//player.ShowPlayerStat();

}

void EnumTest3()
{
		TraitBonus traits;

		traits.GetTrait(Trait::STRENGTH);
		traits.ShowStat();


		// 플레이어의 특성을 증가시켰을 때 , 특정 스탯을 증가하게 하려면 어떠한 코드를 작성해야 하나?

		// enum Trait, enum Stat, int amount 함수가 필요하다.
}

void EnumTest4()
{
		Player player;
		// player 안에 있는 Traitbonus 클래스에 접근하여 함수 사용
		/*player.GetTraits().GetTrait(Trait::STRENGTH);
		player.GetTraits().ShowStat();*/

		// Player 클래스에 Traitbonus 함수를 Wrapping 한다.
		player.GetTrait(Trait::STRENGTH);
		player.ShowStatus();
}


int main()
{
		//EnumTest1();
		//EnumTest2();
		//EnumTest3();
		//EnumTest4();

		// 입력을 사용하여 스탯을 증가

		// 화면 출력 : 1을 누르면 Strength 증가시킨다.. 2를 누르면 ... 3을 누르면 ...

		Player player;

		std::cout << "=================레벨업===============" << std::endl;

		int input;
		std::cout << "숫자 몇번을 입력 했을때 특성 A를 올립니다." << std::endl;
		std::cin >> input;

		if (input >= Trait::NONE)
		{
			std::cout << "잘못된 숫자를 입력하였습니다." << std::endl;
		}
		else
		{
			player.GetTrait(static_cast<Trait>(input));
		}

		player.ShowStatus();

}

	// 플레이어 레벨업 시스템 + 스탯 상승 시스템
	// 레벨업을 했을 때 스탯을 상승할 수 있게 만들어라/
	// Player	TraitBonus, LevelUp

