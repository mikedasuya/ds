#include <stdio.h>
#include <stdlib.h>

#define  MAXLIMIT 50

class ar {
	char key;
	int frquency; 
};

int main() {
	ar array[MAXLIMIT];
	ar obj1;
	obj1.key = 'H';
	obj1.val = 1;
	ar obj2;
	obj2.key = 'U';
	obj2.val = 1;
	ar obj3;
	obj3.key = 'F';
	obj3.val = 1;
	ar obj4;
	obj4.key = 'M';
	obj4.val = 2;
	ar obj5;
	obj5.key = 'A';
	obj5.val = 3;
	ar obj6;
	obj6.key = 'N';
	obj6.val = 3;
	array[6] = { obj2, obj1, obj3, obj5, obj4, obj6};
	insertionSort()
}
