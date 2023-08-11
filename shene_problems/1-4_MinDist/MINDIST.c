/*
 * MINDIST.c
 *
 *  Created on: Mar 27, 2013
 *      Author: option0417
 */

#include <limits.h>
#include "MINDIST.h"

int getMinDist(int f[], int fSize, int g[], int gSize) {
	int minDist = INT_MAX;
	int fIdx  = 0;
	int gIdx  = 0;

	while (fIdx < fSize && gIdx < gSize) {
		if (f[fIdx] == g[gIdx]) {
			return 0;
		} else if (f[fIdx] < g[gIdx]) {
			if (g[gIdx] - f[fIdx] < minDist)
				minDist = g[gIdx] - f[fIdx];
			fIdx++;
		} else {
			if (f[fIdx] - g[gIdx] < minDist)
				minDist = f[fIdx] - g[gIdx];
			gIdx++;
		}
	}
	return minDist;
}

