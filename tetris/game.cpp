#include "game.h"

Block block;
void runGame(void) {
	int** map;
	int key;Block * currentBlock ;
	//Ŀ�� ������ ����
	cursorView(0);
	//2���� ���� �������� �Ҵ� ����
	map = initMap();
	//�� ��� ����
	createMapBorder(map);

	//ù �� ����ü ����
	currentBlock = generateBlock();

	//������ �� ����ü�� �� �迭�� �߰�(����)
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
		//���� ������ malloc���� ������ �� ����
		//deleteBlock(*currentBlock);
	}
	//���� �Ҵ� ���� �� ����
	deleteMap(map);
	return;
}