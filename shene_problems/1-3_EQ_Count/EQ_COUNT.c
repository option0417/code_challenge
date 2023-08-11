/*
 * EQ_COUNT.c
 *
 *  Created on: Mar 27, 2013
 *      Author: option0417
 */

#include "EQ_COUNT.h"

int getEQCount(int f[], int fSize, int g[], int gSize) {
	int count = 0;
	int fIdx  = 0;
	int gIdx  = 0;

	while (fIdx < fSize && gIdx < gSize) {
		if (f[fIdx] == g[gIdx]) {
			count++;
			fIdx++;
			gIdx++;
		} else if (f[fIdx] < g[gIdx]) {
			fIdx++;
		} else {
			gIdx++;
		}
	}

	return count;
}
