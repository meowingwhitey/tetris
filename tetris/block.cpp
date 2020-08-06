#include "block.h"
extern const int blockShape[7][4][4][4] = {
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
	//블럭 생성 위치
	COORD center;
	//블럭의 가장 아래 층 계산
	int blockBase = 0;//블럭의 가장 아랫층
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (blockShape[block->type][block->rotate][i][j]) {
				blockBase++;
				break;
			}
		}
	}
	//블럭 생성 위치 초기화 및 블럭 구조체에 블럭 위치 설정
	center.X = 4;
	center.Y = 4 - blockBase;
	block->pos.X = center.X;
	block->pos.Y = center.Y;

	//블럭 생성 위치에 블럭 생성
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			map[center.X][center.Y] = blockShape[block->type][block->rotate][i][j];
		}
	}
	return;
}

void moveBlock(int ** map, int key, Block* block) {
	int i, j;
	//블럭의 키에 따른 이동 값
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
	gotoxy(13, 4);
	printf("[%d, %d] \n", block->pos.X, block->pos.Y);
	//X축
	for (i = 0; i < 4; i++) {
		//Y축
		for (j = 0; j < 4; j++) {
			if (blockShape[block->type][block->rotate][j][i] == 1) {
				//이전 블럭을 창에서 지워줌
				if (block->pos.Y + j - 4 > 0) {
					gotoxy(block->pos.X + i, block->pos.Y + j - 4);
					printf("  ");
				}

			}
		}
	}
	//X축
	for (i = 0; i < 4; i++) {
		//Y축
		for (j = 0; j < 4; j++) {
			if (blockShape[block->type][block->rotate][j][i] == 1) {
				if (block->pos.Y + j - 4 + diff.Y > 0) {
					gotoxy(block->pos.X + diff.X + i, block->pos.Y + diff.Y + j - 4);
					printf("■");
				}
			}
		}
	}
	block->pos.X = block->pos.X + diff.X;
	block->pos.Y = block->pos.Y + diff.Y;
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