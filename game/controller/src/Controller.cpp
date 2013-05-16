#include "Controller.h"

namespace ENGINE {
Controller::Controller() {
	eng = new Engine();
}

int Controller::nextMove( int ar[3][3]) {
    Iterator<Node*>::iterator iter = list->begin();
    while (iter != list->end()) {
        Node * ptr = *iter;
        delete ptr;
    }
	if (!eng->IsGamePossible()) {
		return 0;
	}
    if (eng->isComputerWinning(ar)){
        return 0;
    }
    if (eng->userWinCompulsion(ar)) {
        return 1;
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
    return 5;

}

void Controller::evaluateState(int ar[3][3], int row, int column) {
        if (ar[i][j] == 0) {
            ar[i][j] = CROSS;
            //comp will evaluate
            int result = eng->evaluateState(ar);
            //if comp wins go back
            addNode(ar,i,j, result);
            ar[i][j] = 0;
        }
}

void Controller::addNode(int ar[3][3], int row, int column, int result) {
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

