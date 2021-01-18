#include "stdio.h"

/*
 * Source: https://leetcode.com/problems/reverse-integer/description/
 * Author: W.D Su
 * Date:   09/27/2017
*/

int reverse(int );

int main(int argc, char* argv[]) {
  printf("%d\n", reverse(123));         // 321
  printf("%d\n", reverse(-123));        // -321
  printf("%d\n", reverse(2147483647));  // 0
  printf("%d\n", reverse(-2147483647)); // 0
  printf("%d\n", reverse(1463847412));  // 2147483641
  printf("%d\n", reverse(-1463847412)); // -2147483641
  printf("%d\n", reverse(1000000003));  // 0
  printf("%d\n", reverse(-1000000003)); // 0
  return 0;
}

int reverse(int x) {
    int reversed = 0;                                                                                        
                                                                                                              
    while (x) {
        if ((reversed > 214748364 || reversed < -214748364)) {
            return 0;
        }                                                                                          
        reversed = reversed*10 + x%10;
        x /= 10;
    }                                                    
                                                                                                              
    return reversed;
}

int reverse2(int x) {
    long long reversed = 0;
    
    while (x) {
        reversed = (reversed << 1) + (reversed << 3) + (x % 10);
        x /= 10;
    }

    return reversed > 2147483647 || reversed < -2147483646 ? 0 : reversed;
}
