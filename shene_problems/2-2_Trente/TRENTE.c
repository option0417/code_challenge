/*
 * TRENTE.c
 *
 *  Created on: Mar 30, 2013
 *      Author: option0417
 */

#include "TRENTE.h"

void solveTRENTE() {
	/*
	 *   VINGT
	 *    CINQ
	 * +  CINQ
	 * -------
	 *  TRENTE
	 */
	int C = 2;
	int E = 3;
	int G = 2;
	int I = 2;
	int N = 2;
	int R = 0; // R = 0
	int T = 1; // T = 1
	int Q = 2;
	int V = 8; // V = 8 ~ 9
	int addNum1 = 0, addNum2 = 0, sumNum = 0;

	printf("  VINGT\n");
	printf("   CINQ\n");
	printf("+  CINQ\n");
	printf("-------\n");
	printf(" TRENTE\n");
	printf("\n");
	for (V = 8; V <= 9; V++) {
		for (C = 2; C <= 9; C++) {
			if (C != V) {
				for (E = 3; E <= 9; E+=2) {
					if (E != C && E != V) {
						for (G = 2; G <= 9; G++) {
							if (G != E && G != C && G != V) {
								for (I = 2;I <= 9; I++) {
									if (I != G && I != E && I != C && I != V) {
										for (N = 2; N <= 9; N++) {
											if (N != I && N != G && N != E && N != C && N != V) {
												for (Q = 2; Q <= 9; Q++) {
													if (Q != N && Q != I && Q != G && Q != E && Q != C && Q != V) {
														addNum1 = V*10000 + I*1000 + N*100 + G*10 + T;
														addNum2 = C*1000 + I*100 + N*10 + Q;
														sumNum  = T*100000 + E*1000 + N*100 + T*10 + E;
														if (addNum1 + addNum2 + addNum2 == sumNum) {
															printf("  %d%d%d%d%d\n", V, I, N, G, T);
															printf("   %d%d%d%d\n", C, I, N, Q);
															printf("+  %d%d%d%d\n", C, I, N, Q);
															printf("-------\n");
															printf(" %d%d%d%d%d%d\n", T, R, E, N, T, E);
															return;
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}


}
