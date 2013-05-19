#include "controller.h"
#include "Node.h"
#include <list>
#include <utility>
#include "engine.h"
#include <iterator>

using namespace std;

namespace ENGINE {

Controller::Controller() {
	eng = new Engine();
}

int Controller::nextMove( int ar[3][3]) {
    //just make list empty per move as it contains the nodes per move
    // ----next move
    listNode.clear();
    list<Node*>::iterator iter = listNode.begin();
    while (iter != listNode.end()) {
        Node * ptr = *iter;
//        delete ptr;
    }
    // check to see if any rows/columns/dignals are possible
	if (!eng->isGamePossible(ar)) {
		return -4;
	}
    if (eng->isComputerWinning(ar)){
        return -3;
    }
    if (eng->userWinCompulsion(ar)) {
        return 1;
    }
	for (int i = 0; i < 3 ; i++) {
		for (int j = 0;j < 3; j++) {
            evaluateState(ar,i , j);
		}
	}	
    if (!listNode.empty()) {
        Node * ptr = listNode.front();
        int row = ptr->row;
        int column = ptr->column;
        ar[row][column] = CROSS;
    }
	if (!eng->isGamePossible(ar)) {
		return -4;
	}
    return 5;

}

Controller::~Controller() {
    delete eng;
    eng = NULL;
}

void Controller::evaluateState(int ar[3][3], int row, int column) {
        
        if (ar[row][column] == 0) {
            ar[row][column] = CROSS;
            //comp will evaluate
            int result = eng->evaluateState(ar);
            //if comp wins go back
            if (result != -20) {
                addNode(ar, row, column, result);
            }
            ar[row][column] = 0;
        }
}

void Controller::addNode(int ar[3][3], int row, int column, int result) {
        if (listNode.empty()) {
            Node * ptr = new Node(ar, row, column, result);
            listNode.push_front(ptr);
        } else {
            Node * front = listNode.front();
            if (front->result < result) {
                Node * ptr = new Node(ar, row, column, result);
                listNode.push_front(ptr);
            }
        }
}

}

