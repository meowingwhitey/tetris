#include "lib.h"

void gotoxy(int x, int y) {
	//■는 칸을 두개 먹음
	COORD pos = { x * 2, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//커서 옵션
//1 : 커서 생성, 0 : 커서 삭제
void cursorView(char show)
{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

int getKeyValue(void) {
	//키 입력 받음
	if (GetAsyncKeyState(VK_UP) != 0) {
		gotoxy(13, 3);
		printf("[*]Current Key : VK_UP    ");
		return VK_UP;
	}
	if (GetAsyncKeyState(VK_DOWN) != 0) {
		gotoxy(13, 3);
		printf("[*]Current Key : VK_DOWN    ");
		return VK_DOWN;
	}
	if (GetAsyncKeyState(VK_RIGHT) != 0) {
		gotoxy(13, 3);
		printf("[*]Current Key : VK_RIGHT    ");
		return VK_RIGHT;
	}
	if (GetAsyncKeyState(VK_LEFT) != 0) {
		gotoxy(13, 3);
		printf("[*]Current Key : VK_LEFT    ");
		return VK_LEFT;
	}
	if (GetAsyncKeyState(VK_SPACE) != 0) {
		gotoxy(13, 3);
		printf("[*]Current Key : VK_SPACE");
		return VK_SPACE;
	}
	return 0;
}