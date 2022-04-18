#include "game.h"

//初始化
void InitBoard(char board[ROWS][COLS], int rows, int cols, char init)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = init;
		}
	}
}

//显示，外面扩充的那一圈不用打印，所以传过来的行和列是row，col
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int k = 0;
	//1. 最顶部显示列数
	for (i = 1; i <= col; i++)
	{
		if (i == 1)
			printf("   %d ", i);
		else
			printf("  %d ", i);
	}
	//换行
	printf("\n");

	//2. 顶部线
	for (i = 1; i <= col; i++)
	{
		//除最后一列外都要带上---
		if (i == 1)
		{
			printf(" ");
		}
		printf(" ---");
	}
	//换行
	printf("\n");

	//3. 数据行和分割行
	for (i = 1; i <= row; i++)
	{
		//1.打印一行数据
		for (j = 0; j <= col; j++)
		{
			//最左侧显示列数
			if (j == 0)
			{
				printf("%d", i);
			}
			else if (j != col)
			{
				printf("| %c ", board[i][j]);
			}
			else
			{
				printf("| %c |", board[i][j]);
			}
		}
		//换行
		printf("\n");

		//2.打印分割行；
		for (k = 1; k <= col; k++)
		{
			if (k == 1)
			{
				printf(" ");
			}
			//---
			printf(" ---"); 
		}
		//打印完分割行也要换行
		printf("\n");
	}
}

//布雷
void PlaceMines(char board[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int i = 0;
	//地雷用字符1表示
	for (i = 0; i < MINE_NUM; i++)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		//避免重复
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
		}
	}
}

//计算周围地雷的个数
int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	//'1'-'0'=1;
	//'3'-'0'=3;
	//把周围的字符都减去'0'，就可以实现字符数转整型数，妙啊~
	//只有0和1，把周围的8个数加起来是几就说明有几个1（地雷）
	return mine[x - 1][y - 1] +
		   mine[x - 1][y] +
		   mine[x - 1][y + 1] +
		   mine[x][y - 1] +
		   mine[x][y + 1] +
		   mine[x + 1][y - 1] +
		   mine[x + 1][y] +
		   mine[x + 1][y + 1] - 8 * '0';
}

//智能展开功能
//1. 自己不是雷
//2. 该坐标周围没有雷
//3. 周围每个坐标都满足上面两个条件
//递归
void IntellUnfold(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	//如果是雷，则提示失败
	if (mine[x][y] == '1')
	{
		printf("***很遗憾!你被炸死了~***\n");
		DisplayBoard(mine, ROW, COL);
	}
	//1. 如果不是雷，要显示周围地雷的个数
	else
	{
		//周围地雷的个数
		int mine_count = GetMineCount(mine, x, y);
		//2. 如果周围没有雷
		if (mine_count == 0)
		{
			show[x][y] = ' ';
			//遍历周围的格子
			int arrx[] = { x - 1,x,x + 1 };
			int arry[] = { y - 1,y,y + 1 };
			int i = 0;
			int j = 0;
			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < 3; j++)
				{
					//除了自己以外的其他格子
					if (i != 1 || j != 1)
					{
						IntellUnfold(mine, show, arrx[i], arry[j]);
					}
				}
			}
		}
		else
		{
			//show显示周围雷的个数，加'0'是为了将整型转成字符型
			show[x][y] = mine_count + '0';
		}
	}
}

//扫雷
void SweapMines(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	//非地雷格的最大数
	int not_mine_num_max = row * col - MINE_NUM;
	//扫出来的非地雷格计数器
	int not_mine_count = 0;
	//当非地雷格数量没有达到最大时，继续游戏
	while (not_mine_count < not_mine_num_max)
	{
		//坐标
		int x = 0;
		int y = 0;
		printf("***请输入坐标：--> ");
		scanf_s("%d%d", &x, &y);
		//判定输入合法性
		//不合法就重新输入
		if (x < 1 || x > row || y < 1 || y > col)
		{
			printf("***请输入1~%d之间的坐标值！***", row);
		}
		//合法
		else
		{
			//合法则智能展开
			IntellUnfold(mine, show, x, y);
			DisplayBoard(show, ROW, COL);
		}
		//非雷格个数+1
		not_mine_count++;
	}
	if (not_mine_count == not_mine_num_max)
	{
		//达到最大，没有踩到雷，则提示游戏成功！然后选择继续玩还是退出
		printf("***恭喜通关^-^***\n");
	}
}