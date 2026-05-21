#ifndef GAMEUI_H_
#define GAMEUI_H_

#include <string>

void printCharacterUpgrade(int HP_Potion, int MP_Potion);

void printStatus(std::string player_name, int stat[]);

extern const std::string SEPARATOR;

#endif