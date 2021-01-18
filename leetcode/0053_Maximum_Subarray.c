/*
 * Source: https://leetcode.com/problems/maximum-subarray/description/
 * Author: W.D Su
 * Date:   10/13/2017
*/
#include "stdio.h"
#include "stdlib.h"

// O(n2)
int maxSubArray2(int* nums, int numsSize) {
    int max = nums[0];
    int cnt = 0;
    int tmp = 0;
    for (int select = 1; select < numsSize; select++) {
        for (int idx = 0; idx < numsSize; idx++) {
            
            while (cnt < select) {
                tmp += nums[idx + cnt];
                cnt++;
            }
            if (max < tmp) max = tmp;
            
            tmp = 0;
            cnt = 0;
        }
    }
    return max;
}

// O(n)
int maxSubArray(int* nums, int numsSize) {
    int max = nums[0]
    int cnt = 0;
    int tmp = 0;
    
    for (; cnt < numsSize; cnt++) {
        tmp += nums[cnt];
        max = tmp > max ? tmp : max;
        tmp = tmp > 0 ? tmp : 0;
    }
    return max;
}


int main(int argv, char* argc[]) {
  int nums1[1] = {1};
  maxSubArray(nums1, 1);

  int nums2[2] = {1, -1};  
  maxSubArray(nums2, 2);

  int nums3[2] = {-1, 1};  
  maxSubArray(nums3, 2);

  int nums4[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};  
  printf("max: %d\n", maxSubArray(nums4, 9));

  return 0;
}
