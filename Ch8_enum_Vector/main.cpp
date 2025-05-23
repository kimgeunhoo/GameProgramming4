/*
	enum ����

	class �ȿ� enum Ȱ���ϱ�
*/

/*
	enum: ������
	enum���� ����� ������ �� �ִ�.
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
	Trait - Stat ���踦 �����ؾ� �Ѵ�.
	STR 1 �÷��� �� ? : Damage(���� ��ġ) * ( ); �տ��� or ������

*/

/*
	Vector Ÿ���� �Ѱ���
	Stat, Trait
	Dex �ø��� Speed �����ϴ� �ý���?

	�迭 ���·� ����Ǿ� �ִ� �ڷᱸ���̱� ������, �ڷ��� ���� �� �߰��� �� �� ������ �߻��� �� �ִ�.
	������� �����Ǿ� ���� ���� �������� ������ �߻��Ͽ��� �� ������ ����ȴ�.

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
		C������ Casting ������
		- �������� ����ȯ�� ���ÿ� �� �� �ִ�. (casting�� �� �ڵ�θ� �ϰ�ó����)
		CPP������ Casting
		- static_cast, const_cast, reinterpret_cast // dynamic_cast

		�ǵ����� ���� ����ȯ�� �߻��� �� �ִ�. (static�� �ƴ� const�� �ȴٴ��� ��...)

		Tip) int, double, std::string Primitive Type Ÿ���� ��ȯ�ϰ� ������ static_cast ���
		const_cast : ����� �����ִ� ����ȯ
		reinterpret_cast : �޸𸮿� �����Ͽ� int* -> double* ���ؼ��Ͽ� ��ȯ�ϴ� ��ȯ
		dynamic_cast : Ŭ������ ��Ӱ��踦 ����ȯ�Ͽ�, ���� �����Ͱ� �������� ������ null ��ȯ�Ѵ�.

		if(dynamic_cast<Monster> d) {}

	*/;

void EnumTest1()
{
		// enum�� ������, ������ enum���� ��ȯ�ϴ� ����

		int num = Stat::DAMAGE;

		Stat someType = (Stat)num;		// C������ ����ȯ ����
		Stat someType2 = static_cast<Stat>(num);	// CPP ����ȯ

		if (someType2 == Stat::DAMAGE) // someType ����� ����ȯ �Ǿ��ٸ� �ڵ尡 ����
		{
			std::cout << "���� ���" << std::endl;
		}
}

	// Enum vector Ÿ������ ����ȯ�Ͽ� ����ϴ� ����
void EnumTest2()
{
		Player player;

		//

		//player.IncreaseStat(Stat::DAMAGE, 5); // �÷��̾��� ���ݷ� ������ 5��ŭ �������Ѷ�.
		//player.ShowPlayerStat();

}

void EnumTest3()
{
		TraitBonus traits;

		traits.GetTrait(Trait::STRENGTH);
		traits.ShowStat();


		// �÷��̾��� Ư���� ���������� �� , Ư�� ������ �����ϰ� �Ϸ��� ��� �ڵ带 �ۼ��ؾ� �ϳ�?

		// enum Trait, enum Stat, int amount �Լ��� �ʿ��ϴ�.
}

void EnumTest4()
{
		Player player;
		// player �ȿ� �ִ� Traitbonus Ŭ������ �����Ͽ� �Լ� ���
		/*player.GetTraits().GetTrait(Trait::STRENGTH);
		player.GetTraits().ShowStat();*/

		// Player Ŭ������ Traitbonus �Լ��� Wrapping �Ѵ�.
		player.GetTrait(Trait::STRENGTH);
		player.ShowStatus();
}


int main()
{
		//EnumTest1();
		//EnumTest2();
		//EnumTest3();
		//EnumTest4();

		// �Է��� ����Ͽ� ������ ����

		// ȭ�� ��� : 1�� ������ Strength ������Ų��.. 2�� ������ ... 3�� ������ ...

		Player player;

		std::cout << "=================������===============" << std::endl;

		int input;
		std::cout << "���� ����� �Է� ������ Ư�� A�� �ø��ϴ�." << std::endl;
		std::cin >> input;

		if (input >= Trait::NONE)
		{
			std::cout << "�߸��� ���ڸ� �Է��Ͽ����ϴ�." << std::endl;
		}
		else
		{
			player.GetTrait(static_cast<Trait>(input));
		}

		player.ShowStatus();

}

	// �÷��̾� ������ �ý��� + ���� ��� �ý���
	// �������� ���� �� ������ ����� �� �ְ� ������/
	// Player	TraitBonus, LevelUp

