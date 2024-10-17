//这个character类包含了character的各项属性，以及可以执行的各项函数 
#define _character_h
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

inline Character::Character(double a,double b,double c,int d,int e,int f,char g[16]){
	HPMAX=a;
	HP=a;
	ATK=b;
	DEF=c;
	EXP=d;
	LV=e;
	skillCD=0;
	skillCD_MAX=f;
	strcpy(name,g);
}

inline void Character::attack(Character *ID)
{
	double DMG=0;
	Character *p=ID;
	DMG=ATK-(*p).DEF;
	(*p).HP-=DMG;
	cout<<"造成了"<<DMG<<"点伤害"<<endl;
}

inline void Character::skill(Character *ID)
{
	skillCD=skillCD_MAX;
	double DMG=0;
	Character *p=ID;
	DMG=(ATK-(*p).DEF)*1.2;
	(*p).HP-=DMG;
	cout<<"造成了"<<DMG<<"点伤害"<<endl;
}

inline void Character::LevelUp()
{
	if(EXP>=10*LV){
		EXP-=10*LV;
		LV+=1;
		HPMAX+=10;
		if(HP>0.5*HPMAX){
			HP=HPMAX;
		}
		else{
			HP+=HPMAX*0.5;
		}
		ATK+=2;
		DEF+=1;
	}
}
#end
