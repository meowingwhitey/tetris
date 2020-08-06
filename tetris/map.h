//�� ��� �� �� �迭�� ���� �ÿ� �������
#ifndef MAP_H
#define MAP_H

#include "lib.h"

extern const int mapWidth;
extern const int mapHeight;

//�� ��� ���
void createMapBorder(void);

//malloc �� ���� �� ��ȯ
//return : mapValue[mapWidth][mapHeight];
int** initMap(void);

//malloc���� ������ �� free
void deleteMap(int ** map);
#endif //MAP_H