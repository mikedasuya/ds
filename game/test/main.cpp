#include <stdlib.h>
#include <stdio.h>
#include "engine.h"
#include "Common.h"
#include "controller.h"

using namespace ENGINE;

Controller * contr = NULL;

int calculateComputerMove(int ar[3][3]) {
	
	return contr->nextMove(ar);
	
}

void printGame(int ar[3][3]) {
	printf("\n -------------------print -start---\n");fflush(stdout);
	for ( int i = 0; i < 3; i++) {
		printf("\n");fflush(stdout);
		for (int j = 0; j < 3; j++) {
			printf("%d|", ar[i][j]);fflush(stdout);
		}
		printf("\n");fflush(stdout);
	}

	printf("\n -------------------print -end---\n");fflush(stdout);

}
int main() {
	printf("\n -----main ---\n");fflush(stdout);
	int ar[3][3] = { {0,0,0} ,
		       {0,0,0},
		       {0,0,0}
		    };
	int ch;
	int row;
	int coul;
	contr = new Controller();
	while (ch != 10) {
		printf("\n enter the row number \n");fflush(stdout);
		scanf ("%d", &row);
        if (row < 0 || row > 2) {
            printf ("\n ---row hs to be between 0 & 2 --\n");fflush(stdout);
            continue;
        }
		printf("\n enter the column number \n");fflush(stdout);
		scanf ("%d", &coul);
        if (coul < 0 || coul > 2) {
            printf ("\n ---column hs to be between 0 & 2 --\n");fflush(stdout);
            continue;
        }
		ch = row;
        if (ch == 10) {
            break;
        }
        if (ar[row][coul] != 0) {
            printf("\n Already entry exisists, cannot override \n");fflush(stdout);
            continue;
        }
		ar[row][coul] = ZERO;
		printGame(ar);
		int val = calculateComputerMove(ar);
        if (val < 0) {
            printf("\n ---game over ---\n");fflush(stdout);
            break;
        }
		printGame(ar);
		
		
	}
	delete contr;

}
