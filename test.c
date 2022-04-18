//������������Ϸ
#include "game.h"

void menu()
{
	printf("******************************************\n");
	printf("************1. PLAY  0. EXIT**************\n");
	printf("******************************************\n");
}

void game()
{
	//������Ϸ���
	char res = 0;
	//�������飨���̣�
	char board[ROW][COL] = { 0 }; //����Ԫ�س�ʼֵ��Ϊ�ո񣬱�ʾ����������
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	//   |   |   
    //---|---|---
	//   |   |   
	//---|---|---
	//   |   |   
	DisplayBoard(board, ROW, COL);
	//����
	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж�����Ƿ�Ӯ
		res = IsWin(board, ROW, COL);
		//���resΪ*��#��D����Ϸ����
		if (res != 'C')
		{
			break;
		}
		//��������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�жϵ����Ƿ�Ӯ
		res = IsWin(board, ROW, COL);
		//���resΪ*��#��D����Ϸ����
		if (res != 'C')
		{
			break;
		}
	}
	//��Ϸ���������ݷ���ֵ�ж�ʤ��
	if (res == '*')
	{
		printf("��ϲ�㣡���ʤ����");
	}
	else if (res == '#')
	{
		printf("���ź�~������~");
	}
	else if (res == 'D')
	{
		printf("ƽ��~����һ�ְ�~");
	}	
}

void test()
{
	int input = 0;
	//srand()�������ڲ��������
	//������ʽ��srand(unsigned seed),���У�seedΪ��������ӣ���δ����ʱ��seedĬ��Ϊ1������������������Զ��仯
	//��seed����Ϊtime(NULL),��������������Զ��仯���ǻ�ȡ��1970��1��1��00��00�����ڵ�ʱ��������ʱ�����
	srand((unsigned int)time(NULL));
	do
	{
		menu(); //��ʾ�˵�
		printf("��ѡ��> "); //����ѡ��1��0
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("****������****\n");
			printf("****��ʼ��Ϸ****\n");
			game();
			break; 
		case 0:
			printf("****�˳���Ϸ****\n");
			break;
		default:
			printf("**ѡ�����������ѡ��!**\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}