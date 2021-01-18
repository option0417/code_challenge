#include "stdio.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int outerIdx = 0;
    int innerIdx = 0;
    
    for (outerIdx = 0; outerIdx < numsSize; outerIdx++) {
        for (innerIdx = outerIdx + 1; innerIdx < numsSize; innerIdx++) {
            if (nums[innerIdx] == target - nums[outerIdx]) {
                int* indices = (int *)malloc(sizeof(int) * 2);                
                indices[0] = outerIdx;
                indices[1] = innerIdx;
                return indices;
            }
        }
    }
    return NULL;
}

void main(void) {
  
  return;
}
