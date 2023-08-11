/*
 * FACTOR.c
 *
 *  Created on: Apr 8, 2013
 *      Author: option0417
 */

#include <stdio.h>
#include <stdlib.h>
#include "FACTOR.h"

void showFactors(int num) {
	int* primeArray = (int*)malloc(sizeof(int) * num/2);
	Factor* factorArray = (Factor*)malloc(sizeof(Factor) * num/2);
	int count = 0;
	int index = 0;

	if ((num & 0x01UL) == 0) {
		for (count = 0; (num & 0x01UL) == 0 && num > 1; num >>= 1, count++);
		Factor two = {2, count};
		factorArray[index++] = two;
	}


	for (int primeArrayIndex = 0; num >= (2*primeArrayIndex + 3); primeArrayIndex++) {
		if (primeArray[primeArrayIndex] == 0) {
			primeArray[primeArrayIndex] = (2*primeArrayIndex + 3);
			for (count = 0; num % primeArray[primeArrayIndex] == 0 && num > 1; num /= primeArray[primeArrayIndex], count++);
			if (count > 0) {
				Factor factor = {(2*primeArrayIndex + 3), count};
				factorArray[index++] = factor;
			}

			int subIndex = 2*primeArrayIndex + 3 + primeArrayIndex;
			while (subIndex < num/2) {
				primeArray[subIndex] = -1;
				subIndex += (2*primeArrayIndex + 3);
			}
		}
	}

	for (int resultIndex = 0; resultIndex < index; resultIndex++) {
		Factor tmpFactor = factorArray[resultIndex];
		printf("%2d(%d)", tmpFactor.prime, tmpFactor.count);
	}
	printf("\n");
	free(factorArray);
}
