//블럭 
#ifndef BLOCK_H
#define BLOCK_H

#include "lib.h"

typedef struct _Block {
	//블럭의 타입 ex) ㄱ모양인지 ㄴ인지
	int type;
	//회전 횟수
	int rotate;
	//현재 블럭의 위치
	COORD pos;
}Block;

//블럭 생성시 위치를 map에 맞춰줌
void settingBlock(int** map, Block* block);

//블럭 위치 이동
//이후 게임에서 블럭의 이동여부를 체크해야됨
//반환값 1 -> 블럭이동O
//반환값 0 -> 블럭이동X
int moveBlock(int** map, int key, Block* block);

//블럭 회전
//좌회전 - z, ctrl
//우회전 - x, ↑
int rotateBlock(int** map, int key, Block* block);

//블럭 구조체 동적 할당
Block * generateBlock(void);

//생성된 블럭 삭제
void deleteBlock(Block *block);

//블럭 이동시에 충돌 탐지
int isBlockCollision(int ** map, Block *block, COORD diff);

#endif //BLOCK_H