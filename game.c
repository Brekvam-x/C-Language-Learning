#include "game.h"

//��ʼ��
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

//��ʾ�������������һȦ���ô�ӡ�����Դ��������к�����row��col
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int k = 0;
	//1. �����ʾ����
	for (i = 1; i <= col; i++)
	{
		if (i == 1)
			printf("   %d ", i);
		else
			printf("  %d ", i);
	}
	//����
	printf("\n");

	//2. ������
	for (i = 1; i <= col; i++)
	{
		//�����һ���ⶼҪ����---
		if (i == 1)
		{
			printf(" ");
		}
		printf(" ---");
	}
	//����
	printf("\n");

	//3. �����кͷָ���
	for (i = 1; i <= row; i++)
	{
		//1.��ӡһ������
		for (j = 0; j <= col; j++)
		{
			//�������ʾ����
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
		//����
		printf("\n");

		//2.��ӡ�ָ��У�
		for (k = 1; k <= col; k++)
		{
			if (k == 1)
			{
				printf(" ");
			}
			//---
			printf(" ---"); 
		}
		//��ӡ��ָ���ҲҪ����
		printf("\n");
	}
}

//����
void PlaceMines(char board[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int i = 0;
	//�������ַ�1��ʾ
	for (i = 0; i < MINE_NUM; i++)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		//�����ظ�
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
		}
	}
}

//������Χ���׵ĸ���
int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	//'1'-'0'=1;
	//'3'-'0'=3;
	//����Χ���ַ�����ȥ'0'���Ϳ���ʵ���ַ���ת���������~
	//ֻ��0��1������Χ��8�����������Ǽ���˵���м���1�����ף�
	return mine[x - 1][y - 1] +
		   mine[x - 1][y] +
		   mine[x - 1][y + 1] +
		   mine[x][y - 1] +
		   mine[x][y + 1] +
		   mine[x + 1][y - 1] +
		   mine[x + 1][y] +
		   mine[x + 1][y + 1] - 8 * '0';
}

//����չ������
//1. �Լ�������
//2. ��������Χû����
//3. ��Χÿ�����궼����������������
//�ݹ�
void IntellUnfold(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	//������ף�����ʾʧ��
	if (mine[x][y] == '1')
	{
		printf("***���ź�!�㱻ը����~***\n");
		DisplayBoard(mine, ROW, COL);
	}
	//1. ��������ף�Ҫ��ʾ��Χ���׵ĸ���
	else
	{
		//��Χ���׵ĸ���
		int mine_count = GetMineCount(mine, x, y);
		//2. �����Χû����
		if (mine_count == 0)
		{
			show[x][y] = ' ';
			//������Χ�ĸ���
			int arrx[] = { x - 1,x,x + 1 };
			int arry[] = { y - 1,y,y + 1 };
			int i = 0;
			int j = 0;
			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < 3; j++)
				{
					//�����Լ��������������
					if (i != 1 || j != 1)
					{
						IntellUnfold(mine, show, arrx[i], arry[j]);
					}
				}
			}
		}
		else
		{
			//show��ʾ��Χ�׵ĸ�������'0'��Ϊ�˽�����ת���ַ���
			show[x][y] = mine_count + '0';
		}
	}
}

//ɨ��
void SweapMines(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	//�ǵ��׸�������
	int not_mine_num_max = row * col - MINE_NUM;
	//ɨ�����ķǵ��׸������
	int not_mine_count = 0;
	//���ǵ��׸�����û�дﵽ���ʱ��������Ϸ
	while (not_mine_count < not_mine_num_max)
	{
		//����
		int x = 0;
		int y = 0;
		printf("***���������꣺--> ");
		scanf_s("%d%d", &x, &y);
		//�ж�����Ϸ���
		//���Ϸ�����������
		if (x < 1 || x > row || y < 1 || y > col)
		{
			printf("***������1~%d֮�������ֵ��***", row);
		}
		//�Ϸ�
		else
		{
			//�Ϸ�������չ��
			IntellUnfold(mine, show, x, y);
			DisplayBoard(show, ROW, COL);
		}
		//���׸����+1
		not_mine_count++;
	}
	if (not_mine_count == not_mine_num_max)
	{
		//�ﵽ���û�вȵ��ף�����ʾ��Ϸ�ɹ���Ȼ��ѡ������滹���˳�
		printf("***��ϲͨ��^-^***\n");
	}
}