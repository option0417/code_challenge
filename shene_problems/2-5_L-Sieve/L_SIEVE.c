/*
 * L_SIEVE.c
 *
 *  Created on: Apr 5, 2013
 *      Author: option0417
 */

#include <stdlib.h>
#include "L_SIEVE.h"

int showPrimeWithISieve(int num) {
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

				for (int subIndex = 1, tmp = 1; numArray[index] * subIndex < num;
						subIndex = 2*tmp + 3, tmp++) {
					if (subIndex == 1 || subIndex > numArray[index]) {
						int tmpIndex = numArray[index];
						tmpIndex *= subIndex;
						while (tmpIndex < num) {
							if (tmpIndex != numArray[index]) {
								numArray[(tmpIndex-3)/2] = -1;
							}
							tmpIndex *= (2*index+3);
						}
					}
				}
			} else {
				numArray[index] = -1;
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
