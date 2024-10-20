#include <iostream>
#include "play.hpp"
#include "character.hpp"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "Windows.h"
#include "color.hpp"

void play(Character& player)
{
	using std::srand, std::time, std::rand,std::cout,std::endl,std::to_string;
	srand(time(NULL));
	Character enemy("Enemy", rand() % 120, rand() % 50, rand() % 30);
	while (true)
	{
		cout << "造成" << attack(player, enemy) << "点伤害" << endl;
		cout << "受到" << attack(enemy, player) << "点伤害" << endl;
		green("玩家血量:" + to_string(enemy.getHp()));
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