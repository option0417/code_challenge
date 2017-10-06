/*
 * Source: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
 * Author: W.D Su
 * Date:   10/06/2017
*/
#include "stdio.h"
#include "stdlib.h"

int removeDuplicates(int* nums, int numsSize) {
    if (!numsSize) return numsSize;
    
    int idx     = 0;
    int idx2    = idx+1;
    for (; idx2 < numsSize; idx2++) {
        if (nums[idx] != nums[idx2]) {
            nums[idx+1] = nums[idx2];
            idx++;
        }
    }
    return idx+1;
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
    int nums1[0] = {};
    showArray(nums1, 0);
    printf(" -> ");
    showArray(nums1,  removeDuplicates(nums1, 0));    // []
    printf("\n");

    int nums2[1] = {1};
    showArray(nums2, 1);
    printf(" -> ");
    showArray(nums2,  removeDuplicates(nums2, 1));    // [1]
    printf("\n");

    int nums3[2] = {1, 1};
    showArray(nums3, 2);
    printf(" -> ");
    showArray(nums3,  removeDuplicates(nums3, 2));    // [1]
    printf("\n");

    int nums4[2] = {1, 2};
    showArray(nums4, 2);
    printf(" -> ");
    showArray(nums4,  removeDuplicates(nums4, 2));    // [1, 2]
    printf("\n");

    int nums5[3] = {1, 1, 1};
    showArray(nums5, 3);
    printf(" -> ");
    showArray(nums5,  removeDuplicates(nums5, 3));    // [1]
    printf("\n");

    int nums6[3] = {1, 1, 2};
    showArray(nums6, 3);
    printf(" -> ");
    showArray(nums6,  removeDuplicates(nums6, 3));    // [1, 2]
    printf("\n");

    int nums7[3] = {1, 2, 3};
    showArray(nums7, 3);
    printf(" -> ");
    showArray(nums7,  removeDuplicates(nums7, 3));    // [1, 2, 3]
    printf("\n");

    int nums8[4] = {1, 1, 1, 1};
    showArray(nums8, 4);
    printf(" -> ");
    showArray(nums8,  removeDuplicates(nums8, 4));    // [1]
    printf("\n");

    int nums9[4] = {1, 1, 1, 2};
    showArray(nums9, 4);
    printf(" -> ");
    showArray(nums9,  removeDuplicates(nums9, 4));    // [1, 2]
    printf("\n");

    int nums10[4] = {1, 1, 2, 3};
    showArray(nums10, 4);
    printf(" -> ");
    showArray(nums10,  removeDuplicates(nums10, 4));  // [1, 2, 3]
    printf("\n");

    int nums11[4] = {1, 2, 3, 4};
    showArray(nums11, 4);
    printf(" -> ");
    showArray(nums11,  removeDuplicates(nums11, 4));  // [1, 2, 3, 4]
    printf("\n");

    int nums12[5] = {1, 1, 1, 1, 1};
    showArray(nums12, 5);
    printf(" -> ");
    showArray(nums12,  removeDuplicates(nums12, 5));  // [1]
    printf("\n");
    return 0;
}
