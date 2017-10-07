/*
 * Source: https://leetcode.com/problems/implement-strstr/description/
 * Author: W.D Su
 * Date:   10/06/2017
*/

#include "stdio.h"
#include "stdlib.h"

int strStr(char* haystack, char* needle) {
    if (needle[0] == '\0') return 0;
    
    char* tmp = haystack;
    int l1 = 0;
    while (*tmp++ != '\0') l1++;
    tmp = needle;
    int l2 = 0;
    while (*tmp++ != '\0') l2++;
    
    int strIdx = 0;
    int idx = 0;
    while (l1 >= l2) {
        while (needle[idx] != '\0') {
            if (haystack[idx] == needle[idx]) {
                idx++;
                if (needle[idx] == '\0') return strIdx;
            } else {
                break;
            }
        }
        strIdx++;
        haystack++;
        l1--;
        idx = 0;
    }
    return -1;
}

int main(int argv, char* argc[]) {
    printf("%d\n", strStr("", ""));                 // 0
    printf("%d\n", strStr("a", "a"));               // 0
    printf("%d\n", strStr("b", "a"));               // -1
    printf("%d\n", strStr("ab", "a"));              // 0
    printf("%d\n", strStr("ba", "a"));              // 1
    printf("%d\n", strStr("ab", "ab"));             // 0
    printf("%d\n", strStr("mississippi", "issip")); // 4
    return 0;
}
