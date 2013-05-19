#ifndef __CONROLLER_H
#define __CONTROLLER_H

#include <list>
#include "Node.h"

using namespace std;

namespace ENGINE {

class Engine;

class Controller {
    public:
    Controller();
    int nextMove(int ar[3][3]);
    void evaluateState(int ar[3][3],
                        int row,
                        int column);
    void addNode(int ar[3][3],int row,
                    int column, int result);
    ~Controller();

    private:
    Engine *eng;
    list<Node*> listNode;

};

}



#endif //controller
