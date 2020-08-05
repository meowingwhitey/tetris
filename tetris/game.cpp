#include "game.h"

Block block;
void runGame(void) {
	int** map;
	Block * currentBlock ;
	cursorView(0);
	//2차원 맵을 동적으로 할당 받음
	map = initMap();
	//맵 경계 생성
	createMapBorder();

	//첫 블럭 구조체 생성
	currentBlock = generateBlock();

	//생성된 블럭 구조체를 맵에 고정
	settingBlock(map, currentBlock);
	while (1) {
		moveBlock(map, getKeyValue(), currentBlock);

		//malloc으로 생성된 블럭 삭제
		//deleteBlock(*currentBlock);
		//맵 새로고침
		refreshMap();
	}
	//동적 할당 받음 맵 삭제
	deleteMap(map);
	return;
}