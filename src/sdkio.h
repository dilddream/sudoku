#ifndef _SDKIO_H_
#define _SDKIO_H_

#include <stdio.h>
#include "sdkboard.h"


FILE *load_sudoku_from_file(const char *filename);


FILE *load_sudoku_from_file(const char *filename)
{
	FILE *file = fopen(filename, "rw");

	if (!file) {
		printf("Error: failed to open file.\n");
		exit(0);
	}

	return file;
}


#endif	// _SDKIO_H
