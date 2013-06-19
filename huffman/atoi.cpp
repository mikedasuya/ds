#include <stdio.h>
#include <stdlib.h>


int main() {
	char * ptr = (char*) malloc(4);
	ptr[0] ='1';
	ptr[1] = '2';
	ptr[2] ='3';
	ptr[3] = '\0';
	char *mvptr = ptr;
	int sum= 0;
	while (*mvptr !='\0') {
		char  ch = *mvptr;
		sum = sum*10+ ch-'0';
		mvptr++;
	}
	printf("\n --integer value is :%d: --\n", sum);fflush(stdout);

}
