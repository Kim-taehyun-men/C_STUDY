

#include <windows.h>
#include <stdio.h>


void Clear(void)
{
	system("cls");
}

void GotoXY(int _x, int _y)
{
	COORD pos ;
	pos.X = _x;
	pos.Y = _y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void SetTitle(const char* szConsoleName)
{
	SetConsoleTitle(szConsoleName);
}

void SetColor(unsigned char _BgColor, unsigned char _TextColor)
{
	if (_BgColor > 15 || _TextColor > 15) return;

	unsigned short ColorNum = (_BgColor << 4) | _TextColor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNum);
}

void SetMyCursor(BOOL _bShow)
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = _bShow;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

void SetConsoleSize(int _col, int _lines)
{
	char setText[100];
	sprintf_s(setText, "mode con cols=%d lines=%d", _col, _lines);
	system(setText);
}