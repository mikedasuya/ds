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
		printf("\n enter the column number \n");fflush(stdout);
		scanf ("%d", &coul);
		ch = row;
        if (ch == 10) {
            break;
        }
		ar[row][coul] = ZERO;
		printGame(ar);
		calculateComputerMove(ar);
		printGame(ar);
		
		
	}
	delete contr;

}
