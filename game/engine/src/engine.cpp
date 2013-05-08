#include "engine.h"
#include "Common.h"
#include <stdio.h>
#include <stdlib.h>


Engine::Engine(INPUT in) {
	forWhom = in;
}

int Engine::evaluateState(int ar[3][3]) {
	
	int columnforCross = column(ar, forWhom);
	printf ("\n ------columforZero -:%d:--\n", columnforCross);fflush(stdout);
	/*
	int rowforZero = row(ar, INPUT::ZERO);
	int diagnalForZero = diagnal(ar, INPUT::ZERO);

	int sumforZero = columforZero + rowforZero + diagnalForZero;
	
	int columnforCross = column(ar, INPUT::CROSS);
	int rowforCross = row(ar, INPUT::CROSS);
	int diagnalForCross = diagnal(ar, INPUT::CROSS);
	*/
}

int Engine::column(int ar[3][3], INPUT val) {

	int count = 0;
	if ((ar[0][0] == 0 &&
	    ar[1][0] == 0 &&
	    ar[2][0] == 0))
	 {
		count++;
	} else if (colum0Contains(ar, val)) {
		count++;
	}

	if (ar[0][1] == 0 &&
	    ar [1][1] == 0 &&
	    ar [2] [1] == 0 ) {
		count++;
	} else 	if (colum1Contains(ar, val)) {
		count++;
	}

	if (ar[0] [3] == 0 &&
	    ar[1] [3] == 0 &&
	    ar[2] [3] == 0) {
		count ++;
	} else 	if (colum2Contains(ar, val)) {
		count++;
	}

	return count;

}	

bool Engine::colum0Contains(int ar[3][3], INPUT val) {
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

bool Engine::colum1Contains(int ar[3][3], INPUT val) {
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


bool Engine::colum2Contains(int ar[3][3], INPUT val) {
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

