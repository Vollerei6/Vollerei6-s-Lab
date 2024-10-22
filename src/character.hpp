//这个character类包含了character的各项属性，以及可以执行的各项函数 
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include "random_get.hpp"
#include "weapon.hpp"

class Character{
	public:
		Character(const std::string& name, double HPMAX = 100, double ATK = 50, double DEF = 30, int EXP = 0, int LV = 0, int skillCD_MAX = 3,double speed=100);//构造函数
		~Character() = default;
		void skill(Character *ID);
		void LevelUp();///升级
		void Save();
		void Load();
		inline double getHp() { return HP;}
		void getInfo();
		inline double getATK() { return ATK * getDis(); }
		double damage(const double takeDamage);
		inline double getSpeed() { return speed; }
		inline void resetHp() { HP = HPMAX; }
		inline int addEXP(int addEXP) { this->EXP += addEXP; LevelUp(); return this->EXP; }
	private:
		long long coin = 0;
		Weapon weapon; //拥有武器
		double HPMAX;//表示生命值上限 
		double HP;//表示现有的生命值 
		double ATK;
		double DEF;
		int EXP;
		int LV;
		int skillCD;//当前的剩余冷却时间 
		int skillCD_MAX;//最大CD 
		double speed;
		std::string name;
};//角色类，包含角色的各种属性/角色可进行的行为 
#endif // CHARACTER_HPP
