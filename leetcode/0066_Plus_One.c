#include "stdio.h"
#include "stdlib.h"

/*
 * Source: https://leetcode.com/problems/plus-one/description/
 * Author: W.D Su
 * Date:   07/09/2018
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int* newDigits = 0;
    int idx = digitsSize - 1;
    int carry = 0;
    
    for (; idx >= 0; idx--) {
        if (digits[idx] == 9) {
            digits[idx] = 0;
            carry = 1;
        } else {
            digits[idx]++;
            carry = 0;
            break;
        }
    }
    
    *returnSize = digitsSize + carry;
    newDigits = (int*) malloc((*returnSize) * sizeof(int));
    
    if (carry) {
        memcpy(newDigits + 1, digits, sizeof(int) * (digitsSize));
        *(newDigits) = 1;
    } else {
        memcpy(newDigits, digits, sizeof(int) * (digitsSize));
    }
    
    return newDigits;
}

void showArray(int* ary, int* length) {
    for (;*length > 0; (*length)--) {
        printf("%d ", *ary);
        ary++;
    }
    printf("\n");
}

int main(int argv, char* argc[]) {
    int case1[]           = {1, 2, 3};
    int case2[]           = {1, 2, 9};
    int case3[]           = {9, 9, 9};
    int case1ReturnSize   = 0;
    
    int* case1Result = plusOne(case1, 3, &case1ReturnSize);
    showArray(case1Result, &case1ReturnSize);
    
    int* case2Result = plusOne(case2, 3, &case1ReturnSize);
    showArray(case2Result, &case1ReturnSize);
    
    int* case3Result = plusOne(case3, 3, &case1ReturnSize);
    showArray(case3Result, &case1ReturnSize);    
}
