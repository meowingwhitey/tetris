//맵 출력 및 맵 배열을 받을 시에 출력해줌
#ifndef MAP_H
#define MAP_H

#include "lib.h"

extern const int mapWidth;
extern const int mapHeight;

//맵 경계 출력
void createMapBorder(void);

//malloc 맵 생성 및 반환
//return : mapValue[mapWidth][mapHeight];
int** initMap(void);

//malloc으로 생성된 맵 free
void deleteMap(int ** map);
#endif //MAP_H