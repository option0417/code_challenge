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

int reverse3(int x) {
    if (x >= 2147483647 || x <= -2147483648) {
        return 0;
    }
    
    int remind = 0;
    int mul = 0;
    int reverse = 0;
    bool isConvert = false;
    
    if (x < 0) {
        x = -x;
        isConvert = true;
    }
    
    while (x > 0) {
        remind = x%10;
        x = x/10;
        
        mul = x > 0 ? 10 : 1;
        if (reverse+remind > 214748364 && mul == 10) {
            return 0;
        }
        
        reverse = (reverse + remind) * mul;
    }
    
    if (isConvert) {
        reverse = -reverse;
    }
    
    return reverse;
}
