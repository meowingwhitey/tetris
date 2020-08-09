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

int moveBlock(int ** map, int key, Block* block) {
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
	if (isBlockCollision(map, block, diff)) {
		//블럭 이동 X일때
		return 0;
	}
	/*gotoxy(13, 4);
	printf("[%d, %d] \n", block->pos.X, block->pos.Y);
	gotoxy(13, 5);
	printf("[*] blockType : %d\n",block->type);
	gotoxy(13, 6);
	printf("[*] blockRotate : %d\n", block->rotate);
	*/
	//X축
	for (i = 0; i < 4; i++) {
		//Y축
		for (j = 0; j < 4; j++) {
			if (blockShape[block->type][block->rotate][j][i] == 1) {
				//이전 블럭을 창에서 지워줌
				//실제 맵이랑 출력되는 맵은 Y축에서 4의 차이가 있으므로
				//이를 맞추기 위해 출력할때 -4의 가중치를 채워줌
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
	//블럭 이동 O일때
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
	//이동할 위치
	COORD pos = { 0, 0 };

	pos.X = block->pos.X + diff.X;
	pos.Y = block->pos.Y + diff.Y;
	//블럭은 위로는 쌓일 수 있음
	//블럭이 위로 충돌할 시에는 게임이 끝난 것이므로 이후 게임진행시 처리해주어야함
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

//일단은 VK_UP시 회전하는 것까지만 구현
int rotateBlock(int** map, int key, Block* block) {
	int i, j;
	//이전 rotate 값
	int prevRotate;
	//충돌 체크시 diff를 { 0, 0 }으로 줌
	//block->rotate 값을 일시적으로 변경 후
	//충돌 확인시 기존 값으로 복원하여 충돌 방지
	prevRotate = block->rotate;
	block->rotate = (block->rotate + 1) % 4;
	if (isBlockCollision(map, block, {0, 0})) {
		//블럭 회전X일때
		block->rotate = prevRotate;
		return 0;
	}
	//X축
	for (i = 0; i < 4; i++) {
		//Y축
		for (j = 0; j < 4; j++) {
			if (blockShape[block->type][prevRotate][j][i] == 1) {
				//이전 블럭을 창에서 지워줌
				//실제 맵이랑 출력되는 맵은 Y축에서 4의 차이가 있으므로
				//이를 맞추기 위해 출력할때 -4의 가중치를 채워줌
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
				if (block->pos.Y + j - 4 > 0) {
					gotoxy(block->pos.X + i, block->pos.Y + j - 4);
					printf("■");
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
	//블럭 회전 O
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