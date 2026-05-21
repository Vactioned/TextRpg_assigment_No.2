#ifndef BATTLE_H_
#define BATTLE_H_

#include "Player.h"
#include "Monster.h"

extern bool isPlayerWin;

void battleStart(Player* player, Monster& monster);

#endif