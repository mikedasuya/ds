#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	char * ptr = "its a day";
	char * ptr1 = (char*) malloc(strlen(ptr)+1);
	for (int i = 0; i < strlen(ptr);i++) {
		ptr1[i] = ptr[i];
	}
	*(ptr1+ strlen(ptr)) = '\0';
	printf("\n -----final string is :%s: --\n", ptr1);fflush(stdout);
}
