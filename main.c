//#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void menu()
{
	printf("*************************\n");
	printf("******** 1. PLAY ********\n");
	printf("******** 0. EXIT ********\n");
	printf("*************************\n");
}

//��Ϸʵ�ֺ���
void game()
{
	//������Ϣ�Ĵ洢
	//1. ���úõ��׵���Ϣ
	char mine[ROWS][COLS] = { 0 };
	//2. �Ų��׵���Ϣ
	char show[ROWS][COLS] = { 0 };
	//�������飺һ�����ڴ���׵���Ϣ��һ�����ڴ���Ų�����������Ϣ
	//ֻ�Ѻ�����ʾ����Ļ��

	//��ʼ��,һ������ַ�0��һ�����*
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//��ʾ
	/*DisplayBoard(mine, ROW, COL);*/
	//ֻ��ʾ�������׵�ͼ
	DisplayBoard(show, ROW, COL);

	//������
	PlaceMines(mine, ROW, COL);
	////���²��׳ɹ�--�ɹ�����
	//DisplayBoard(mine, ROW, COL);

	////����, Ҫ��show�������Ϣ���ݸ�mine
	SweapMines(mine, show, ROW, COL);
}

//���к������˵�+��Ϸ
void test()
{
	int input = 0; //ѡ���滹���˳�
	//��������ӣ�srand����ֻ�ܵ���һ��
	srand((unsigned int)time(NULL));
	do
	{
		menu();//��ӡ�˵�
		printf("***��ѡ��> ");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("****�˳���Ϸ****\n");
			break;	
		default:
			printf("***ѡ��������������룡***\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}