#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *ptr = "its not a day";
	char* ptr1 = "day1";
	int len = strlen(ptr);
	int cmplen = strlen(ptr1);
	int result = true;
	for (int i = len-1, j = cmplen -1 ; j >=0;j--,i--) {
		if (ptr[i] == ptr1[j]) {
			result = true;
		} else {
			result = false;
			break;
		}
	}
	if (result == true) {
		printf("\n ----got it equal \n");fflush(stdout);
	} else {
		printf("\n ----got it unequal \n");fflush(stdout);
	}
	
}
