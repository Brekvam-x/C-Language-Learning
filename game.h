#pragma once
#define ROW 3
#define COL 3
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);

//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);

//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col);

//判断输赢
//能告诉我们四种游戏状态：C-继续，*-玩家赢，#-玩家输，D-平局
char IsWin(char board[ROW][COL], int row, int col);