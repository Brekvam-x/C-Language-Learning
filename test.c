//测试三子棋游戏
#include "game.h"

void menu()
{
	printf("******************************************\n");
	printf("************1. PLAY  0. EXIT**************\n");
	printf("******************************************\n");
}

void game()
{
	//接收游戏结果
	char res = 0;
	//创建数组（棋盘）
	char board[ROW][COL] = { 0 }; //数组元素初始值均为空格，表示棋盘上无子
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	//   |   |   
    //---|---|---
	//   |   |   
	//---|---|---
	//   |   |   
	DisplayBoard(board, ROW, COL);
	//下棋
	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断玩家是否赢
		res = IsWin(board, ROW, COL);
		//如果res为*、#、D，游戏结束
		if (res != 'C')
		{
			break;
		}
		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断电脑是否赢
		res = IsWin(board, ROW, COL);
		//如果res为*、#、D，游戏结束
		if (res != 'C')
		{
			break;
		}
	}
	//游戏结束，根据返回值判定胜负
	if (res == '*')
	{
		printf("恭喜你！获得胜利！");
	}
	else if (res == '#')
	{
		printf("很遗憾~你输了~");
	}
	else if (res == 'D')
	{
		printf("平局~再来一局吧~");
	}	
}

void test()
{
	int input = 0;
	//srand()函数用于产生随机数
	//基本格式：srand(unsigned seed),其中，seed为随机数种子，当未声明时，seed默认为1，产生的随机数不会自动变化
	//将seed设置为time(NULL),即让随机数可以自动变化，是获取自1970年1月1日00：00到现在的时间秒数（时间戳）
	srand((unsigned int)time(NULL));
	do
	{
		menu(); //显示菜单
		printf("请选择：> "); //输入选择1或0
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("****三子棋****\n");
			printf("****开始游戏****\n");
			game();
			break; 
		case 0:
			printf("****退出游戏****\n");
			break;
		default:
			printf("**选择错误！请重新选择!**\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}