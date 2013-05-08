#include "engine.h"
#include "Common.h"
#include <stdio.h>
#include <stdlib.h>

namespace ENGINE {

Engine::Engine() {
}

int Engine::evaluateState(int ar[3][3], INPUT forWhom) {
 	assign(ar);	
	int columnC = column(forWhom);
	printf ("\n ------colum -:%d:--\n", columnC);fflush(stdout);
	int rowsC = rows(forWhom);
	printf ("\n ------rows -:%d:--\n", rowsC);fflush(stdout);
	int diagnal = diagnals(forWhom);
	printf ("\n ------diagnal -:%d:--\n", diagnal);fflush(stdout);
	int sum = columnC+rowsC+diagnal;
	printf ("\n ------total -:%d:--\n", sum);fflush(stdout);
	return sum;
}
bool Engine::assign(int arr[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3;j++) {
			ar[i][j] = arr[i][j];
		}
	}

}

int Engine::diagnals(INPUT val) {
	int count = 0;
	if (val == CROSS) {
		val = ZERO;	
	} else if (val == ZERO) {
		val = CROSS;
	}

	if (ar[0][0] == 0 &&
	    ar[1][1] == 0 &&
	    ar[2][2] == 0) {
		count++;
	} else {
		if (ar[0][0] == val ||
		    ar[1][1] == val ||
		    ar[2][2] == val) {

		} else {
			count++;
		}	   
	}
	if (ar[2][0] == 0 &&
	    ar[1][1] == 0 &&
	    ar[0][2] == 0) {
		count++;
	} else {
		if (ar[2][0] == val ||
		    ar[1][1] == val || 
		    ar[0][2] == val) {
		
		} else {
			count++;
		}
	}
	return count;
		
}

int Engine::rows(INPUT val) {
	int count = 0;
	if (ar[0][0] == 0 && 	
	    ar[0][1] == 0 && 	
	    ar[0][2] == 0 ) {
		count++;
	} else if ( row0Contain(val)) {
		count++;
	}
	if (ar[1][0] == 0 && 	
	    ar[1][1] == 0 && 	
	    ar[1][2] == 0 ) {
		count++;
	} else if (row1Contain(val)) {
		count++;
	}
	if (ar[2][0] == 0 && 	
	    ar[2][1] == 0 && 	
	    ar[2][2] == 0 ) {
		count++;
	} else if (row2Contain(val)) {
		count++;
	}
	return count;

}

bool Engine::row0Contain(INPUT val) {
	if (val == CROSS) {
		val = ZERO;
	} else if (val == ZERO) {
		val = CROSS;
	}
	if (ar[0][0] == val ||
	    ar[0][1] == val ||
	    ar[0][2] == val)
	    {
		return false;
	}
	return true;

}

bool Engine::row1Contain(INPUT val) {
	if (val == CROSS) {
		val = ZERO;
	} else if (val == ZERO) {
		val = CROSS;
	}
	if (ar[1][0] == val ||
	    ar[1][1] == val ||
	    ar[1][2] == val)
	    {
		return false;
	}
	return true;

}


bool Engine::row2Contain(INPUT val) {
	if (val == CROSS) {
		val = ZERO;
	} else if (val == ZERO) {
		val = CROSS;
	}
	if (ar[2][0] == val ||
	    ar[2][1] == val ||
	    ar[2][2] == val)
	    {
		return false;
	}
	return true;

}

int Engine::column(INPUT val) {

	int count = 0;
	if ((ar[0][0] == 0 &&
	    ar[1][0] == 0 &&
	    ar[2][0] == 0))
	 {
		count++;
	} else if (colum0Contains(val)) {
		count++;
	}

	if (ar[0][1] == 0 &&
	    ar [1][1] == 0 &&
	    ar [2] [1] == 0 ) {
		count++;
	} else 	if (colum1Contains(val)) {
		count++;
	}

	if (ar[0] [2] == 0 &&
	    ar[1] [2] == 0 &&
	    ar[2] [2] == 0) {
		count ++;
	} else 	if (colum2Contains(val)) {
		count++;
	}

	return count;

}	

bool Engine::colum0Contains(INPUT val) {
	if (val == CROSS) {
		val = ZERO;
	} else if (val == ZERO) {
		val = CROSS;
	}
	if (ar[0][0] == val ||
	    ar[1][0] == val ||
	    ar[2][0] == val) {
		return false;
	}
	return true;
}

bool Engine::colum1Contains(INPUT val) {
	if (val == CROSS) {
		val = ZERO;
	} else if (val == ZERO) {
		val = CROSS;
	}
	if (ar[0][1] == val ||
	    ar[1][1] == val ||
	    ar[2][1] == val) {
		return false;
	}
	return true;
}


bool Engine::colum2Contains(INPUT val) {
	if (val == CROSS) {
		val = ZERO;
	} else if (val == ZERO) {
		val = CROSS;
	}
	if (ar[0][2] == val ||
	    ar[1][2] == val ||
	    ar[2][2] == val) {
		return false;
	}
	return true;
}
}
