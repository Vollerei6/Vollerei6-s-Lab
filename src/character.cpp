#include "character.hpp"
Character::Character(double a,double b,double c,int d,int e,int f,char g[16]){
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

void Character::attack(Character *ID) const
{
	double DMG=0;
	Character *p=ID;
	DMG=ATK-(*p).DEF;
	(*p).HP-=DMG;
	cout<<"造成了"<<DMG<<"点伤害"<<endl;
}

void Character::skill(Character *ID)
{
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