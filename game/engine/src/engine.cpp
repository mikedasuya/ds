#include "engine.h"
#include "Common.h"
#include <stdio.h>
#include <stdlib.h>

namespace ENGINE {

Engine::Engine() {
}

int Engine::evaluateState(int ar[3][3], INPUT forWhom) {
	int columnC = column(ar, CROSS);
	int rowsC = rows(ar, CROSS);
	int diagnal = diagnals(ar, CROSS);
	int sum = columnC+rowsC+diagnal;
	printf ("\n ------total for cross-:%d:--\n", sum);fflush(stdout);
	columnC = column(ar, ZERO);
	rowsC = rows(ar, ZERO);
	diagnal = diagnals(ar, ZERO);
	int sumZ = columnC+rowsC+diagnal;
    if (userWinCompulsion(ar)) {
        if (doesUserWinsInNextMove(ar)) {
            return -20;
        }
    }
	return sum - sumZ;
}

bool doesUserCompulsionAfterNextMove(int ar[3][3]) {
        bool result = false;
        struct Param * p = NULL;
        int count = 0;
        if ( p = column0Wins(ar, ZERO) != NULL) {
            count++;
            result = true;
        }
        if ( p = column1Wins(ar, ZERO) != NULL) {
            count++;
            result = true;
        }
        if ( p = column2Wins(ar, ZERO) != NULL) {
            result = true;
            count++;
        }
        if ( p = row0Wins(ar, ZERO) != NULL) {
            result = true;
            count++;
        }
        if ( p = row1Wins(ar, ZERO) != NULL) {
            result = true;
            count++;
        }
        if ( p = row2Wins(ar, ZERO) != NULL) {
            result = true;
            count++;
        }
        if ( p = diagnal1Wins(ar, ZERO) != NULL) {
            result = true;
            count++;
        }
        if ( p = diagnal2Wins(ar, ZERO) != NULL) {
            result = true;
            count++;
        }
        if (result == true && count == 2) {
            result = true;
        } else {
            result = false;
        }
        return result;

}

bool Engine::isGamePossible(int ar[][]) {

    //check if already there are 3 zero or 3 cross
    if (column(CROSS) + rows(CROSS) > 0 ||
        column(ZERO) + rows(ZERO) > 0 ) {
        return true;
    }
    return false;

}

bool Engine::isComputerWinning(int ar[3][3]) {
        if ( column0Wins(ar, CROSS) ||
              column1Wins(ar, CROSS) ||
              column2Wins(ar, CROSS) ||
              row0Wins(ar, CROSS) ||
              row1Wins(ar, CROSS) ||
              row2Wins(ar, CROSS) ||
              diagnal1Wins(ar, CROSS) ||
              diagnal2Wins(ar, CROSS)
            
            ) {
            printf("\n ---computr wins --\n");fflush(stdout);
            return true;
        }
        return false;
}

bool Engine::internalUserCompulsion(int ar[3][3], struct Param * pa, INPUT val) {
    ar[pa->rows][pa->columns] = val;
    return true;
}

bool Engine::UserWinCompulsion(int ar[3][3]) {
        bool result = false;
        struct Param * p = NULL;
        if ( p = column0Wins(ar, ZERO) != NULL) {
            internalUserCompulsion(ar, p, CROSS);
            result = true;
        }
        if ( p = column1Wins(ar, ZERO) != NULL) {
            internalUserCompulsion(ar, p, CROSS);
            result = true;
        }
        if ( p = column2Wins(ar, ZERO) != NULL) {
            internalUserCompulsion(ar, p, CROSS);
            result = true;
        }
        if ( p = row0Wins(ar, ZERO) != NULL) {
            internalUserCompulsion(ar, p, CROSS);
            result = true;
        }
        if ( p = row1Wins(ar, ZERO) != NULL) {
            internalUserCompulsion(ar, p, CROSS);
            result = true;
        }
        if ( p = row2Wins(ar, ZERO) != NULL) {
            internalUserCompulsion(ar, p, CROSS);
            result = true;
        }
        if ( p = diagnal1Wins(ar, ZERO) != NULL) {
            internalUserCompulsion(ar, p, CROSS);
            result = true;
        }
        if ( p = diagnal2Wins(ar, ZERO) != NULL) {
            internalUserCompulsion(ar, p, CROSS);
            result = true;
        }
        if (result == true) {
            printf("\n ---------user win compulsion --\n");fflush(stdout);
        }
        return result;

}

struct Param * Engine::calculateColumnWins(int ar[3][3], INPUT val , int ro) {
      int j = ro;
      bool result = false;
      int rows = 0;
      INPUT value = CROSS;
      if (val == CROSS) {
          value = ZERO;
      } else {
          value = CROSS;
      }
      int column = 0;
      struct Param * p = NULL;
      int count = 0;
      for (int i = 0; i < 3; i++) {
            if (ar[i][j] == val ) {
                count++;
                result = true;
            } else if (ar[i][j] == 0) {
                rows = i;
                column = j;
                result = true;
            } else if (ar[i][j] == value) {
                result = false;
                break;
            }
      }
      if (count == 2 && result == true) {
          p = new Param();
          p->row = rows;
          p->column = column;
          result = true;
      }
      return p;
}

struct Param* column0Wins(int ar[3][3], INPUT val) {
     return calculateColumnWins(ar, val , 0) ;
}

struct Param * Engine::column1Wins(int ar[3][3], INPUT val) {
     return calculateColumnWins(ar, val , 1) ;
}


struct Param * Engine::column2Wins(int ar[3][3], INPUT val) {
     return calculateColumnWins(ar, val , 2) ;
}

struct Param * Engine::calculateRowWins(int ar[3][3], INPUT val, int colu) {
      int j = colu;
      bool result = false;
      int count = 0;
      int rows = 0;
      int column = 0;
      INPUT value = CROSS;
      if (val == CROSS) {
          value = ZERO;
      } else {
          value = CROSS;
      }
      struct Param * p = NULL;
      for (int i = 0; i < 3; i++) {
            if (ar[j][i] == val ) {
                count++;
                result = true;
            } else if (ar[j][i] == 0) {
                rows = j;
                column = i;
                result = true;
            } else if (ar[j][i] == value) {
                result = false;
                break;
            }
      }
      if (count == 2 && result == true) {
          p = new Param();
          p->row = rows;
          p->column = column;
          result = true;

}

struct Param * Engine::row0Wins(int ar[3][3], INPUT val) {
    calculateRowWins(ar, val, 0);
}

struct Param* Engine::row1Wins(int ar[3][3], INPUT val) {
    calculateRowWins(ar, val, 1);
}

struct Param* Engine::row2Wins(int ar[3][3], INPUT val) {
    calculateRowWins(ar, val, 2);
}



int Engine::diagnals(int ar[3][3], INPUT val) {
	int count = 0;
    count = diagnal1(ar, val) + diagnal2(ar, val);
	return count;
		
}

bool Engine::diagnal1Wins(int ar[][], INPUT val) {
	bool result = false;
    int rows = 0;
    int column = 0;
    INPUT value = CROSS;
    if (val == CROSS) {
        value = ZERO;
    } else {
        value = CROSS;
    }
    struct Param * p = NULL;
    for (int j = 0, i = 2; j < 3, i > -1;j++ ,i--) {
            if (ar[i][j] == val) { 
                count++;
                result = true;
            } else if (ar[i][j] == 0) {
                rows = i;
                column = j;
                result = true;
            } else if (ar[i][j] == value) {
                result = false;
                break;
            }
    }
    if (count == 2 && result == true) {
        p = new Param();
        p->rows = rows;
        p->column = column;
    }
    return p;

}

struct Param * Engine::diagnal2Wins(int ar[][], INPUT val) {
	bool result = false;
    int rows = 0;
    int column = 0;
    INPUT value = CROSS;
    if (val == CROSS) {
        value = ZERO;
    } else {
        value = CROSS;
    }
    struct Param * p = NULL;
    for (int j = 0, i = 2; j < 3, i > -1;j++ ,i--) {
            if (ar[j][i] == val) { 
                count++;
                result = true;
            } else if (ar[j][i] == 0) {
                rows = j;
                column = i;
                result = true;
            } else if (ar[j][i] == value) {
                result = false;
                break;
            }
    }
    if (count == 2 && result == true) {
        p = new Param();
        p->rows = rows;
        p->column = column;
    }
    return p;
}



bool Engine::diagnal1(int ar[3][3], INPUT val) {
	bool result = false;
    for (int j = 0, i = 2; j < 3, i > -1;j++ ,i--) {
            if (ar[i][j] == val ||
                ar[i][j] == 0 ) {
                count++
            }
    }
    if (count == 3) {
        result = true;
    }
	return result;
}

bool Engine::diagnal2(int ar[3][3], INPUT val) {
	bool result = false;
    for (int j = 0, i = 2; j < 3, i > -1;j++ ,i--) {
            if (ar[j][i] == val ||
                ar[j][i] == 0 ) {
                count++
            }
    }
    if (count == 3) {
           result = true;
    }
	return result;
}

int Engine::rows(INPUT val) {
	int count = 0;
	if ( row0Contain(val)) {
		count++;
	}
	if (row1Contain(val)) {
		count++;
	}
	if (row2Contain(val)) {
		count++;
	}
	return count;

}

bool row0Contains(int ar[3][3], INPUT val) {
      int j = 0;
      bool result = false;
      int count = 0;
      for (int i = 0; i < 3; i++) {
            if (ar[j][i] == val ||
                ar[j][i] == 0) {
                count++;
            }
      }
      if (count == 3) {
          result = true;
      }
      return result;
}

bool row1Contains(int ar[3][3], INPUT val) {
      int j = 1;
      bool result = false;
      int count = 0;
      for (int i = 0; i < 3; i++) {
            if (ar[j][i] == val ||
                ar[j][i] == 0 ) {
                count++;
            }
      }
      if (count == 3) {
          result = true;
      }
      return result;
}

bool row2Contains(int ar[3][3], INPUT val) {
      int j = 2;
      bool result = false;
      int count = 0;
      for (int i = 0; i < 3; i++) {
            if (ar[j][i] == val ||
                ar[j][i] == 0 ) {
                count++;
            }
      }
      if (count == 3) {
          result = true;
      }
      return result;
}

int Engine::column(INPUT val) {

	int count = 0;
	if (colum0Contains(val)) {
		count++;
	}
	if (colum1Contains(val)) {
		count++;
	}
	if (colum2Contains(val)) {
		count++;
	}

	return count;

}	

bool column0Contains(int ar[3][3], INPUT val) {
      int j = 0;
      bool result = false;
      int count = 0;
      for (int i = 0; i < 3; i++) {
            if (ar[i][j] == val  ||
                ar[i][j] == 0 ) {
                count++;
            }
      }
      if (count == 3) {
          result = true;
      }
      return result;
}

bool column1Contains(int ar[3][3], INPUT val) {
      int j = 1;
      bool result = false;
      int count = 0;
      for (int i = 0; i < 3; i++) {
            if (ar[i][j] == val || 
             ar[i][j] == 0 ) {
                count++;
            
      }
      if (count == 3) {
          result = true;
      }
      return result;
}


bool column2Contains(int ar[3][3], INPUT val) {
      int j = 2;
      bool result = false;
      int count = 0;
      for (int i = 0; i < 3; i++) {
            if (ar[i][j] == val ||
                ar[i][j] == 0 ) {
                count++;
            }
      }
      if (count == 3) {
          result = true;
      }
      return result;
}


}
