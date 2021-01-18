/*
 * Source: https://leetcode.com/problems/search-insert-position/description/
 * Author: W.D Su
 * Date:   10/08/2017
*/

#include "stdio.h"
#include "stdlib.h"

int searchInsert(int* nums, int numsSize, int target) {
    int idx = 0;
    for (; idx < numsSize; idx++) {
        if (nums[idx] >= target) {
            return idx;
        }
    }
    return idx;
}

void showArray(int* nums, int numsSize) {
    printf("[");
    int cnt = 0;
    for (; cnt < numsSize; cnt++) {
      printf("%d", nums[cnt]);
      if (cnt+1 != numsSize) printf(", ");
    }
    printf("]");
}

int main(int argv, char* argc[]) {
  int nums1[1] = {1};
  int nums2[4] = {1, 3, 5, 6};
  showArray(nums1, 1);
  printf(" %d -> %d\n", 0, searchInsert(nums1, 1, 0));  // 0

  showArray(nums2, 4);
  printf(" %d -> %d\n", 5, searchInsert(nums2, 4, 5));  // 2

  showArray(nums2, 4);
  printf(" %d -> %d\n", 2, searchInsert(nums2, 4, 2));  // 1

  showArray(nums2, 4);
  printf(" %d -> %d\n", 7, searchInsert(nums2, 4, 7));  // 4

  showArray(nums2, 4);
  printf(" %d -> %d\n", 0, searchInsert(nums2, 4, 0));  // 0
  return 0;
}
