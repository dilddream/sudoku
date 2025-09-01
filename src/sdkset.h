#ifndef _SUDOKU_SET_H
#define _SUDOKU_SET_H


#include <stdbool.h>


typedef struct {
	uint16_t mask;
} sdkset;


// sdkset APIs
sdkset sdkset_create();
void sdkset_remove(sdkset *set, int num);
int sdkset_size(sdkset *set);
void sdkset_update(int idx1, int idx2, int num);


sdkset sdkset_create()
{
	sdkset set = 0x0000001111111110;
	return set;
}


void sdkset_remove(sdkset *set, int num)
{
	if (1 <= num && num <= 9)
		set->mask &= ~(1 << num);
}


int sdkset_size(sdkset *set)
{
	int cnt;
	uint16_t tmp_mask = set->mask;
	
	while (tmp_mask) {
		tmp_mask &= tmp_mask - 1;
		cnt++;
	}

	return cnt;
}


void 


#endif	// _SUDOKU_SET_H
