#pragma once
#define ROW 9
#define COL 9
//Ϊ����߽ǲ�����8������������������һȦ
#define ROWS ROW+2 
#define COLS COL+2
//���׵�����
#define MINE_NUM 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//����
void InitBoard(char board[ROWS][COLS], int rows, int cols, char init);
void DisplayBoard(char board[ROWS][COLS], int row, int col);
void PlaceMines(char board[ROWS][COLS], int row, int col);
void SweapMines(char mine[ROWS][COLS], char show[ROWS][COLS], int rows, int cols);