#include <stdio.h>


int main(int argc, char *argv[]) {

	// error check
	if (argc != 2) {
		printf("Usage: ./sudoku [problem]\n");
		return 0;
	}
	
	FILE *file = fopen(argv[1], "r");

	if (!file) {
		printf("File does not exists\n");
		return 0;
	}


	

	int sudoku[9][9] = {0,};
	
	while (1) {
		int idx1, idx2, val;
		int err = fscanf(file, "%d %d %d", &idx1, &idx2, &val);
			
		if (err != 3) {
			printf("There is wrong data\n");
			return 0;
		}

		if (err == EOF)
			break;

		sudoku[idx1][idx2] = val;
	}



	return 0;
}
