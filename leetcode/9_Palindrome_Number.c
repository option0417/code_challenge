#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

/*
 * Source: https://leetcode.com/problems/palindrome-number/description/
 * Author: W.D Su
 * Date:   09/27/2017
*/
bool isPalindrome(int x) {
    if (x < 0) return false;
    if (x/10 == 0) return true;
    if (x%10 == x/10) return true; else if ((x/10)/10 == 0) return false;
    if (x%10 == 0) return false;
    
    int reverHalf = 0;
    
    while (x > reverHalf) {
        reverHalf = reverHalf * 10 + x % 10;
        x /= 10;
    }
    
    return (x == reverHalf) || (x == reverHalf/10);
}

int main(int argc,  char* argv[]) {
  printf("%d\n", isPalindrome(-1));     // false
  printf("%d\n", isPalindrome(0));      // true
  printf("%d\n", isPalindrome(1));      // true
  printf("%d\n", isPalindrome(12));     // false
  printf("%d\n", isPalindrome(22));     // true
  printf("%d\n", isPalindrome(111));    // true
  printf("%d\n", isPalindrome(123));    // false
  printf("%d\n", isPalindrome(121));    // true
  printf("%d\n", isPalindrome(100));    // false
  printf("%d\n", isPalindrome(1021));   // false
  printf("%d\n", isPalindrome(1231));   // false
  printf("%d\n", isPalindrome(1221));   // true
  printf("%d\n", isPalindrome(12321));  // true
  printf("%d\n", isPalindrome(12311));  // false
  printf("%d\n", isPalindrome(10201));  // true
  printf("%d\n", isPalindrome(123123)); // false
  printf("%d\n", isPalindrome(1000021));// false
  return 0;
}
