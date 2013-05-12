#include "Controller.h"

namespace ENGINE {
Controller::Controller() {
	eng = new Engine();
}

int Controller::nextMove( int ar[3][3]) {
	if (!eng->gameIsPossible()) {
		return 0;
	}
    if (userOrCompWins()) {

    }
    struct rowColumnParam * val = eng->userWinCompulsion(ar);
    if (val != NULL) {
         ar[val->row][val->column] = ZERO;
         return 1;
    }
    struct rowColumnParam * val = eng->CompWin(ar);
    if (val != NULL) {
        ar[val->row][val->column] = CROSS;
        return 2;
    }
	for (int i = 0; i < 3 ; i++) {
		for (int j = 0;j < 3; j++) {
            evaluateState(ar,i , j);
		}
	}	
    if (!list->empty()) {
        Node * ptr = list->pop_front();
        ar[ptr->row][ptr->column] = ZERO;
    }

}

void Controller::evaluateState(int ar[3][3], int row, int column) {
        if (ar[i][j] == 0) {
            ar[i][j] = ZERO;
            //comp will evaluate
            int result = eng->evaluate(ar, ZERO);
            //if comp wins go back
            addNode(ar,i,j, result);
            ar[i][j] = 0;
        }
}

void Controller::addNode(int ar[3][3], int row, int column, int result) {
    if (eng->userWinsInNextMoves(ar)) {
    } else {     
        if (list->empty()) {
            Node * ptr = new Node(ar, row, column, result);
            list->add(ptr);
        } else {
            Node * front = list->pop_front();
            if (front->index < result) {
                Node * ptr = new Node(ar, row, column, result);
                list->push_front(ptr);
            }
        }
    }
}

}

