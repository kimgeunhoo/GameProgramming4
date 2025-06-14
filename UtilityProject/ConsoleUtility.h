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
		static std::random_device rd; // 시드 생성기
		static std::mt19937 gen(rd()); // Mersenne Twister 엔진
		std::uniform_int_distribution<> dist(1, max); // 1부터 max까지의 균일한 정수 분포
		return dist(gen); // 랜
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

		// 함수 포인터
		Func();			

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli> duration = end - start;
		std::cout << duration.count() << " ms 시간이 걸렸습니다." << std::endl;
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