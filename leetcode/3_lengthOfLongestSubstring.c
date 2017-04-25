/*
 * =====================================================================================
 *        Created: 25//04/2017
 *        Author:  W.D 
 * =====================================================================================
 */

#include "stdio.h"

int lengthOfLongestSubstring(char* s) {
	int beginIndex = 0;
	int endIndex = 0;
	int cnt = 0;
	int len = 0;
	char* tmpS = s;

	while (*tmpS != '\0') {
	  for (cnt = beginIndex; cnt < endIndex; cnt++) {
		  if (*tmpS == *(s+cnt)) {
				if (endIndex - beginIndex > len) {
			    len = endIndex - beginIndex;
				}
				beginIndex = endIndex;
			}
		}

		endIndex++;
		tmpS++;
	}

	if (endIndex - beginIndex > len) {
		len = endIndex - beginIndex;
	}

  return len;
}

int main(void) {
  char* s1 = "abcabcbb";  // 3
  char* s2 = "bbbbb";     // 1
  char* s3 = "pwwkew";    // 3
  char* s4 = "a";         // 1
  char* s5 = "abc";       // 3
  char* s6 = "aab";       // 2
  char* s7 = "ababc";     // 3
	char* s8 = "";          // 0

  int length = lengthOfLongestSubstring(s1);
	printf("Length: %d\n", length);

  length = lengthOfLongestSubstring(s2);
	printf("Length: %d\n", length);

  length = lengthOfLongestSubstring(s3);
	printf("Length: %d\n", length);

  length = lengthOfLongestSubstring(s4);
	printf("Length: %d\n", length);

  length = lengthOfLongestSubstring(s5);
	printf("Length: %d\n", length);

  length = lengthOfLongestSubstring(s6);
	printf("Length: %d\n", length);

  length = lengthOfLongestSubstring(s7);
	printf("Length: %d\n", length);

  length = lengthOfLongestSubstring(s8);
	printf("Length: %d\n", length);
	return 0;
}
