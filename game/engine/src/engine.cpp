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

bool Engine::isGamePossible(int ar[][]) {

    //check if already there are 3 zero or 3 cross
    if (isWinning(ar, ZERO) || isWinning(ar, CROSS)) {
        return false;
    }
    if (column(CROSS) + rows(CROSS) > 0 ||
        column(ZERO) + rows(ZERO) > 0 ) {
        return true;
    }
    return false;

}

bool Engine::UserWinCompulsion(int ar[3][3]) {
        

}

bool Engine::assign(int arr[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3;j++) {
			ar[i][j] = arr[i][j];
		}
	}

}


//checks whether there are rows with all ZERO or all cross.
//In that case no need to proceed further.

bool isWinning(int a[3][3], INPUT forWhom) {

    bool result = false;
    int count = 0;
    //check rows for all cross or zero
    for (int i = 0; i < 3 ;i++) {
        for (int j = 0;j < 3; j++) {
            if (ar[i][j] == val) {
                count++;
            }
        }
        if (count == 3) {
            result = true;
            break;
        }
        count = 0;
    }
    count = 0;
    if (result == false) {
        //check all column for all cross or zero
        for (int i = 0; i < 3 ;i++) {
            for (int j = 0;j < 3; j++) {
                if (ar[j][i] == val) {
                    count++;
                }
            }
            if (count == 3) {
                result = true;
                break;
            }
            count = 0;

        }
    }
    count = 0;
    if (result == false) {
        //check for diagnals for all cross or zero
        for (int i = 0, j = 2; i < 3, j > -1 ;i++, j--) {
            if (ar[i][j] == val) {
                count++;
            }
        }
        if (count == 3) {
            result = true;
        }
    }
    if (result == false) {
        //check diagnal
        for (int i = 0, j = 2; i < 3, j > -1 ;i++, j--) {
            if (ar[j][i] == val) {
                count++;
            }
        }
        if (count == 3) {
            result = true;
        }
    }
    return result;
    
}


bool column0Wins(int ar[3][3], INPUT val) {
      int j = 0;
      bool result = false;
      int count = 0;
      for (int i = 0; i < 3; i++) {
            if (ar[i][j] == val ) {
                count++;
            }
      }
      if (count == 2) {
          result = true;
      }
      return result;
}

bool column1Wins(int ar[3][3], INPUT val) {
      int j = 1;
      bool result = false;
      int count = 0;
      for (int i = 0; i < 3; i++) {
            if (ar[i][j] == val ) {
                count++;
            }
      }
      if (count == 2) {
          result = true;
      }
      return result;
}


bool column2Wins(int ar[3][3], INPUT val) {
      int j = 2;
      bool result = false;
      int count = 0;
      for (int i = 0; i < 3; i++) {
            if (ar[i][j] == val ) {
                count++;
            }
      }
      if (count == 2) {
          result = true;
      }
      return result;
}


bool row0Wins(int ar[3][3], INPUT val) {
      int j = 0;
      bool result = false;
      int count = 0;
      for (int i = 0; i < 3; i++) {
            if (ar[j][i] == val ) {
                count++;
            }
      }
      if (count == 2) {
          result = true;
      }
      return result;
}

bool row1Wins(int ar[3][3], INPUT val) {
      int j = 1;
      bool result = false;
      int count = 0;
      for (int i = 0; i < 3; i++) {
            if (ar[j][i] == val ) {
                count++;
            }
      }
      if (count == 2) {
          result = true;
      }
      return result;
}

bool row2Wins(int ar[3][3], INPUT val) {
      int j = 2;
      bool result = false;
      int count = 0;
      for (int i = 0; i < 3; i++) {
            if (ar[j][i] == val ) {
                count++;
            }
      }
      if (count == 2) {
          result = true;
      }
      return result;
}



int Engine::diagnals(int ar[3][3], INPUT val) {
	int count = 0;
    count = diagnal1(ar, val) + diagnal2(ar, val);
	return count;
		
}

bool Engine::diagnal1Wins(int ar[][], INPUT val) {
	bool result = false;
    for (int j = 0, i = 2; j < 3, i > -1;j++ ,i--) {
            if (ar[i][j] == val) { 
                count++
            }
    }
    if (count == 2) {
        result = true;
    }
    return result;

}
bool Engine::diagnal2Wins(int ar[][], INPUT val) {
	bool result = false;
    for (int j = 0, i = 2; j < 3, i > -1;j++ ,i--) {
            if (ar[j][i] == val ) {
                count++
            }
    }
    if (count == 2) {
        result = true;
    }
    return result;
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
