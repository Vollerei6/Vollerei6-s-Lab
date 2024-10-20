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
	Character enemy("Enemy", 120*getDis(), 50*getDis(), 30*getDis());
	while (true)
	{
		cout << "造成" << attack(player, enemy) << "点伤害" << endl;
		cout << "受到" << attack(enemy, player) << "点伤害" << endl;
		green("玩家血量:" + to_string(player.getHp()));
		endl(cout);
		red("怪物血量:" + to_string(enemy.getHp()));
		endl(cout);
		if (player.getHp() <= 0)
		{
			cout << "失败" << endl;
			break;
		}
		if (enemy.getHp() <= 0)
		{
			cout << "胜利" << endl;
			break;
		}
		Sleep(1000);
	}
}