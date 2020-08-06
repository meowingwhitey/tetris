//�� ��� �� �� �迭�� ���� �ÿ� �������
#ifndef MAP_H
#define MAP_H

#include "lib.h"

#define MAP_BORDER 3
#define MAP_BLOCK_FIXED 2
#define MAP_BLOCK_MOVE 1
#define MAP_EMPTY 0

//�� ũ��(��� ����)
extern const int mapWidth;
extern const int mapHeight;

//�� ��� ���
void createMapBorder(int ** map);

//malloc �� ���� �� ��ȯ
//return : mapValue[mapWidth][mapHeight];
int** initMap(void);

//malloc���� ������ �� free
void deleteMap(int ** map);

#endif //MAP_H