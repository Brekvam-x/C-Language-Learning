//#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void menu()
{
	printf("*************************\n");
	printf("******** 1. PLAY ********\n");
	printf("******** 0. EXIT ********\n");
	printf("*************************\n");
}

//游戏实现函数
void game()
{
	//地雷信息的存储
	//1. 布置好的雷的信息
	char mine[ROWS][COLS] = { 0 };
	//2. 排查雷的信息
	char show[ROWS][COLS] = { 0 };
	//两个数组：一个用于存放雷的信息，一个用于存放排查出来的类的信息
	//只把后者显示在屏幕上

	//初始化,一个填充字符0；一个填充*
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//显示
	/*DisplayBoard(mine, ROW, COL);*/
	//只显示用于排雷的图
	DisplayBoard(show, ROW, COL);

	//布置雷
	PlaceMines(mine, ROW, COL);
	////看下布雷成果--成功！！
	//DisplayBoard(mine, ROW, COL);

	////排雷, 要将show里面的信息传递给mine
	SweapMines(mine, show, ROW, COL);
}

//运行函数：菜单+游戏
void test()
{
	int input = 0; //选择玩还是退出
	//随机数种子，srand函数只能调用一次
	srand((unsigned int)time(NULL));
	do
	{
		menu();//打印菜单
		printf("***请选择：> ");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("****退出游戏****\n");
			break;	
		default:
			printf("***选择错误，请重新输入！***\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}