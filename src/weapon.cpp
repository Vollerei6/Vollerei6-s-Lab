#include "weapon.hpp"
#include <string>

Weapon::Weapon(const std::string& name, double ATK, double Crit, double combo, double suck)
{
	this->name = name;
	this->ATK = ATK;
	this->Crit = Crit;
	this->combo = combo;
}
