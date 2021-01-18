/*
 * Source: https://leetcode.com/problems/remove-element/description/
 * Author: W.D Su
 * Date:   10/06/2017
*/
#include "stdio.h"
#include "stdlib.h"

int removeElement(int* nums, int numsSize, int val) {
    if (!numsSize) return 0;
    
    int idx = 0;
    int idx2 = 0;
    for (; idx2 < numsSize; idx2++) {
        if (nums[idx2] != val) {
            nums[idx] = nums[idx2];
            idx++;
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
    int removed = 1;
    printf("Remove %d\n", removed);

    int nums1[0] = {};
    showArray(nums1, 0);
    printf(" -> ");
    showArray(nums1, removeElement(nums1, 0, removed)); // []
    printf("\n");

    int nums2[1] = {1};
    showArray(nums2, 1);
    printf(" -> ");
    showArray(nums2, removeElement(nums2, 1, removed)); // []
    printf("\n");

    int nums3[1] = {2};
    showArray(nums3, 1);
    printf(" -> ");
    showArray(nums3, removeElement(nums3, 1, removed)); // [2]
    printf("\n");

    int nums4[2] = {1, 1};
    showArray(nums4, 2);
    printf(" -> ");
    showArray(nums4, removeElement(nums4, 2, removed)); // []
    printf("\n");

    int nums5[3] = {1, 1, 1};
    showArray(nums5, 3);
    printf(" -> ");
    showArray(nums5, removeElement(nums5, 3, removed)); // []
    printf("\n");

    int nums6[3] = {1, 1, 2};
    showArray(nums6, 3);
    printf(" -> ");
    showArray(nums6, removeElement(nums6, 3, removed)); // [2]
    printf("\n");

    int nums7[3] = {1, 2, 1};
    showArray(nums7, 3);
    printf(" -> ");
    showArray(nums7, removeElement(nums7, 3, removed)); // [2]
    printf("\n");

    int nums8[3] = {2, 1, 1};
    showArray(nums8, 3);
    printf(" -> ");
    showArray(nums8, removeElement(nums8, 3, removed)); // [2]
    printf("\n");

    int nums9[4] = {1, 1, 1, 1};
    showArray(nums9, 4);
    printf(" -> ");
    showArray(nums9, removeElement(nums9, 4, removed)); // []
    printf("\n");

    int nums10[4] = {1, 1, 2, 2};
    showArray(nums10, 4);
    printf(" -> ");
    showArray(nums10, removeElement(nums10, 4, removed)); // [2, 2]
    printf("\n");

    int nums11[4] = {1, 2, 2, 1};
    showArray(nums11, 4);
    printf(" -> ");
    showArray(nums11, removeElement(nums11, 4, removed)); // [2, 2]
    printf("\n");

    int nums12[4] = {2, 2, 1, 1};
    showArray(nums12, 4);
    printf(" -> ");
    showArray(nums12, removeElement(nums12, 4, removed)); // [2, 2]
    printf("\n");

    int nums13[4] = {2, 2, 2, 2};
    showArray(nums13, 4);
    printf(" -> ");
    showArray(nums13, removeElement(nums13, 4, removed)); // [2, 2, 2, 2]
    printf("\n");

    return 0;
}
