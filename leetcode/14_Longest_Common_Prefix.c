/*
 * Source: https://leetcode.com/problems/longest-common-prefix/description/
 * Author: W.D Su
 * Date:   09/29/2017
*/
#include "stdio.h"
#include "stdlib.h"


char* longestCommonPrefix(char** strs, int strsSize) {
    char* str = strs[0];
    int chIdx = 0;
    int flag = 1;

    while (str[chIdx] != '\0' && flag) {
        for (int idx = 1; idx < strsSize; idx++) {
          char* str2 = strs[idx];
          if (str[chIdx] != str2[chIdx]) {
            flag = 0;
            chIdx--;
            break;
          }
        }

        if (flag) chIdx++;
    }
    
    if (chIdx) {
        char* prefix = (char*)malloc(sizeof(char) * chIdx);
        while (chIdx >= 0) {
            prefix[chIdx] = str[chIdx];
            chIdx--;
        }
        return prefix;
    }
    return "";
}

int main(int argv, char* argc[]) {
  char* str1[] = {"a"};
  printf("[%s]: %s\n", str1[0], longestCommonPrefix(str1, 1));

  char* str2[] = {"a", "ab", "abc"};
  printf("[%s, %s, %s]: %s\n", str2[0], str2[1], str2[2], longestCommonPrefix(str2, 3));

  char* str3[] = {"a", "ab", "abc", "b"};
  printf("[%s, %s, %s, %s]: %s\n", str3[0], str3[1], str3[2], str3[3], longestCommonPrefix(str3, 4));

  char* str4[] = {"ab", "ab", "abc"};
  printf("[%s, %s, %s]: %s\n", str4[0], str4[1], str4[2], longestCommonPrefix(str4, 3));

  char* str5[] = {"abc", "abcd", "abcde"};
  printf("[%s, %s, %s]: %s\n", str5[0], str5[1], str5[2], longestCommonPrefix(str5, 3));
  return 0;
}
