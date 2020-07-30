#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<Windows.h>

const int mapWidth = 10;
const int mapHeight = 20;

int mapValue[mapWidth][mapHeight];

const int blockShape[7][4][4][4] = {
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

void gotoxy(int x, int y);
void makeMapGrid(void);
void moveBlock(int key);
int main(void) {
	int i, j;
	int key = 0;
	int current_block, current_block_state;
	srand((unsigned int)time(NULL));
	current_block = rand() % 7;
	current_block_state = 0;
	for (i = 0; i < mapWidth; i++) {
		for (j = 0; j < mapHeight; j++) {
			mapValue[i][j] = 0;
		}
	}
	makeMapGrid();
	while (1) {
		if (GetAsyncKeyState(VK_UP) != 0) {
			gotoxy(13, 3);
			printf("                                     ");
			gotoxy(13, 3);
			printf("[*]Current Key : VK_UP");
			moveBlock(VK_UP);
		}
		if (GetAsyncKeyState(VK_DOWN) != 0) {
			gotoxy(13, 3);
			printf("                                     ");
			gotoxy(13, 3);
			printf("[*]Current Key : VK_DOWN");
			moveBlock(VK_DOWN);
		}
		if (GetAsyncKeyState(VK_RIGHT) != 0) {
			gotoxy(13, 3);
			printf("                                     ");
			gotoxy(13, 3);
			printf("[*]Current Key : VK_RIGHT");
			moveBlock(VK_RIGHT);
		}
		if (GetAsyncKeyState(VK_LEFT) != 0) {
			gotoxy(13, 3);
			printf("                                     ");
			gotoxy(13, 3);
			printf("[*]Current Key : VK_LEFT");
			moveBlock(VK_LEFT);
		}
		if (GetAsyncKeyState(VK_SPACE) != 0) {
			gotoxy(13, 3);
			printf("                                     ");
			gotoxy(13, 3);
			printf("[*]Current Key : VK_SPACE");
			moveBlock(VK_SPACE);
		}
	}
}
void makeMapGrid(void) {
	int i, j;
	gotoxy(0, 0);
	for (i = 0; i <= mapWidth + 1; i++) {
		printf("■");
	}
	for (i = 1; i <= mapHeight; i++) {
		gotoxy(0, i);
		printf("■");
		for (j = 1; j <= mapWidth; j++) {
			printf("□");
		}
		printf("■");
	}
	gotoxy(0, mapHeight + 1);
	for (i = 0; i <= mapWidth + 1; i++) {
		printf("■");
	}
}
void gotoxy(int x, int y) {
	//■는 칸을 두개 먹음
	COORD pos = { x * 2,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void moveBlock(int key) {

}