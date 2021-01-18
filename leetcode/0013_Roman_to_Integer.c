#include "stdio.h"
#include "stdlib.h"

/*
 * Source: https://discuss.leetcode.com/category/21/roman-to-integer
 * Author: W.D Su
 * Date:   09/28/2017
 * I V X  L  C   D   M
 * 1 5 10 50 100 500 1,000 
 *
 * IV IX XL XC CD  CM
 * 4  9  40 90 400 900
 * Example:
 *   1954 as MCMLIV
 *   1990 as MCMXC
 *   2014 as MMXIV
*/
int romanToInt(char* s) {
  int symbolCount[13] = {
    0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0 ,0
  };

  while (*s != '\0') {
    char roman = *s;  

    if (roman == 'I') {
        if (*(s+1) == 'X') {
            symbolCount[8]++;
            s++;
        } else if (*(s+1) == 'V') {
            symbolCount[7]++;
            s++;
        } else {
            symbolCount[0]++;
        }
    } else if (roman == 'V') {
        symbolCount[1]++;
    } else if (roman == 'X') {
        if (*(s+1) == 'L') {
            symbolCount[9]++;
            s++;
        } else if (*(s+1) == 'C') {
            symbolCount[10]++;
            s++;
        } else {
            symbolCount[2]++;
        }
    } else if (roman == 'L') {
        symbolCount[3]++;
    } else if (roman == 'C') {
        if (*(s+1) == 'D') {
            symbolCount[11]++;
            s++;
        } else if (*(s+1) == 'M') {
            symbolCount[12]++;
            s++;
        } else {
            symbolCount[4]++;
        }
    } else if (roman == 'D') {
        symbolCount[5]++;
    } else if (roman == 'M') {
        symbolCount[6]++;
    }
    s++;
  }

  int romanInt = 0;
  romanInt += symbolCount[0];
  romanInt += symbolCount[1] * 5;
  romanInt += symbolCount[2] * 10;
  romanInt += symbolCount[3] * 50;
  romanInt += symbolCount[4] * 100;
  romanInt += symbolCount[5] * 500;
  romanInt += symbolCount[6] * 1000;
  romanInt += symbolCount[7] * 4;
  romanInt += symbolCount[8] * 9;
  romanInt += symbolCount[9] * 40;
  romanInt += symbolCount[10] * 90;
  romanInt += symbolCount[11] * 400;
  romanInt += symbolCount[12] * 900;

  return romanInt;
}

int main(int argc, char* argv[]) {
  printf("%s = %d\n", "I", romanToInt("I"));                    // 1
  printf("%s = %d\n", "II", romanToInt("II"));                  // 2
  printf("%s = %d\n", "III", romanToInt("III"));                // 3
  printf("%s = %d\n", "IV", romanToInt("IV"));                  // 4
  printf("%s = %d\n", "V", romanToInt("V"));                    // 5
  printf("%s = %d\n", "VI", romanToInt("VI"));                  // 6
  printf("%s = %d\n", "VII", romanToInt("VII"));                // 7
  printf("%s = %d\n", "VIII", romanToInt("VIII"));              // 8
  printf("%s = %d\n", "IX", romanToInt("IX"));                  // 9
  printf("%s = %d\n", "X", romanToInt("X"));                    // 10
  printf("%s = %d\n", "XX", romanToInt("XX"));                  // 20
  printf("%s = %d\n", "XL", romanToInt("XL"));                  // 40
  printf("%s = %d\n", "L", romanToInt("L"));                    // 50
  printf("%s = %d\n", "XC", romanToInt("XC"));                  // 90
  printf("%s = %d\n", "C", romanToInt("C"));                    // 100
  printf("%s = %d\n", "CC", romanToInt("CC"));                  // 200
  printf("%s = %d\n", "CD", romanToInt("CD"));                  // 400
  printf("%s = %d\n", "D", romanToInt("D"));                    // 500
  printf("%s = %d\n", "CM", romanToInt("CM"));                  // 900
  printf("%s = %d\n", "M", romanToInt("M"));                    // 1000
  printf("%s = %d\n", "MM", romanToInt("MM"));                  // 2000
  printf("%s = %d\n", "DCXXI", romanToInt("DCXXI"));            // 621
  printf("%s = %d\n", "CCVII", romanToInt("CCVII"));            // 207
  printf("%s = %d\n", "MLXVI", romanToInt("MLXVI"));            // 1066
  printf("%s = %d\n", "MCMIV", romanToInt("MCMIV"));            // 1904
  printf("%s = %d\n", "MCMLIV", romanToInt("MCMLIV"));          // 1954
  printf("%s = %d\n", "MCMXC", romanToInt("MCMXC"));            // 1990
  printf("%s = %d\n", "MMXIV", romanToInt("MMXIV"));            // 2014
  printf("%s = %d\n", "MMMMMMMMMM", romanToInt("MMMMMMMMMM"));  // 10000
  return 0;
}
