#pragma once
#include <string>
#include "nlohmann/json.hpp"

class Weapon
{
public:
	Weapon() = default;
	Weapon(const std::string& name, double ATK, double Crit, double combo, double suck);
	~Weapon() = default;
	inline double getATK() { return this->ATK; }
	void Save(const std::string& characterName,nlohmann::json & archive);
private:
	std::string name = "Weapon";//名字·
	double ATK = 0;//攻击
	double Crit = 0;//暴击
	double combo = 0;//连击
	double suck = 0;//吸血
};
