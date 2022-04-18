#include "game.h"

//��ʼ������
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

//��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < row; i++)
	{
		//1.��ӡһ������
		for (j = 0; j < col; j++)
		{
			//�����һ���ⶼҪ���Ϸ��з�|
			printf(" %c ", board[i][j]);
			if(j < col - 1)
				printf("|");
		}
		//��ӡ��һ�оͻ���
		printf("\n");

		//2.��ӡ�ָ��У�
		if (i < row - 1)
		{
			//�ָ���---�������������䶯
			for (k = 0; k < col; k++)
			{
				//�����һ���ⶼҪ���Ϸ��з� |
				printf("---");
				if (k < col - 1)
					printf("|");
			}
		}
		//��ӡ��ָ���ҲҪ����
		printf("\n");
	}
}

//�������
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("******��һغ�******\n");
	while (1)
	{
		printf("������ --> ");
		scanf_s("%d%d", &x, &y);
		//��ֹ��������곬�����̷�Χ,���ж�����Ϸ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//�մ���������
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("Ϲѽ�������Ķ����أ�������ӣ�\n");
			}
		}
		//�Ƿ����룬������ʾ
		else
		{
			printf("���Ķ����أ���������߶�ȥ��~����λ��ᣬ������һ�Σ�\n");
		}
	}
}

//��������
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("******���Իغ�******\n");
	//rand������������0~rand_max-1֮��������������ʽһ��Ϊ��
	//x = rand() % rand_max + rand_min -- ����rand_min~rand_max-1֮����������
	//����ͱ�ʾ����0~row-1֮�������
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		//�մ���������
		if (board[x - 1][y - 1] == ' ')
		{
			board[x - 1][y - 1] = '#';
			break;
		}
	}
}

//�ж������Ƿ�����
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
				return 0;//û��
			}
		}
	}
	return 1;//����
}

//�ж���Ӯ C-������*-���Ӯ��#-����䣬D-ƽ��
char IsWin(char board[ROW][COL], int row, int col)
{
	//�ж���
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		//ÿ��ѭ����Ҫ����������0
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

	//�ж���
	for (j = 0; j < col; i++)
	{
		//ÿ��ѭ����Ҫ����������0
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

	//�ж϶Խ���
	int count1 = 0;
	int	count2 = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			//���Խ���
			if (i == j && board[i][j] == board[i + 1][j + 1] && board[i][j] != ' ')
			{
				count1++;
			}
			//���Խ���
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

	//�ж�ƽ��
	if (IsFull(board, row, col) == 1)
	{
		return 'D';
	}
	return 'C';
}