#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int* convertStringToInt(int , char* , int );
int fetchInt(char* , int , int );

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int n; // the number of temperatures to analyse
    scanf("%d", &n); fgetc(stdin);
    char temps[257]; // the n temperatures expressed as integers ranging from -273 to 5526
    fgets(temps, 257, stdin); // the n temperatures expressed as integers ranging from -273 to 5526

    // Write an action using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");
    if (n == 0) {
        printf("0\n");
        return 0;
    }
	
	int* nums = convertStringToInt(n, temps, strlen(temps));
	int diff = 5527;
	int resultIdx = -1;

	for (int idx = 0; idx < n; idx++) {
	    if (nums[idx] >= 0) {
		    if ((nums[idx] - 0) <= diff) {		
			    diff = nums[idx] - 0;
			    resultIdx = idx;
		    }
	    } else {
		    if ((0-nums[idx]) < diff) {
		        diff = 0 - nums[idx];
		        resultIdx = idx;
		    }
		}
	}
	printf("%d\n", nums[resultIdx]);

    return 0;
}

int* convertStringToInt(int numSize, char* str, int length) {
	int nums[numSize];
	int numLength	= 0;
	int numIdx		= 0;
    for (int idx = 0; idx < length; idx++) {
        if (*(str + idx) ^ 0x20) numLength++;
		else {
			nums[numIdx++] = fetchInt(str, idx - numLength, numLength);
			numLength = 0;
		}
	}
	nums[numIdx] = fetchInt(str, length - numLength, numLength);
	return nums;
}

int fetchInt(char* str, int startIdx, int numLength) {
	char tmp[numLength+1];
	int tmpIdx = 0;
	int limit = startIdx + numLength;
	
	for (;startIdx < limit; startIdx++) {
		tmp[tmpIdx++] = *(str+startIdx);
	}
	tmp[tmpIdx] = '\0';
	
	fprintf(stderr, "tmp %s\n", tmp);
	fprintf(stderr, "str %s\n", str);
	
	return atoi(tmp);
}
