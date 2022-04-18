#pragma once
#define ROW 3
#define COL 3
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col);

//��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col);

//�������
void PlayerMove(char board[ROW][COL], int row, int col);

//��������
void ComputerMove(char board[ROW][COL], int row, int col);

//�ж���Ӯ
//�ܸ�������������Ϸ״̬��C-������*-���Ӯ��#-����䣬D-ƽ��
char IsWin(char board[ROW][COL], int row, int col);