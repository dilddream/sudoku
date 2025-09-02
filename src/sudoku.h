#ifndef _SUDOKU_H
#define _SUDOKU_H

typedef struct {
	sdkboard board;
	
	sdkset row[9];
	sdkset col[9];
	sdkset box[9];
} sdk;




// sudoku APIs
void sdk_create();
void sdkset_update(int idx1, int idx2, int num, sdk *sudoku);
void write_sdk_cell(int idx1, int idx2, int num, sdk *sudoku);


sdk sdk_create()
{
	sdk sudoku;

	sudoku->board = sdkboard_create();

	for (int i=0; i<9; i++) {
		sudoku->row[i] = sdkset_create();
		sudoku->col[i] = sdkset_create();
		sudoku->box[i] = sdkset_create();
	}
}


void sdkset_update(int idx1, int idx2, int num, sdk *sudoku)
{
	sdkset_remove(sudoku->row[idx1], num);
	sdkset_remove(sudoku->col[idx2], num);
	sdkset_remove(sudoku->box[3*(idx1/3)+(idx2/3)], num);
}


void write_sdk_cell(int idx1, int idx2, int num, sdk *sudoku)
{
	sudoku->board[idx1][idx2] = num;
	sdkset_update(idx1, idx2, num, sudoku);
}
	



#endif	// _SUDOKU_H
