<<<<<<< HEAD
﻿#include <iostream>
#include <windows.h>
#include <format>
#include <string>
#include "color.hpp"
void rgb_init() {																// 初始化
=======
#include "color.hpp"

#ifdef _WIN32
#include <windows.h>
#endif

void rgb_init() {																// 初始化
	#ifdef _WIN32
>>>>>>> 38f412864736f1b14537d6b00624b583562b8d7b
	using namespace std;
	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);		//输入句柄
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);		//输出句柄
	DWORD dwInMode, dwOutMode;
	GetConsoleMode(hIn, &dwInMode);						//获取控制台输入模式
	GetConsoleMode(hOut, &dwOutMode);					//获取控制台输出模式
	dwInMode |= 0x0200;									//更改
	dwOutMode |= 0x0004;
	SetConsoleMode(hIn, dwInMode);						//设置控制台输入模式
	SetConsoleMode(hOut, dwOutMode);					//设置控制台输出模式
<<<<<<< HEAD
=======
	#endif
>>>>>>> 38f412864736f1b14537d6b00624b583562b8d7b
}

