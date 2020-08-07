//잡다한 함수 집합
#ifndef LIB_H
#define LIB_H

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<Windows.h>

#define MAP_BORDER 3
#define MAP_BLOCK_FIXED 2
#define MAP_BLOCK_MOVE 1
#define MAP_EMPTY 0

void gotoxy(int x, int y);
void cursorView(char show);
int getKeyValue(void);

#endif //LIB_H