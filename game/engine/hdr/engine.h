#ifndef __ENGINE_H
#define __ENGINE_H

#include "Common.h"

namespace ENGINE {

class Engine {
	private:
	int column(int ar[3][3], INPUT val);
	int diagnals(int ar[3][3], INPUT val);
    int rows(int ar[3][3], INPUT val);
	bool column0Contains(int ar[3][3], INPUT val);
	bool column1Contains(int ar[3][3], INPUT val);
	bool column2Contains(int ar[3][3], INPUT val);
	bool row0Contains(int ar[3][3], INPUT val);
	bool row1Contains(int ar[3][3], INPUT val);
	bool row2Contains(int ar[3][3], INPUT val);
    bool doesUserWinsInNextMove(int ar[3][3]);
	bool internalUserCompulsion(int ar[3][3],struct Param*, INPUT val);	
	struct Param * calculateColumnWins(int ar[3][3],INPUT val, int row);
	struct Param * calculateRowWins(int ar[3][3],INPUT val, int column);
    struct Param *column0Wins(int ar[3][3], INPUT val);
    struct Param *column1Wins(int ar[3][3], INPUT val);
    struct Param *column2Wins(int ar[3][3], INPUT val);
    struct Param * row0Wins(int ar[3][3], INPUT val);
    struct Param * row1Wins(int ar[3][3], INPUT val);
    struct Param * row2Wins(int ar[3][3], INPUT val);

    struct Param* diagnal1Wins(int ar[3][3], INPUT val);
    struct Param* diagnal2Wins(int ar[3][3], INPUT val);
    bool diagnal1(int ar[3][3], INPUT val);
    bool diagnal2(int ar[3][3], INPUT val);
    void printGame(int ar[3][3]);
    public:
	
	Engine();
	int evaluateState(int ar[3][3]);
    bool isGamePossible(int ar[3][3]);
    bool isComputerWinning(int ar[3][3]);
    bool userWinCompulsion(int ar[3][3]);
	
};

}

#endif
