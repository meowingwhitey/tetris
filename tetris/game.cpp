#include "game.h"

Block block;
void runGame(void) {
	int** map, i, j;
	int score = 0;
	//while문 반복 횟수를 통하여 블럭이 떨어지는 속도 조정
	int blockDropCount = 0;
	int blockDropRate = 5;

	//블럭 고정 시간
	int blockFixCount = 0;
	int blockFixRate = 4;

	int key;
	Block * currentBlock ;
	//커서 깜빡임 삭제
	cursorView(0);
	//2차원 맵을 동적으로 할당 받음
	map = initMap();
	//맵 경계 생성
	createMapBorder(map);

	//첫 블럭 구조체 생성
	currentBlock = generateBlock();

	gotoxy(13, 2);
	printf("=====TETRIS=====\n");

	//생성된 블럭 구조체를 맵 배열에 추가(생성)
	settingBlock(map, currentBlock);
	gotoxy(13, 3);
	printf("Score : %d \n", score);
	while (1) {
		//블럭이 움직이지 못하는 위치일 경우에는 맵에 입력시켜버림
		//또는 특정 시간동안 움직임이 없을 경우
		if (!isBlockMovable(map, currentBlock) || ((blockFixCount >= blockFixRate) && isBlockBottom(map, currentBlock))) {
			//블럭을 현 위치 맵에 고정시킴
			fixBlock(map, currentBlock);
			//이전 블럭 삭제
			deleteBlock(currentBlock);
			//새로운 블럭 구조체 생성
			currentBlock = generateBlock();
			//생성된 블럭 구조체를 맵 배열에 추가(생성)
			settingBlock(map, currentBlock);
			
			//블럭 고정과 관련된 변수 초기화
			blockFixCount = 0;
			blockDropCount = 0;
			score = score + isLineFull(map);
			gotoxy(13, 3);
			printf("Score : %d \n", score);
			if (isGameEnded(map)) {
				gotoxy(13, 4);
				printf("=====GAME OVER=====\n");
				break;
			}
			continue;
		}
		key = getKeyValue();
		if (key == VK_DOWN || key == VK_LEFT || key == VK_RIGHT) {
			moveBlock(map, key, currentBlock);
			blockFixCount = 0;
		}
		else if (key == VK_UP) {
			rotateBlock(map, key, currentBlock);
			blockFixCount = 0;
		}
		//아무 이동이 없을 경우 fixCount를 높여줌
		else {
			blockFixCount++;
		}
		Sleep(SPEED);

		//블럭 자동 드롭 시간 조정
		blockDropCount++;
		if (blockDropCount == blockDropRate) {
			moveBlock(map, VK_DOWN, currentBlock);
			blockDropCount = 0;
		}

	}
	//동적 할당 받음 맵 삭제
	deleteMap(map);
	return;
}
int isGameEnded(int** map) {
	int i = 0;
	//블럭이 맵을 벗어났는지 확인
	for (i = 1; i < mapWidth - 1; i++) {
		if (map[4][i] == MAP_BLOCK_FIXED) {
			return 1;
		}
	}
	return 0;
}