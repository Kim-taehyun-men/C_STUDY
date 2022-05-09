#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include "Console.h"

char g_item[][10][30] =
{
	{
	"□□□□■■□■■□",
	"□□□□■■□■■□",
	"□□□□■■□■■□",
	"□□□□■■□■■□",
	"□□□□■■□■■□",
	"□■■■■■■■■□",
	"□□■■■■■■■□",
	"□□■■■■■■■□",
	"□□■■■■■■■□",
	"□□■■■■■■■□",
	},
	{
	"□□□□□□□□□□",
	"□□□□□□□□□□",
	"□□□□□□□□□□",
	"□□■■■■■■■□",
	"□□■■■■■■■□",
	"□■■■■■■■■□",
	"□□■■■■■■■□",
	"□□■■■■■■■□",
	"□□■■■■■■■□",
	"□□■■■■■■■□",
	},
		{
	"□■□■□■□■□□",
	"□■□■□■□■□□",
	"□■□■□■□■□■",
	"□■□■□■□■□■",
	"□■□■□■□■□■",
	"□■■■■■■■■□",
	"□□■■■■■■■□",
	"□□■■■■■■■□",
	"□□■■■■■■■□",
	"□□■■■■■■■□",
	}
};
char g_vsText[][20] =
{
	"■□□■□■■□",
	"■□□■■□□□",
	"■□□■■□□□",
	"■□□■■■■□",
	"■□□■□□□■",
	"□■■□□□□■",
	"□■■□■■■□",
	
};
int g_result[3][3] =
{
	{0, -1, 1},
	{1, 0, -1},
	{-1, 1, 0}
};
void printXY(int _x, int _y, const char* _text)
{
	GotoXY(_x, _y);
	printf(_text);
}
void print2DXY(int _x, int _y, int _sizeX, int _sizeY, char* _text)
{
	char* temp = _text;
	for (int y = 0; y < _sizeY; ++y)
	{
		printXY(_x, _y + y, temp);
		temp += _sizeX;
	}
}

void startMenu(void)
{
	int com = 0, player = 0, count = 0;
	char key = 0;
	Clear();
	while (1)
	{
		if (count == 0)
		{
			com = rand() % 3;
			count = 15;
			player++;
		}
		--count;

		if (_kbhit())
		{
			_getch();
			break;
		}

		SetColor(0, 10);
		print2DXY(12, 5, sizeof(g_item[player % 3][0]), sizeof(g_item[player % 3]) / sizeof(g_item[player % 3][0]), (char*)g_item[player % 3]);
		SetColor(0, 12);
		print2DXY(48, 5, sizeof(g_item[com][0]), sizeof(g_item[com]) / sizeof(g_item[com][0]), (char*)g_item[com]);
		SetColor(0, 8);
		if (player % 2 == 0)
			printXY(26, 17, "시작하려면 아무키나 누르세요...");
		else
			printXY(26, 17, "                                 ");
		Sleep(33);

	}
}

void ResultMenu(int player, int com)
{
	int result = 0;
	char szResult[3][10] = { "패", "무", "승" };

	SetColor(0, 10);
	print2DXY(12, 5, sizeof(g_item[player % 3][0]), sizeof(g_item[player % 3]) / sizeof(g_item[player % 3][0]), (char*)g_item[player % 3]);
	SetColor(0, 12);
	print2DXY(48, 5, sizeof(g_item[com][0]), sizeof(g_item[com]) / sizeof(g_item[com][0]), (char*)g_item[com]);
	SetColor(0, 15);
	print2DXY(32, 8, sizeof(g_vsText[0]), sizeof(g_vsText) / sizeof(g_vsText[0]), (char*)g_vsText);

	result = g_result[player][com];
	printXY(39, 20, szResult[result + 1]);

	while (1)
	{
		if (_kbhit());
		{
			_getch();
			break;
		}
		
	}

}

void Gamemain()
{
	int com = 0, player = 0, count = 0;
	int result = 0;
	char key = 0;
	char szResult[3][10] = { "패", "무", "승" };
	Clear();
	while (1)
	{
		if (count == 0)
		{
			com = rand() % 3;
			count = 10;
			player++;
		}
		--count;

		if (_kbhit())
		{
			key = _getch();
			if (key == '27') // esc
			{
				break;
			}
			if (key >= '0' && key <= '2')
			{
				player = key - '0';
				com = rand() % 3;

				ResultMenu(player, com);
				break;
			}

		}

		SetColor(0, 10);
		print2DXY(12, 5, sizeof(g_item[player % 3][0]), sizeof(g_item[player % 3]) / sizeof(g_item[player % 3][0]), (char*)g_item[player % 3]);
		SetColor(0, 12);
		print2DXY(48, 5, sizeof(g_item[com][0]), sizeof(g_item[com]) / sizeof(g_item[com][0]), (char*)g_item[com]);
		SetColor(0, 15);
		print2DXY(32, 8, sizeof(g_vsText[0]), sizeof(g_vsText) / sizeof(g_vsText[0]), (char*)g_vsText);
		printXY(22, 17, "가위(0), 바위(1), 보(2) 중에 선택하세요  ");
		Sleep(50);

	}
}
int main(void)
{
	int player = 0, com = 0, result = 0;
	char szResult[3][10] = { "패", "무", "승"};
	

	srand(time(NULL));
	while (1)
	{
		startMenu();
		Gamemain();
	}
	return 0;
}