#include "game.h"

//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < row; i++)
	{
		//1.打印一行数据
		for (j = 0; j < col; j++)
		{
			//除最后一列外都要带上分列符|
			printf(" %c ", board[i][j]);
			if(j < col - 1)
				printf("|");
		}
		//打印完一行就换行
		printf("\n");

		//2.打印分隔行；
		if (i < row - 1)
		{
			//分割行---的数量随列数变动
			for (k = 0; k < col; k++)
			{
				//除最后一列外都要带上分列符 |
				printf("---");
				if (k < col - 1)
					printf("|");
			}
		}
		//打印完分割行也要换行
		printf("\n");
	}
}

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("******玩家回合******\n");
	while (1)
	{
		printf("请落子 --> ");
		scanf_s("%d%d", &x, &y);
		//防止输入的坐标超出棋盘范围,需判断输入合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//空处可以落子
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("瞎呀？！往哪儿杵呢？这儿有子！\n");
			}
		}
		//非法输入，予以提示
		else
		{
			printf("往哪儿瞅呢？下棋盘外边儿去啦~给你次机会，重新下一次！\n");
		}
	}
}

//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("******电脑回合******\n");
	//rand函数用于生成0~rand_max-1之间的随机整数，格式一般为：
	//x = rand() % rand_max + rand_min -- 生成rand_min~rand_max-1之间的随机整数
	//这里就表示生成0~row-1之间的整数
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		//空处可以落子
		if (board[x - 1][y - 1] == ' ')
		{
			board[x - 1][y - 1] = '#';
			break;
		}
	}
}

//判断棋盘是否满了
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;//没满
			}
		}
	}
	return 1;//满了
}

//判断输赢 C-继续，*-玩家赢，#-玩家输，D-平局
char IsWin(char board[ROW][COL], int row, int col)
{
	//判断行
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		//每次循环都要将计数器清0
		int count = 0;
		for (j = 0; j < col - 1; j++)
		{
			if (board[i][j] == board[i][j + 1] && board[i][j] != ' ')
			{
				count++;
			}
		}
		if (count == col - 1)
		{
			return board[i][j];
		}
	}

	//判断列
	for (j = 0; j < col; i++)
	{
		//每次循环都要将计数器清0
		int count = 0;
		for (i = 0; i < row - 1; i++)
		{
			if (board[i][j] == board[i+1][j] && board[i][j] != ' ')
			{
				count++;
			}
		}
		if (count == row - 1)
		{
			return board[i][j];
		}
	}

	//判断对角线
	int count1 = 0;
	int	count2 = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			//正对角线
			if (i == j && board[i][j] == board[i + 1][j + 1] && board[i][j] != ' ')
			{
				count1++;
			}
			//副对角线
			else if (i + j == row && board[i][j] == board[i + 1][j - 1] && board[i][j] != ' ')
			{
				count2++;
			}
		}
	}
	if (count1 == row)
		return board[0][0];
	if (count2 == row)
		return board[0][col - 1];

	//判断平局
	if (IsFull(board, row, col) == 1)
	{
		return 'D';
	}
	return 'C';
}