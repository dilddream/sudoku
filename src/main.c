#include <stdio.h>
#include "sdkio.h"
#include "sudoku.h"
#include "arg.h"

int main(int argc, char *argv[]) {


	arg(argc, *argv[]);

	sdk sudoku = sdk_create();

	FILE *file = load_sudoku_from_file(argv[1]);

	for (int i=0; i<9; i++) {
		for (int j=0; j<9; j++) {
			char ch = fgetc(file) - '0';
			sdk_init(i, j, ch, sudoku);
		}
	}


	while (1) {
		for (int i=0; i<9; i++) {
			for (int j=0; j<9; j++) {
				sdk_check(i, j, sudoku);
			}
		}

		if (num_of_zero == 0) 
			break;	
	}


	FILE *ans = fopen("ss1.txt", "w");

	for (int i=0; i<9; i++) {
		for (int j=0; j<9; j++) {
			fprintf(ans, "%d", sudoku->board[i][j]);
		}
		fprintf(ans, "\n");
	}

	fclose(file);
	fclose(ans);


	return 0;
}
