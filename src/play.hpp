#ifndef _play_h
#define _play_h
#include "character.hpp"

void play(Character& player);
void exitGame(Character& player);
void battle(Character& charaacter1, Character& character2);
void getWeapon(Character& player);
double attack(Character &attacker, Character &Target);
#endif
