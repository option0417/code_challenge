#include "stdio.h"
#include "stdlib.h"

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

int main(int argc, char* argv[]) {
  int nums[5] = {1, 2, 3, 4, 5};
  int* result; 
  
  result = twoSum(nums, 5, 3);
  printf("Result: %d, %d\n", result[0], result[1]);  // 0, 1
  
  result = twoSum(nums, 5, 4);
  printf("Result: %d, %d\n", result[0], result[1]);  // 0, 2
  
  result = twoSum(nums, 5, 5);
  printf("Result: %d, %d\n", result[0], result[1]);  // 0, 3
  
  result = twoSum(nums, 5, 6);
  printf("Result: %d, %d\n", result[0], result[1]);  // 0, 4
  
  result = twoSum(nums, 5, 7);
  printf("Result: %d, %d\n", result[0], result[1]);  // 1, 4
  
  result = twoSum(nums, 5, 8);
  printf("Result: %d, %d\n", result[0], result[1]);  // 2, 4
  
  result = twoSum(nums, 5, 9);
  printf("Result: %d, %d\n", result[0], result[1]);  // 3, 4

  result = twoSum(nums, 5, 10);
  printf("Result is Null: %s\n", result == NULL ? "true" : "false");    // NULL
  return 0;
}
