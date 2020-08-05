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
void moveBlock(int** map, int key, Block* block);
//블럭 구조체 동적 할당
Block * generateBlock(void);
//생성된 블럭 삭제
void deleteBlock(Block *block);
#endif //BLOCK_H