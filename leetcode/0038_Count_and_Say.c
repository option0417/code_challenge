/*
 * Source: https://leetcode.com/problems/count-and-say/description/
 * Author: W.D Su
 * Date:   10/12/2017
*/
#include "stdio.h"
#include "stdlib.h"

struct CurrStr {
    char* str;
    int length;
};

// Slow version
void concatString(struct CurrStr* currStr, char ch, int amount) {
    char* str = malloc(currStr->length + amount + 2);
    
    int cnt = 0;
    while (cnt < currStr->length) {
        str[cnt] = currStr->str[cnt];
        cnt++;
    }

    str[cnt] = (amount + 48); 
    str[cnt+1] = ch; 
    str[cnt+2] = '\0';
    
    currStr->str = str;
    currStr->length += 2;
}

// Slow version
char* countAndSay2(int n) {
    char* STRING_TABLE[11] = {
        "", "1", "11", "21", "1211", "111221",
        "312211", "13112221", "1113213211", "31131211131221", "13211311123113112211"
    };
    if (n <= 10) return STRING_TABLE[n];
    
    char* str = STRING_TABLE[10];
    int cnt, charCnt;

    while (n-- > 10) {
        cnt      = 1;
        charCnt  = 1;
        struct CurrStr* currStr = malloc(sizeof(struct CurrStr));
        while (str[cnt] != '\0') {
            if (str[cnt] != str[cnt-1]) {
                concatString(currStr, str[cnt-1], charCnt);
                charCnt = 1;
            } else {
                charCnt++;
            }
            cnt++;
        }
        
        if (charCnt) concatString(currStr, str[cnt-1], charCnt);
        str = currStr->str;
    }
    return str;
}

char* countAndSay(int n) {
    char* STRING_TABLE[11] = {
        "", "1", "11", "21", "1211", "111221",
        "312211", "13112221", "1113213211", "31131211131221", "13211311123113112211"
    };
    if (n <= 10) return STRING_TABLE[n];
    
    char* str = STRING_TABLE[10];
    int idx, cnt, charCnt, l = 20;
    while (n-- > 10) {
        idx      = 0;
        cnt      = 1;
        charCnt  = 1;
        
        char* tmpStr = malloc(sizeof(char) * l * 2 + 1);
        while (str[cnt] != '\0') {
            if (str[cnt] != str[cnt-1]) {
                tmpStr[idx++] = charCnt + 48;
                tmpStr[idx++] = str[cnt-1];
                charCnt = 1;
            } else {
                charCnt++;
            }
            cnt++;
        }
        
        if (charCnt) {
            tmpStr[idx++] = charCnt + 48;
            tmpStr[idx++] = str[cnt-1];
        }
        tmpStr[idx] = '\0';
        l = idx-1;
        str = tmpStr;
    }
    return str;
}

int main(int argv, char* argc[]) {
  printf("%d -> %s\n", 1, countAndSay(1));    // 1
  printf("%d -> %s\n", 2, countAndSay(2));    // 11
  printf("%d -> %s\n", 3, countAndSay(3));    // 21
  printf("%d -> %s\n", 4, countAndSay(4));    // 1211
  printf("%d -> %s\n", 5, countAndSay(5));    // 111221
  printf("%d -> %s\n", 6, countAndSay(6));    // 312211
  printf("%d -> %s\n", 7, countAndSay(7));    // 13112221
  printf("%d -> %s\n", 8, countAndSay(8));    // 1113213211
  printf("%d -> %s\n", 9, countAndSay(9));    // 31131211131221
  printf("%d -> %s\n", 10, countAndSay(10));  // 13211311123113112211
  printf("%d -> %s\n", 11, countAndSay(11));  // 11131221133112132113212221
  printf("%d -> %s\n", 12, countAndSay(12));  // 3113112221232112111312211312113211
  return 0;
}
