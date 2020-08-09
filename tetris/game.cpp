#include "game.h"

Block block;
void runGame(void) {
	int** map, i, j;
	int score = 0;
	//while�� �ݺ� Ƚ���� ���Ͽ� ���� �������� �ӵ� ����
	int blockDropCount = 0;
	int blockDropRate = 5;

	//�� ���� �ð�
	int blockFixCount = 0;
	int blockFixRate = 4;

	int key;
	Block * currentBlock ;
	//Ŀ�� ������ ����
	cursorView(0);
	//2���� ���� �������� �Ҵ� ����
	map = initMap();
	//�� ��� ����
	createMapBorder(map);

	//ù �� ����ü ����
	currentBlock = generateBlock();

	gotoxy(13, 2);
	printf("=====TETRIS=====\n");

	//������ �� ����ü�� �� �迭�� �߰�(����)
	settingBlock(map, currentBlock);
	gotoxy(13, 3);
	printf("Score : %d \n", score);
	while (1) {
		//���� �������� ���ϴ� ��ġ�� ��쿡�� �ʿ� �Է½��ѹ���
		//�Ǵ� Ư�� �ð����� �������� ���� ���
		if (!isBlockMovable(map, currentBlock) || ((blockFixCount >= blockFixRate) && isBlockBottom(map, currentBlock))) {
			//���� �� ��ġ �ʿ� ������Ŵ
			fixBlock(map, currentBlock);
			//���� �� ����
			deleteBlock(currentBlock);
			//���ο� �� ����ü ����
			currentBlock = generateBlock();
			//������ �� ����ü�� �� �迭�� �߰�(����)
			settingBlock(map, currentBlock);
			
			//�� ������ ���õ� ���� �ʱ�ȭ
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
		//�ƹ� �̵��� ���� ��� fixCount�� ������
		else {
			blockFixCount++;
		}
		Sleep(SPEED);

		//�� �ڵ� ��� �ð� ����
		blockDropCount++;
		if (blockDropCount == blockDropRate) {
			moveBlock(map, VK_DOWN, currentBlock);
			blockDropCount = 0;
		}

	}
	//���� �Ҵ� ���� �� ����
	deleteMap(map);
	return;
}
int isGameEnded(int** map) {
	int i = 0;
	//���� ���� ������� Ȯ��
	for (i = 1; i < mapWidth - 1; i++) {
		if (map[4][i] == MAP_BLOCK_FIXED) {
			return 1;
		}
	}
	return 0;
}