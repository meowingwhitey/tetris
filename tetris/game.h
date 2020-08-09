#ifndef GAME_H
#define GAME_H

//게임 진행 속도
#define SPEED 50

#include "lib.h"
#include "map.h"
#include "block.h"


void runGame(void);
int isGameEnded(int **map);
#endif