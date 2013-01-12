#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	char *ptr = "its a day";
	char *ptr1 = "its not a day";
	char *ptrsum = (char*)malloc(strlen(ptr) + strlen(ptr1) + 1);
	int i = 0;
	for (; i < strlen(ptr);i++) {
		ptrsum[i] = ptr[i];		
	}
	for (int j = 0;j < strlen(ptr1);j++) {
		ptrsum[i] = ptr1[j];
		i++;
	} 
	*(ptrsum + strlen(ptr) + strlen(ptr1)) = '\0';
	printf("\n -------final --:%s: --\n", ptrsum);fflush(stdout);
}
