#ifndef _SDKSET_H
#define _SDKSET_H

#include <stdbool.h>


typedef struct {
	uint16_t mask;
} sdkset;


// sdkset APIs
sdkset sdkset_create();
void sdkset_remove(sdkset *set, int num);
int sdkset_size(sdkset *set);
void sdkset_update(int idx1, int idx2, int num);





// sdkset FUNCTIONs
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


void sdkset_update(int idx1, int idx2, int num)
{
	sdkset_remove(row[idx1], num);
	sdkset_remove(col[idx2], num);
	sdkset_remove(box[idx1/3][idx2/3], num);
}

#endif	// _SDKSET_H

