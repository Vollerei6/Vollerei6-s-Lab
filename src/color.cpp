#include <iostream>
#include <windows.h>
#include <format>
#include <string>
#include "color.hpp"
void rgb_init() {																// 初始化
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
}

void rgb_set(int wr,int wg,int wb,int br,int bg,int bb) {						//设置RGB
	std::cout <<std::format("\033[38;2;{0};{1};{2}m\033[48;2;{3};{4};{5}m",wr,wg,wb,br,bg,bb);	//\033[38表示前景，\033[48表示背景，三个%d表示混合的数
}

void red(const std::string& str)
{
	rgb_set(255, 0, 0, 0, 0, 0);
	std::cout << str;
	rgb_set(255, 255, 255, 0, 0, 0);
}

void green(const std::string& str)
{
	rgb_set(0, 255, 0, 0, 0, 0);
	std::cout << str;
	rgb_set(255, 255, 255, 0, 0, 0);
}
