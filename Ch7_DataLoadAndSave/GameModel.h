#pragma once


/*
	목표 : 레벨업 시스템 구현
	int exp, maxExp;	현재 경험치 > maxExp	레벨 + 1 올린다.
*/

/*
	목표 2 : 레벨에 따른 경험치 요구량을 자료구조로 표현하기.
	vector<"">
*/

/*
	데이터를 표현하기 위한 클래스 생성 LevelExp
	특정 클래스 안에 표현하기 위한 클래스의 자료구조로 선언하기. Player-> std::vector<LevelExp> levelTable;
*/

/*
	생성자에 데이터를 직접 작성한다.
	vector.push_back(), 
	vector.emplace_back();
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <iostream>

//struct Pokemon
//{
//	std::string name;
//
//	LevelExp levelExp;
//};


struct LevelExp
{
	int level;
	int maxExp;

	LevelExp(int level, int maxExp) : level(level), maxExp(maxExp) {}

};

class Player
{
private:
	int exp;
	int maxExp;
	int level;
	std::vector<LevelExp> levelTable;

public:
	Player() : exp(0), level(1), maxExp(100) {}
	Player(int exp, int maxExp) :level(1), exp(exp), maxExp(maxExp) 
	{
		levelTable.emplace_back(1, 100);
		levelTable.emplace_back(2, 100);
		levelTable.emplace_back(3, 100);
		levelTable.emplace_back(4, 150);
		levelTable.emplace_back(5, 150);
		levelTable.emplace_back(6, 150);
		levelTable.emplace_back(7, 200);
		levelTable.emplace_back(8, 200);
		levelTable.emplace_back(9, 200);
	}

	int GetMaxExpForLevel(int level)
	{
		for (const auto& data: levelTable)
		{
			// 레벨과 table 레벨을 비교
			if (level == data.level)
			{
				return data.maxExp;
			}
		}

		return -1; // -1 반환하면 에러로 인식
	}

	void GetExp(int amount)		// 경험치를 획득
	{
		exp += amount;			// exp 그 수치만큼 더해준다.

		maxExp = GetMaxExpForLevel(level);

		if (maxExp == -1)
		{
			std::cout << "최대 레벨에 도달하였습니다. 실행을 취소합니다." << std::endl;
			return;			// 예외 처리 코드 알림 후 함수 종료
		}

		if (exp >= maxExp)		// "레벨의 최대 경험치 도달했을 때"
		{
			level++;
			exp -= maxExp;
		}
	}

	void Show() const
	{
		std::cout << "level : " << level << std::endl;
		std::cout << "Exp : " << exp << std::endl;
		std::cout << "maxExp : " << maxExp << std::endl;
	}

	void SaveData(const std::string& filename)
	{
		std::ofstream file(filename);


		if (file.is_open())
		{
			file << level << " " << exp << " " << maxExp << std::endl;
			file.close();
		}

	}

	void LoadData(const std::string& filename)
	{
		std::ifstream file(filename);

		int _exp, _level, _maxExp;

		file >> _level >> _exp >> _maxExp;

		level = _level;
		exp = _exp;

	
	}
};

