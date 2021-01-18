public class Solution {
    public void merge1(int[] nums1, int m, int[] nums2, int n) {
        int tail = m + n - 1;
        m--;
        n--;
        
        while (m >= 0 && n >= 0) {
            if (nums1[m] > nums2[n]) {
                nums1[tail--] = nums1[m--];
            } else {
                nums1[tail--] = nums2[n--];
            }
        }
        
        while (n >= 0) {
            nums1[tail--] = nums2[n--];
        }
    }
    
    public void merge2(int[] nums1, int m, int[] nums2, int n) {
        int num1Idx = 0;
        int num2Idx = 0;
        int idx = 0;
        int tmpM = 0;
        
        for (num2Idx = 0; num2Idx < n; num2Idx++) {
            tmpM = m;
            
            for (num1Idx = 0; num1Idx < m; num1Idx++) {
                if (nums2[num2Idx] <= nums1[num1Idx]) {
                    for (idx = m; idx > num1Idx; idx--) {
                        nums1[idx] = nums1[idx-1];
                    }
                    nums1[num1Idx] = nums2[num2Idx];
                    m++;
                    break;
                }
            }
            
            if (tmpM == m) {
                nums1[m] = nums2[num2Idx];
                m++;
            }
        }
    }
}
