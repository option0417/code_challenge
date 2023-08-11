/*
 * GT_COUNT.c
 *
 *  Created on: Mar 27, 2013
 *      Author: option0417
 */

#include <stdio.h>
#include "GT_COUNT.h"

int getGTCount(int f[], int fSize, int g[], int gSize) {
	int count = 0;
	int fIdx = 0;
	int gIdx = 0;

	while (fIdx < fSize && gIdx < gSize) {
		if (f[fIdx] > g[gIdx]) {
			gIdx++;
			count += fSize - fIdx;
		} else {
			fIdx++;
		}
	}
	return count;
}
