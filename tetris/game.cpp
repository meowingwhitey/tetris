#include "game.h"

Block block;
void runGame(void) {
	int** map;
	Block * currentBlock ;
	cursorView(0);
	//2���� ���� �������� �Ҵ� ����
	map = initMap();
	//�� ��� ����
	createMapBorder();

	//ù �� ����ü ����
	currentBlock = generateBlock();

	//������ �� ����ü�� �ʿ� ����
	settingBlock(map, currentBlock);
	while (1) {
		moveBlock(map, getKeyValue(), currentBlock);

		//malloc���� ������ �� ����
		//deleteBlock(*currentBlock);
		//�� ���ΰ�ħ
		refreshMap();
	}
	//���� �Ҵ� ���� �� ����
	deleteMap(map);
	return;
}