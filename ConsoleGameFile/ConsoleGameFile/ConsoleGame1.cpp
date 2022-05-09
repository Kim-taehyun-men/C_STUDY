#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "Console.h"
#define MAX  30
#define BACKCOLOR 15

struct ST_OBJECT
{
	int x = 0;
	int y = 0;
	bool bActive = false;
};

ST_OBJECT g_stEnemy[MAX];
ST_OBJECT g_stPlayer;
int g_iScore = 0;

void Spawn(void)
{
	for (int i = 0; i < MAX; i++) {
		if (!g_stEnemy[i].bActive)
		{
			g_stEnemy[i].x = (rand() % 15) * 2;
			g_stEnemy[i].y = 0;
			g_stEnemy[i].bActive = true;
			break;
		}
	}
}

int EnemyProcess(void)
{
	int count = 0;
	for (int i = 0; i < MAX; i++)
	{
		if (g_stEnemy[i].bActive)
		{	
			count++;
			GotoXY(g_stEnemy[i].x, g_stEnemy[i].y);
			printf("��");
			g_stEnemy[i].y++;

			// �浹
			if (g_stEnemy[i].y == g_stPlayer.y && g_stEnemy[i].x == g_stPlayer.x)
			{
				g_stPlayer.bActive = false;
			}

			// ���� ������� ��
			if (g_stEnemy[i].y > g_stPlayer.y)
			{
				g_stEnemy[i].bActive = false;
			}
		}
	}
	return count;
}

void InputProcess(void)
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		g_stPlayer.x-=2;
		if (g_stPlayer.x < 0) g_stPlayer.x = 0;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		g_stPlayer.x+=2;
		if (g_stPlayer.x > 28) g_stPlayer.x = 28;
	}

}

void Update(void)
{
	if(g_stPlayer.bActive)
	{
		GotoXY(g_stPlayer.x, g_stPlayer.y);
		printf("��");
	}
	else
	{	
		GotoXY(g_stPlayer.x, g_stPlayer.y);
		printf("��");
	}
	
}

void Score(void)
{
	if (g_stPlayer.bActive == true)
	{
		g_iScore++;
	}
	GotoXY(0, 0);
	printf("���� : %d", g_iScore);
}

void Init(void)
{
	g_stPlayer.x = 14, g_stPlayer.y = 28;
	g_stPlayer.bActive = true;
	srand(time(NULL));
	SetConsoleSize(30, 30);

	SetTitle("�����ϱ�");
	SetColor(BACKCOLOR, 0);
}



void StartMenu(void)
{
	while (1)
	{
		if (_kbhit()) 
		{
			getch();
		}
		else
		{
			break;
		}
	} // Resultâ������ Y/N�� ���۰� ����
	while (1)
	{
		Clear();
		GotoXY(10, 9);
		printf("�� ���ϱ�");
		GotoXY(10, 20);
		printf("Press any key ... ");
		if (_kbhit()) break; // �ƹ�Ű�� ������ break����
		Sleep(50);
	}
}

void GameMain(void)
{
	int state = 0;
	g_stPlayer.x = 14, g_stPlayer.y = 28;
	g_stPlayer.bActive = true;
	int g_iScore = 0;
	while (1)
	{
		Clear();
		if (g_stPlayer.bActive)
		{
			// ���� �����ϴ� �κ�
			Spawn();

			// input ó��
			InputProcess();
		}
		//�� ó��
		state = EnemyProcess();

		// player ���
		Update();

		// ���� ó��
		Score();

		Sleep(50);
		if (state == 0)
		{
			break;
		}
	}
}

bool Resultmenu(void)
{
	bool bRet = false;
	while (1)
	{
		Clear();
		GotoXY(10, 9);
		printf("Result Menu");
		GotoXY(10, 15);
		printf("Score : %d", g_iScore);
		GotoXY(5, 24);
		printf("continue ... Y/N");
		if (GetAsyncKeyState('Y') & 0x8000)
		{
			bRet = false;
			break;
		}
		if (GetAsyncKeyState('N') & 0x8000)
		{
			bRet = true;
			break;
		}
		Sleep(50);
	}
	return bRet;
}

int main(void)
{	
	Init();
	while (1)
	{
		StartMenu();
		GameMain();
		if (Resultmenu()) break;
	}
	return 0;
}