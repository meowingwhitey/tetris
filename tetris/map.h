//맵 출력 및 맵 배열을 받을 시에 출력해줌
#ifndef MAP_H
#define MAP_H

#include "lib.h"

//맵 크기(경계 포함)
extern const int mapWidth;
extern const int mapHeight;

//맵 경계 출력
void createMapBorder(int ** map);

//malloc 맵 생성 및 반환
//return : mapValue[mapWidth][mapHeight];
int** initMap(void);

//malloc으로 생성된 맵 free
void deleteMap(int ** map);

//한 라인이 완성되었는지 여부 결정
//만약 라인이 완성되었다면 라인 삭제
//반환값 : 완성된 라인의 갯수 
int isLineFull(int** map);

#endif //MAP_H