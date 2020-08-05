#include "map.h"

extern const int mapWidth = 10;
extern const int mapHeight = 20;

void createMapBorder() {
	int i, j;
	gotoxy(0, 0);
	for (i = 0; i <= mapWidth + 1; i++) {
		printf("■");
	}
	for (i = 1; i <= mapHeight; i++) {
		gotoxy(0, i);
		printf("■");
		for (j = 1; j <= mapWidth; j++) {
			printf("  ");
		}
		printf("■");
	}
	gotoxy(0, mapHeight + 1);
	for (i = 0; i <= mapWidth + 1; i++) {
		printf("■");
	}
}
//더블버퍼링 방식 사용
void refreshMap() {

}
int** initMap() {
	//블럭 생성시 내려와야 되므로 위 4개의 공간을 추가로 줌
	int** map = (int**)malloc(sizeof(int*)*(mapHeight + 4));
	int i = 0;
	for (i = 0; i < mapHeight + 4; i++) {
		map[i] = (int*)malloc(sizeof(int)*mapWidth);
	}
	return map;
}
void deleteMap(int ** map) {
	int i = 0;
	for (i = 0; i < mapHeight; i++) {
		free(map[i]);
	}
	free(map);
	return;
}