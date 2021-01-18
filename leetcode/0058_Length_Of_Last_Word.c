/*
 * Source: https://leetcode.com/problems/length-of-last-word/description/
 * Author: W.D Su
 * Date:   10/16/2017
*/
#include "stdio.h"
#include "stdlib.h"

int lengthOfLastWord2(char* s) {
    if (!s[0]) return 0;
    
    int idx = 0, cnt = 0;
    idx = cnt = s[0] != ' ' ? 1 : 0;
    
    while (s[idx] != '\0') {
        if (s[idx] != ' ' && s[idx-1] == ' ') cnt = 1;
        else if (s[idx] != ' ') cnt++;
        idx++;
    }
    return cnt;
}

int lengthOfLastWord(char* s) {
    int l = 0;
    while (s[l++] != '\0');
    l -= 2;
    
    while (s[l] == ' ') l--;
    
    int cnt = 0;
    while (l >= 0) {
        if (s[l] != ' ') cnt++;
        else break;
        l--;
    }
    return cnt;
}

int main(int argv, char* argc[]) {
  printf("%s -> %d\n", "", lengthOfLastWord(""));                       // 0
  printf("%s -> %d\n", "a", lengthOfLastWord("a"));                     // 1
  printf("%s -> %d\n", "a ", lengthOfLastWord("a "));                   // 1
  printf("%s -> %d\n", " a", lengthOfLastWord(" a"));                   // 1
  printf("%s -> %d\n", "a  b  ", lengthOfLastWord("a  b  "));           // 1
  printf("%s -> %d\n", "  a  b", lengthOfLastWord("  a  b"));           // 1
  printf("%s -> %d\n", "Hello World", lengthOfLastWord("Hello World")); // 5

  return 0;
}
