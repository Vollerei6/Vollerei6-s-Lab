//这个character类包含了character的各项属性，以及可以执行的各项函数 
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

class Character{
	public:
		Character(double a,double b,double c,int d,int e,int f,char g[16]);//构造函数
		~Character() = default;
		double HPMAX;//表示生命值上限 
		double HP;//表示现有的生命值 
		double ATK;
		double DEF;
		int EXP;
		int LV;
		int skillCD;//当前的剩余冷却时间 
		int skillCD_MAX;//最大CD 
		char name[16]="";
		void attack(Character *ID) const;//将攻击等操作用函数形式封装，便于后续维护 
		void skill(Character *ID);
		void LevelUp();///升级 
};//角色类，包含角色的各种属性/角色可进行的行为 
#endif // CHARACTER_HPP
