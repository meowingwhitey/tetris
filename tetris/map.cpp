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
int isLineFull(int** map) {
	int i, j, k;
	//만들어진 라인의 총 갯수
	int lineCount = 0;
	//한 라인의 전체 맵 값(한줄 완성시 경계 빼고 20)
	int lineSum[26] = { 0, };
	//한번에 몇줄이 줄어들었는지 확인
	int linePadding = 0;
	//라인 정리를 위한 임시 맵 배열
	int mapTemp[mapHeight][mapWidth] = {0 , };
	//mapTemp에서 어디까지 찼는지를 알기 위해
	int lineBottom = 1;
	
	//모든 맵에 대하여 한줄이 생성되었는지 확인
	for (i = mapHeight - 2; i > 4; i--) {
		for (j = 1; j < mapWidth - 1; j++) {
			lineSum[i] = lineSum[i] + map[i][j];
		}
		//만약 한 라인의 값이 20이 나올시에 카운트를 높여줌
		if (lineSum[i] == 20) {
			lineCount = lineCount + 1;
		}
	}
	if (lineCount == 0) {
		return 0;
	}
	//아래부터 차래대로 맵에 복사
	for (i = mapHeight - 2; lineSum[i] != 0; i--) {
		if (lineSum[i] < 20) {
			for (j = 1; j < mapWidth - 1; j++) {
				if (map[i][j] == MAP_BLOCK_FIXED) {
					mapTemp[mapHeight - lineBottom - 1][j] = MAP_BLOCK_FIXED;
				}
			}
			lineBottom++;
		}
	}
	//라인이 정리된 맵 출력 및 mapTemp 저장값을 모두 map으로 이동시켜줌
	for (i = mapHeight - 2; lineSum[i] != 0; i--) {
		for (j = 1; j < mapWidth - 1; j++) {
			//기존 블럭들 모두 삭제
			gotoxy(j, i - 4);
			printf("  ");
			map[i][j] = MAP_EMPTY;
			if (mapTemp[i][j] == MAP_BLOCK_FIXED) {
				gotoxy(j, i - 4);
				printf("■");
				map[i][j] = MAP_BLOCK_FIXED;
			}
		}
	}
	return lineCount;
}