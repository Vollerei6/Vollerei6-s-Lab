#include "character.hpp"
#include <fstream>
#include <string>

Character::Character(const std::string & t_name,double t_HPMAX,double t_ATK,double t_DEF,int t_EXP,int t_LV,int t_skillCD_MAX)//构造函数
{
	HPMAX = t_HPMAX;
	HP = t_HPMAX;
	ATK = t_ATK;
	DEF = t_DEF;
	EXP = t_EXP;
	LV = t_LV;
	skillCD = t_skillCD_MAX;
	skillCD_MAX = t_skillCD_MAX;
	name = t_name;
}

void Character::attack(Character *ID) const
{
	using namespace std;
	double DMG=0;
	Character *p=ID;
	DMG=ATK-(*p).DEF;
	(*p).HP-=DMG;
	cout<<"造成了"<<DMG<<"点伤害"<<endl;
}

void Character::skill(Character *ID)
{
	using namespace std;
	skillCD=skillCD_MAX;
	double DMG=0;
	Character *p=ID;
	DMG=(ATK-(*p).DEF)*1.2;
	(*p).HP-=DMG;
	cout<<"造成了"<<DMG<<"点伤害"<<endl;
}

void Character::LevelUp()
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

void Character::Load()
{
	using namespace std;
	ifstream infile("archive.dat");//尝试打开存档
	if (infile.good()) {
		infile >> HPMAX;
		HP = HPMAX;
		infile >> ATK;
		infile >> DEF;
		infile >> EXP;
		infile >> LV;
		infile >> name;
		infile.close();
	}
}

void Character::Save()
{
	
}