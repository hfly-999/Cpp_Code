#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void InitBoard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < ROW; i++)for (int j = 0; j < COL; j++)
		board[i][j] = ' ';
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	/*printf("  %c| %c | %c \n---|---|---\n", board[0][0], board[0][1], board[0][2]);
	printf("  %c| %c | %c \n---|---|---\n", board[1][0], board[1][1], board[1][2]);
	printf("  %c| %c | %c \n", board[2][0], board[2][1], board[2][2]);*/
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < COL - 1)printf("|");
		}
		printf("\n");
		if (i < ROW - 1)for (int m = 0; m < COL; m++)
		{
			if (m < COL - 1)printf("---|");
			else printf("---\n");
		}
	}
	printf("\n");

}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("player please enter site ->\n");
		scanf("%d%d", &x, &y);
		if ((x<1 || x>COL) || (y < 1 || y>3))printf("site is out of ranger!\nplease enter right site again");
		else
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = { '#' };
				break;
			}
			else printf("The site has been dominated,please enter another site");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("computer move->\n");
	while (1)
	{
		x = rand() % col;
		y = rand() % ROW;
		if (board[x][y] == ' ')
		{
			board[x][y] = { '*' };
			break;
		}
	}
}

bool judge(char board[ROW][COL])
{
	for (int i = 0; i < ROW ; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == '#' || board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == '#' )
		{
			printf("player win!\n");
			return true;
		}
	}
	if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == '#'|| board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] == '#')
	{
		printf("player win!\n");
		return true;
	}
	for (int i = 0; i < ROW ; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == '*' || board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == '*' )
		{
			printf("computer win!\n");
			return true;
		}
	}
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == '*' || board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] == '*')
	{
		printf("computer win!\n");
		return true;
	}
	for (int i = 0; i < ROW ; i++)for (int j = 0; j < COL ; j++)if (board[i][j] == ' ')return false;
	
	printf("equal\n");
	return true;
	
}

void menu()
{
	printf("**************************************\n");
	printf("******  <  1.play   0.exit  >  *******\n");
	printf("**************************************\n");
}

void game()
{
	//
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);//³õÊ¼»¯
	//display board
	DisplayBoard(board, ROW, COL);
	//pattern :
	while (1)
	{
		//player play && display && judge if win or beaten
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		if (judge(board) == true)break;
		//function return true or false
		//computer play && display
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		if (judge(board) == true)break;
	}

}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("please choose ->\n");
		scanf("%d", &input);
		switch (input)
		{
		case 0: printf("game exit	!\n"); break;
		case 1: printf("game start	!\n");
			game();
			break;
		default:printf("game error,please choose agagin	!\n"); break;

		}
	} while (input);
}


























