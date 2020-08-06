#include "map.h"

//실제 맵 크기(10)+맵 경계(2)
extern const int mapWidth = 12;
//실제 맵 크기(20)+맵 경계(2)+블럭생성 공간(4)
extern const int mapHeight = 26;

void createMapBorder(int ** map) {
	int i, j;
	//콘솔에 맵 출력(블럭 생성을 위한 공간은 출력 X)
	gotoxy(0, 0);
	for (i = 0; i < mapWidth; i++) {
		printf("■");
	}
	for (i = 5; i < mapHeight; i++) {
		for (j = 0; j < mapWidth; j++) {
			if (map[i][j] == MAP_BORDER) {
				gotoxy(j, i - 4);
				printf("■");
			}
		}
	}
	/*
	//gotoxy(0, 0);
	for (i = 0; i < mapHeight; i++) {
		for (j = 0; j < mapWidth; j++) {
			printf("%d", map[j][i]);
			//printf("aa");
		}
		printf("\n");
	}
	*/
}
int** initMap() {
	int** map;
	int i, j;
	map = (int**)malloc(sizeof(int*) * mapHeight);
	for (i = 0; i < mapHeight; i++) {
		map[i] = (int*)malloc(sizeof(int)*mapWidth);
	}
	//맵 기본값(MAP_EMPTY로 초기화)
	for (i = 0; i < mapHeight; i++) {
		for (j = 0; j < mapWidth; j++) {
			map[i][j] = MAP_EMPTY;
		}
	}
	//맵 배열에 MAP_BORDER 값 추가
	for (i = 0; i < mapHeight; i++) {
		//맵의 최상단 || 맵의 최하단
		if (i == 0 || i == mapHeight - 1) {
			for (j = 0; j < mapWidth; j++) {
				map[i][j] = MAP_BORDER;
			}
		}
		//맵의 중간
		else {
			map[i][0] = MAP_BORDER;
			map[i][mapWidth - 1] = MAP_BORDER;
		}
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