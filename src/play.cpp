#include <iostream>
#include "play.hpp"
#include "character.hpp"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "Windows.h"
#include "color.hpp"
#include "random_get.hpp"

void play(Character& player)
{
	using std::cout,std::endl,std::to_string;
	Character enemy("Enemy", 75*getDis(), 50*getDis(), 15*getDis(),0,0,3,200*getDis());
	player.resetHp();
	battle(player, enemy);
}

void battle(Character& player, Character& enemy)
{
	double status1 = 0,status2=0;
	double editSpeed1 = 1000 / player.getSpeed();
	double editSpeed2 = 1000 / enemy.getSpeed();
	while (true)
	{
		using std::cout, std::endl;
		status1 += (std::min)(editSpeed1, editSpeed2);
		status2 += (std::min)(editSpeed1, editSpeed2);
		if (status1 >= editSpeed1)
		{
			cout << "造成" << green() << attack(player, enemy) << white() << "点伤害" << endl;
			cout << red() << "怪物血量:" << enemy.getHp() << white() << endl ;
			status1 -= editSpeed1;
		}
		if (status2 >= editSpeed2)
		{
			cout << "受到" <<red()<< attack(enemy, player) <<white()<< "点伤害" << endl;
			cout << green() << "玩家血量:" << player.getHp() << white() << endl ;
			status2-=editSpeed2;
		}
		endl(cout);
		if (player.getHp() <= 0 && enemy.getHp() <= 0)
		{
			cout << "平局" << endl;
			break;
		}
		else
		{
			if (player.getHp() <= 0)
			{
				cout << red() << "失败" << white() << endl;
				break;
			}
			if (enemy.getHp() <= 0)
			{
				cout << green() << "胜利" << white() << endl;
				cout << yellow() << "当前经验值：" << player.addEXP(10) << white() << endl;
				player.Save();
				break;
			}
		}
		Sleep(1000);

	}
}