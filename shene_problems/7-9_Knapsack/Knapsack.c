/*
 * Knapsack.c
 *
 *  Created on: Nov 12, 2012
 *      Author: option0417
 */

#include "Knapsack.h"

void doKnapsack() {
	int** dpTable = createDPTable(ObjectAmount, MAX_WEIGHT);

	printf("D.P-Table created\n");
	int i = 0;
	int j = 0;

	for (i = 0; i < ObjectAmount; i++) {
		for (j = 0; j < MAX_WEIGHT; j++) {
			dpTable[i][j] = i + j;
		}
	}

	for (i = 0; i < ObjectAmount; i++) {
		for (j = 0; j < MAX_WEIGHT; j++) {
			printf("D.P-Table[%d][%d] = %d \n", i, j, dpTable[i][j]);
		}
	}

}

Object* createObject(char* name, int weight, int price) {
	Object* obj = (Object*)malloc(sizeof(Object));
	obj->name = name;
	obj->weight = weight;
	obj->price = price;
	return obj;
}

Package* createPackage(int maxWeight) {
	Package* package = (Package*)malloc(sizeof(Package));
	package->objectList = (Object*)malloc(sizeof(Object) * 5);
	package->maxWeight = maxWeight;
	return package;
}

void putObject(Object* object, Package* package) {
	int count = 0;
	while ((package->objectList + count) != 0);
	package->objectList += count;
	package->objectList = object;
}

int** createDPTable(int objectAmount, int maxWeight) {
	int** dpTable = (int**)malloc(sizeof((int*)malloc(sizeof(int) * maxWeight)) * objectAmount);

	int index = 0;
	for (index = 0; index < objectAmount; index++) {
		dpTable[index] = (int*)malloc(sizeof(int) * maxWeight);
	}

	return dpTable;
}

