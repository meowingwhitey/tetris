#include "lib.h"

void gotoxy(int x, int y) {
	//��� ĭ�� �ΰ� ����
	COORD pos = { x * 2, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//Ŀ�� �ɼ�
//1 : Ŀ�� ����, 0 : Ŀ�� ����
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
	//Ű �Է� ����
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