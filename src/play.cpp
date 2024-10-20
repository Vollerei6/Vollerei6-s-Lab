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
		cout << "造成" <<green()<< attack(player, enemy) <<white()<< "点伤害" << endl;
		cout << "受到" <<red()<< attack(enemy, player) <<white()<< "点伤害" << endl;
		cout << green()<<"玩家血量:" << player.getHp()<<white()<<endl;
		cout <<red()<<"怪物血量:"<<enemy.getHp()<<white()<<endl;
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