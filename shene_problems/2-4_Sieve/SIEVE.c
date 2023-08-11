/*
 * SIEVE.c
 *
 *  Created on: Apr 2, 2013
 *      Author: option0417
 */

#include <stdio.h>
#include <stdlib.h>
#include "SIEVE.h"

int showPrimeWithSieve(int num) {
	if (num <= 2) {
		if (num == 2) {
			return 1;
		} else {
			return 0;
		}
	}

	int count = 1;
	int* numArray = (int*)malloc(sizeof(int) * num/2);

	for (int index = 0; index < num/2; index++) {
		if (numArray[index] == 0) {
			if (2*index + 3 < num) {
				numArray[index] = 2*index + 3;
				count++;
			}

			int subIndex = 2*index + 3 + index;
			while (subIndex < num/2) {
				numArray[subIndex] = -1;
				subIndex+= (2*index+3);
			}
		}
	}

	printf("%6d", 2);
	for (int index = 0; index < num/2; index++) {
		if (numArray[index] > 0) {
			printf("%6d", numArray[index]);
		}
	}
	printf("\n");

	free(numArray);
	return count;
}
