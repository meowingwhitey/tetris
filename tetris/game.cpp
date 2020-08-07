#include "game.h"

Block block;
void runGame(void) {
	int** map;
	int key;Block * currentBlock ;
	//커서 깜빡임 삭제
	cursorView(0);
	//2차원 맵을 동적으로 할당 받음
	map = initMap();
	//맵 경계 생성
	createMapBorder(map);

	//첫 블럭 구조체 생성
	currentBlock = generateBlock();

	//생성된 블럭 구조체를 맵 배열에 추가(생성)
	settingBlock(map, currentBlock);
	while (1) {
		key = getKeyValue();
		if (key == VK_DOWN || key == VK_LEFT || key == VK_RIGHT) {
			moveBlock(map, key, currentBlock);
		}
		else if (key == VK_UP) {
			rotateBlock(map, key, currentBlock);
		}
		Sleep(100);
		//블럭이 안착시 malloc으로 생성된 블럭 삭제
		//deleteBlock(*currentBlock);
	}
	//동적 할당 받음 맵 삭제
	deleteMap(map);
	return;
}