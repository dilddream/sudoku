#ifndef _SDKBOARD_H
#define _SDKBOARD_H

#include <stdio.h>
#include "sdkset.h"


typedef struct {
	int board[9][9];
} sdkboard;


// Sudoku Board APIs
sdkboard sdkboard_create();
void write_sdkboard_cell(int idx1, int idx2, int num, sdkboard *board);




// Sudoku Board Functions
sdkboard sdkboard_create()
{
	sdkboard board = {0,};
	return board;
}

void write_sudoku_cell(int idx1, int idx2, int num, sdkboard *board)
{
	board[idx1][idx2] = num;
}




#endif	// _SDKBOARD_H
