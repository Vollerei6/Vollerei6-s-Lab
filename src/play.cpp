#include <iostream>
#include "play.hpp"
#include "character.hpp"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "Windows.h"

double attack(const Character& attacker, Character& target)
{
	double damage = 0;
	damage = (std::max)(attacker.ATK - target.DEF, attacker.ATK * 0.05);
	target.HP -= damage;
	return damage;
}

void play(Character& player)
{
	using std::srand, std::time, std::rand,std::cout,std::endl;
	srand(time(NULL));
	Character enemy("Enemy", rand() % 120, rand() % 50, rand() % 30);
	while (true)
	{
		cout << "造成" << attack(player, enemy) << "点伤害" << endl;
		cout << "受到" << attack(enemy, player) << "点伤害" << endl;
		cout << "怪物血量:" << enemy.getHp() << endl;
		cout << "玩家血量:" << player.getHp() << endl;
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