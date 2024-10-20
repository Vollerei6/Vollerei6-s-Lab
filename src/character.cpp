#include "character.hpp"
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>

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
/*
void Character::attack(Character *ID) const
{
	using namespace std;
	double DMG=0;
	Character *p=ID;
	DMG=ATK-(*p).DEF;
	(*p).HP-=DMG;
	cout<<"造成了"<<DMG<<"点伤害"<<endl;
}
*/
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
	using json = nlohmann::json;
	std::ifstream fin("archive.json");
	if (fin.is_open())
	{
		json archive;
		fin >> archive;
		if (archive.contains(name))
		{
			HPMAX = archive[name]["HP_MAX"].get<double>();
			HP = archive[name]["HP"].get<double>();
			ATK = archive[name]["ATK"].get<double>();
			DEF = archive[name]["DEF"].get<double>();
			EXP = archive[name]["EXP"].get<int>();
			LV = archive[name]["LV"].get<int>();
			skillCD_MAX = archive[name]["skillCD_MAX"].get<int>();
			std::cout << "角色:" << name << "读取成功" << std::endl;
		}
		else
		{
			Save();
			std::cout << "已为您新建角色：" << name << std::endl;
		}
	}
	else
	{
		Save();
		std::cout << "已为您新建角色：" << name << std::endl;
	}
}

void Character::Save()
{
	using json = nlohmann::json;
	std::ifstream fin("archive.json");
	std::ofstream fout;
	json archive;
	if (fin.is_open())
	{
		fin >> archive;
	}
	else
	{
		fout.open("archive.json");
		fout << "{}";
		fout.close();
		fout.clear();
	}
	fin.close();
	fout.open("archive.json");
	if (fout.is_open())
	{
		archive[name]["HP_MAX"] = HPMAX;
		archive[name]["HP"] = HP;
		archive[name]["ATK"] = ATK;
		archive[name]["DEF"] = DEF;
		archive[name]["EXP"] = EXP;
		archive[name]["LV"] = LV;
		archive[name]["skillCD_MAX"] = skillCD_MAX;
		fout << archive << std::endl;
		fout.close();
	}
}
double attack(const Character& attacker, Character& target)
{
	double damage = 0;
	damage = (std::max)(attacker.ATK - target.DEF, attacker.ATK * 0.05);
	target.HP -= damage;
	return damage;
}
