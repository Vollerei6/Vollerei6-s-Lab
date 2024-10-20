//这个character类包含了character的各项属性，以及可以执行的各项函数 
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <fstream>
#include <iostream>
#include <cstring>
#include <string>

class Character{
	public:
		Character(const std::string& t_name, double t_HPMAX = 100, double t_ATK = 50, double t_DEF = 30, int t_EXP = 0, int t_LV = 0, int t_skillCD_MAX = 3);//构造函数
		~Character() = default;
		friend double attack(const Character &attacker, Character &Target);
		void skill(Character *ID);
		void LevelUp();///升级
		void Save();
		void Load();
		inline double getHp() { return HP;}
		void getInfo();
	private:
		long long coin = 0;
		double HPMAX;//表示生命值上限 
		double HP;//表示现有的生命值 
		double ATK;
		double DEF;
		int EXP;
		int LV;
		int skillCD;//当前的剩余冷却时间 
		int skillCD_MAX;//最大CD 
		std::string name;
};//角色类，包含角色的各种属性/角色可进行的行为 
#endif // CHARACTER_HPP
