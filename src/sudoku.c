#include <stdio.h>
#include "sdkset.h"


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


	

	


	return 0;
}
