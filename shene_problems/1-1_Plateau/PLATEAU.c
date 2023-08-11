/*
 * PLATEAU.c
 *
 *  Created on: Mar 26, 2013
 *      Author: option0417
 */
#include "PLATEAU.h"

void showMaxLengthPlateau(int sortedArray[], int size) {
	int maxLength = 1;

	printf("Plateau : ");
	for (int idx = 0; idx < size; idx++) {
		printf(" %d ", sortedArray[idx]);
	}
	printf("\n");

	for (int idx = 1; idx < size; idx++) {
		if (sortedArray[idx] == sortedArray[idx-maxLength]) {
			maxLength++;
		}
	}
	printf("Max Length of Plateau : %d\n", maxLength);
}

