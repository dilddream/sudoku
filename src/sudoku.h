#ifndef _SUDOKU_H
#define _SUDOKU_H

#include <stdio.h>
#include "sdkset.h"
#include "sdkboard.h"

typedef struct {
	sdkboard board;
	
	sdkset row[9];
	sdkset col[9];
	sdkset box[9];
} sdk;

int num_of_zero = 81;


// sudoku APIs
void sdk_create();
void sdk_init(int idx1, int idx2, int num, sdk *sudoku);
void sdk_check(int idx1, int idx2, sdk *sudoku);


sdk sdk_create()
{
	sdk sudoku;

	sudoku->board = sdkboard_create();

	for (int i=0; i<9; i++) {
		sudoku->row[i] = sdkset_create();
		sudoku->col[i] = sdkset_create();
		sudoku->box[i] = sdkset_create();
	}

	return sudoku;
}



void sdk_init(int idx1, int idx2, int num, sdk *sudoku)
{
	sudoku->board[idx1][idx2] = num;
	
	if (1 <= num && num <= 9) {
		sdkset_update(idx1, idx2, num, sudoku);
		num_of_zero--;
	}
}


void sdk_check(int idx1, int idx2, sdk *sudoku)
{
	if (num != 0)
		return;

	sdkset set = sudoku->row[idx1] & sudoku->col[idx2] & sudoku->box[3*(idx1/3)+(idx2/3)];
	
	int num = sdkset_return(idx1, idx2, set);

	if (num != -1) {
		sdk_init(idx1, idx2, num, sudoku);
}


#endif	// _SUDOKU_H
