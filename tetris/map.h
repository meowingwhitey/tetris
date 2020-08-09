//�� ��� �� �� �迭�� ���� �ÿ� �������
#ifndef MAP_H
#define MAP_H

#include "lib.h"

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

//�� ������ �ϼ��Ǿ����� ���� ����
//���� ������ �ϼ��Ǿ��ٸ� ���� ����
//��ȯ�� : �ϼ��� ������ ���� 
int isLineFull(int** map);

#endif //MAP_H