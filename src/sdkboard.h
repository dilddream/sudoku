#ifndef _SDKINIT_H
#define _SDKINIT_H

#include <stdio.h>
#include "sdkset.h"


// Sudoku Data-structures
typedef struct {
	int board[9][9];
} sdkboard;


// Sudoku Board APIs
void sudoku_board_create();
void write_sudoku_cell(int idx1, int idx2, int num, sdkboard *board);



sdkboard sudoku_board_create()
{
	sdkboard board = {0,};
	return board;
}

void write_sudoku_cell(int idx1, int idx2, int num, sdkboard *board)
{
	board[idx1][idx2] = num;
}




#endif	// _SDKINIT_H
