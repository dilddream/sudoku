#include <stdio.h>

void arg(int argc, char *argv[]);


void arg(int argc, char *argv[])
{
	if (argc != 2) {
		printf("Usage: ./sudoku [file]\n");
		exit(0);
	}

	FILE *file = fopen(argv[1], "r");

	if (!file) {
		printf("File does not exists\n");
		exit(0);
	}
}
