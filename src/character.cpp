#include "character.hpp"
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>
#include <format>
#include "random_get.hpp"

Character::Character(const std::string & name,double HPMAX,double ATK,double DEF,int EXP,int LV,int skillCD_MAX,double speed)//构造函数
{
	this ->HPMAX = HPMAX;
	this->HP = HPMAX;
	this->ATK = ATK;
	this->DEF = DEF;
	this->EXP = EXP;
	this->LV = LV;
	this->skillCD = skillCD_MAX;
	this->skillCD_MAX = skillCD_MAX;
	this-> name = name;
	this->speed = speed;
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
	using json = nlohmann::json;
	std::ifstream fin("archive.json");
	if (fin.is_open())
	{
		json archive;
		fin >> archive;
		if (archive.contains(name))
		{
			try
			{
				HPMAX = archive[name]["HP_MAX"].get<double>();
				HP = archive[name]["HP"].get<double>();
				ATK = archive[name]["ATK"].get<double>();
				DEF = archive[name]["DEF"].get<double>();
				EXP = archive[name]["EXP"].get<int>();
				LV = archive[name]["LV"].get<int>();
				skillCD_MAX = archive[name]["skillCD_MAX"].get<int>();
				this->speed = archive[name]["speed"].get<double>();
				weapon.Load(name, archive);
				std::cout << "角色:" << name << "读取成功" << std::endl;
			}
			catch (std::exception &e)
			{
				#ifdef _DEBUG
				std::cerr << e.what()<<std::endl;
				#endif 		
				Save();
	  		}
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
		archive[name]["speed"] = this->speed;
		weapon.Save(name,archive);
		fout << archive << std::endl;
		fout.close();
	}
}
double attack(Character& attacker, Character& target)
{
	return target.damage(attacker.getATK());
}

void Character::getInfo()
{
	std::cout << std::format("金币数:{0}\n血量:{1}\n攻击:{2}\n防御:{3}\n速度:{4}\n等级:{5}\n经验:{6}/{7}\n", coin, HPMAX, ATK, DEF, speed, LV, EXP, LV * 10);
}

double Character::damage(const double takeDamage)
{
	double damageNum = (std::max)(takeDamage - DEF, takeDamage * 0.05);
	HP -= damageNum;
	return damageNum;
}
