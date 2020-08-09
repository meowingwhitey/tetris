#include "block.h"

extern const int blockShape[7][4][4][4] = {
	//0
	// #
	//### Shape Block
	{
		{
			{0, 1, 0, 0},
			{1, 1, 1, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{1, 0, 0, 0},
			{1, 1, 0, 0},
			{1, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{1, 1, 1, 0},
			{0, 1, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 1, 0, 0},
			{1, 1, 0, 0},
			{0, 1, 0, 0},
			{0, 0, 0, 0}
		}
	},
	//1
	//##
	//## Shape Block
	{
		{
			{1, 1, 0, 0},
			{1, 1, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{1, 1, 0, 0},
			{1, 1, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{1, 1, 0, 0},
			{1, 1, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{1, 1, 0, 0},
			{1, 1, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		}
	},
	//2
	//##
	// ## Shape Block
	{
		{
			{1, 1, 0, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 1, 0, 0},
			{1, 1, 0, 0},
			{1, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{1, 1, 0, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 1, 0, 0},
			{1, 1, 0, 0},
			{1, 0, 0, 0},
			{0, 0, 0, 0}
		}
	},
	//3
	// ##
	//## Shape Block
	{
		{
			{0, 1, 1, 0},
			{1, 1, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{1, 0, 0, 0},
			{1, 1, 0, 0},
			{0, 1, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 1, 1, 0},
			{1, 1, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{1, 0, 0, 0},
			{1, 1, 0, 0},
			{0, 1, 0, 0},
			{0, 0, 0, 0}
		}
	},
	//4
	//####
	//Shape Block
	{
		{
			{1, 0, 0, 0},
			{1, 0, 0, 0},
			{1, 0, 0, 0},
			{1, 0, 0, 0}
		},
		{
			{1, 1, 1, 1},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{1, 0, 0, 0},
			{1, 0, 0, 0},
			{1, 0, 0, 0},
			{1, 0, 0, 0}
		},
		{
			{1, 1, 1, 1},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		}
	},
	//5
	//#
	//### Shape Block
	{
		{
			{1, 0, 0, 0},
			{1, 1, 1, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{1, 1, 0, 0},
			{1, 0, 0, 0},
			{1, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{1, 1, 1, 0},
			{0, 0, 1, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 1, 0, 0},
			{0, 1, 0, 0},
			{1, 1, 0, 0},
			{0, 0, 0, 0}
		}
	},
	//6
	//  #
	//### Shape Block
	{
		{
			{0, 0, 1, 0},
			{1, 1, 1, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{1, 0, 0, 0},
			{1, 0, 0, 0},
			{1, 1, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{1, 1, 1, 0},
			{1, 0, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{1, 1, 0, 0},
			{0, 1, 0, 0},
			{0, 1, 0, 0},
			{0, 0, 0, 0}
		}
	}
};
void settingBlock(int** map, Block* block) {
	int i = 0, j = 0;
	//�� ���� ��ġ
	COORD center;
	//���� ���� �Ʒ� �� ���
	int blockBase = 0;//���� ���� �Ʒ���
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (blockShape[block->type][block->rotate][i][j]) {
				blockBase++;
				break;
			}
		}
	}
	//�� ���� ��ġ �ʱ�ȭ �� �� ����ü�� �� ��ġ ����
	center.X = 4;
	center.Y = 4 - blockBase;
	block->pos.X = center.X;
	block->pos.Y = center.Y;

	//�� ���� ��ġ�� �� ����
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			map[center.X][center.Y] = blockShape[block->type][block->rotate][i][j];
		}
	}
	return;
}

int moveBlock(int ** map, int key, Block* block) {
	int i, j;
	//���� Ű�� ���� �̵� ��
	COORD diff = {0, 0};
	switch (key) {
	case VK_UP:
		diff = {0, -1};
		break;
	case VK_DOWN:
		diff = {0, 1};
		break;
	case VK_LEFT:
		diff = {-1, 0};
		break;
	case VK_RIGHT:
		diff = {1, 0};
		break;
	default:
		break;
	}
	if (isBlockCollision(map, block, diff)) {
		//�� �̵� X�϶�
		return 0;
	}
	/*gotoxy(13, 4);
	printf("[%d, %d] \n", block->pos.X, block->pos.Y);
	gotoxy(13, 5);
	printf("[*] blockType : %d\n",block->type);
	gotoxy(13, 6);
	printf("[*] blockRotate : %d\n", block->rotate);
	*/
	//X��
	for (i = 0; i < 4; i++) {
		//Y��
		for (j = 0; j < 4; j++) {
			if (blockShape[block->type][block->rotate][j][i] == 1) {
				//���� ���� â���� ������
				//���� ���̶� ��µǴ� ���� Y�࿡�� 4�� ���̰� �����Ƿ�
				//�̸� ���߱� ���� ����Ҷ� -4�� ����ġ�� ä����
				if (block->pos.Y + j - 4 > 0) {
					gotoxy(block->pos.X + i, block->pos.Y + j - 4);
					printf("  ");
				}

			}
		}
	}
	//X��
	for (i = 0; i < 4; i++) {
		//Y��
		for (j = 0; j < 4; j++) {
			if (blockShape[block->type][block->rotate][j][i] == 1) {
				if (block->pos.Y + j - 4 + diff.Y > 0) {
					gotoxy(block->pos.X + diff.X + i, block->pos.Y + diff.Y + j - 4);
					printf("��");
				}
			}
		}
	}
	block->pos.X = block->pos.X + diff.X;
	block->pos.Y = block->pos.Y + diff.Y;
	//�� �̵� O�϶�
	return 1;
}

Block * generateBlock(void) {
	Block * block;
	block = (Block*)malloc(sizeof(Block));
	srand((unsigned int)time(NULL));
	block->type = rand() % 7;
	block->rotate = 0;
	block->pos.X = 0;
	block->pos.Y = 0;
	return block;
}

void deleteBlock(Block* block) {
	free(block);
	return;
}

int isBlockCollision(int** map, Block* block, COORD diff) {
	int i, j;
	//�̵��� ��ġ
	COORD pos = { 0, 0 };

	pos.X = block->pos.X + diff.X;
	pos.Y = block->pos.Y + diff.Y;
	//���� ���δ� ���� �� ����
	//���� ���� �浹�� �ÿ��� ������ ���� ���̹Ƿ� ���� ��������� ó�����־����
	//pos.Y = block->pos.Y + diff.Y - 4;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (blockShape[block->type][block->rotate][j][i] == 1) {
				if ((map[pos.Y + j][pos.X + i] == MAP_BORDER) || (map[pos.Y + j][pos.X + i] == MAP_BLOCK_FIXED)) {
					return 1;
				}
			}
		}
	}
	return 0;
}

//�ϴ��� VK_UP�� ȸ���ϴ� �ͱ����� ����
int rotateBlock(int** map, int key, Block* block) {
	int i, j;
	//���� rotate ��
	int prevRotate;
	//�浹 üũ�� diff�� { 0, 0 }���� ��
	//block->rotate ���� �Ͻ������� ���� ��
	//�浹 Ȯ�ν� ���� ������ �����Ͽ� �浹 ����
	prevRotate = block->rotate;
	block->rotate = (block->rotate + 1) % 4;
	if (isBlockCollision(map, block, {0, 0})) {
		//�� ȸ��X�϶�
		block->rotate = prevRotate;
		return 0;
	}
	//X��
	for (i = 0; i < 4; i++) {
		//Y��
		for (j = 0; j < 4; j++) {
			if (blockShape[block->type][prevRotate][j][i] == 1) {
				//���� ���� â���� ������
				//���� ���̶� ��µǴ� ���� Y�࿡�� 4�� ���̰� �����Ƿ�
				//�̸� ���߱� ���� ����Ҷ� -4�� ����ġ�� ä����
				if (block->pos.Y + j - 4 > 0) {
					gotoxy(block->pos.X + i, block->pos.Y + j - 4);
					printf("  ");
				}

			}
		}
	}
	//X��
	for (i = 0; i < 4; i++) {
		//Y��
		for (j = 0; j < 4; j++) {
			if (blockShape[block->type][block->rotate][j][i] == 1) {
				if (block->pos.Y + j - 4 > 0) {
					gotoxy(block->pos.X + i, block->pos.Y + j - 4);
					printf("��");
				}
			}
		}
	}
	//gotoxy(13, 4);
	//printf("[%d, %d] \n", block->pos.X, block->pos.Y);
	//gotoxy(13, 5);
	//printf("[*] blockType : %d\n", block->type);
	//gotoxy(13, 6);
	//printf("[*] blockRotate : %d\n", block->rotate);
	//�� ȸ�� O
	return 1;
}
int fixBlock(int ** map, Block * block) {
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (blockShape[block->type][block->rotate][j][i] == 1) {
				map[block->pos.Y + j][block->pos.X + i] = MAP_BLOCK_FIXED;
			}
		}
	}
	return 1;
}

int isBlockMovable(int** map, Block* block) {
	if (isBlockCollision(map, block, {0, 1}) && isBlockCollision(map, block, { 1, 0 }) && isBlockCollision(map, block, { -1, 0 })) {
		return 0;
	}
	return 1;
}

int isBlockBottom(int** map, Block* block) {
	if (isBlockCollision(map, block, { 0, 1 })) {
		return 1;
	}
	return 0;
}