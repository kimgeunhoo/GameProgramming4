#pragma once

/*
	������ ����
	1�ܰ�. �÷��̾��� ����, ����ġ

	������ �ڷᱸ�� ���·� ����.
	1 100
	2 100
*/

#include <fstream>
#include <iostream>

class Data
{
public:
	int exp;
	int level;

public:
	Data() : exp(100), level(1) {}

	// file ����
	// �޸��忡 exp�� level�� �����ض�.
	// close() ��Ʈ���� �ݵ�� �ݾ��� ��
	void SaveData(const std::string& filename)
	{
		std::ofstream file(filename);

		if (file.is_open())
		{
			file << level << " " << exp << std::endl;
			file.close();
		}

	}

	void LoadData(const std::string& filename)
	{
		std::ifstream file(filename);

		int _exp, _level;

		file >> _level >> _exp;

		level = _level;
		exp = _exp;
	}
};


