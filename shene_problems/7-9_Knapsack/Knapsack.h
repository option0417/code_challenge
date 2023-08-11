/*
 * Knapsack.h
 *
 *  Created on: Nov 12, 2012
 *      Author: option0417
 */

#ifndef KNAPSACK_H_
#define KNAPSACK_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char* name;
	int weight;
	int price;
}Object;

typedef struct {
	Object* objectList;
	int maxWeight;
}Package;

#define ObjectAmount 5
#define MAX_WEIGHT 10

Object* createObject(char* name, int weight, int price);
Package* createPackage(int maxWeight);
void putObject(Object* object, Package* package);
int** createDPTable(int objectAmount, int maxWeight);
void doKnapsack();

#endif /* KNAPSACK_H_ */
