#pragma once

#include <chrono>
#include <random>
#include "Windows.h"
#include <iostream>


class ConsoleUtil
{
public:
	static void GotoXY(int x, int y)
	{
		COORD pos = { static_cast<short>(x), static_cast<short>(y) };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

	static int GetRandomInt(int max)
	{
		static std::random_device rd; // �õ� ������
		static std::mt19937 gen(rd()); // Mersenne Twister ����
		std::uniform_int_distribution<> dist(1, max); // 1���� max������ ������ ���� ����
		return dist(gen); // ��
	}

	static void setCursorVisible(bool visible)
	{
		CONSOLE_CURSOR_INFO cursor = { 0 };
		cursor.dwSize = 1;
		cursor.bVisible = 0;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
	}

	static void TimeCheck(void (*Func)())
	{
		auto start = std::chrono::high_resolution_clock::now();

		// �Լ� ������
		Func();			

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli> duration = end - start;
		std::cout << duration.count() << " ms �ð��� �ɷȽ��ϴ�." << std::endl;
	}

	void SetWindowSize(int cols, int lines)
	{
		system("title PacManX");
		char cmd[30];
		sprintf_s(cmd, "mode con cols=%d lines=%d", cols, lines);
		system(cmd);
	}

	void SetColor(int colorID)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
	}

};