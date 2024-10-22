#pragma once
#include <string>
class Weapon
{
public:
	Weapon() = default;
	Weapon(const std::string& name, double ATK, double Crit, double combo, double suck);
	~Weapon() = default;
private:
	std::string name = "Weapon";//名字·
	double ATK = 0;//攻击
	double Crit = 0;//暴击
	double combo = 0;//连击
	double suck = 0;//吸血
};
