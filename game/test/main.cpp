#include <stdlib.h>
#include <stdio.h>
#include "engine.h"
#include "Common.h"

int main() {
	printf("\n -----main ---\n");fflush(stdout);
	int ar[3][3] = { {0,0,0} ,
		       {0,1,0},
		       {0,0,0}
		    };
	Engine * eng = new Engine(ZERO);
	eng->evaluateState(ar);
}
