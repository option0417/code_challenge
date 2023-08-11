/*
 * HEADTAIL.c
 *
 *  Created on: Mar 29, 2013
 *      Author: option0417
 */

#include "HEADTAIL.h"

int getHeadTail(int f[], int size) {
	int frontIdx = 0,   rearIdx = size-1;
	int subValue = 0;
	int count = 0;

	while (frontIdx < size && rearIdx >= 0) {
		subValue   += (f[frontIdx++] - f[rearIdx--]);
		(subValue == 0) ? count++ : count;
	}
	return count;
}
