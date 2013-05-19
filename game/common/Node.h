#ifndef __NODE_H
#define __NODE_H

class Node {
    public:
    Node(int ar1[3][3], int row1, int column1, int result1): 
        row(row1),
        column(column1),
        result(result1) {
            for (int i = 0; i < 3;i++) {
                for (int j = 0; j < 3; j++) {
                    ar[i][j] == ar1[i][j];
                }
            }
        

    }
    ~Node() {
    }
    int row;
    int column;
    int result;
    int ar[3][3];

};


#endif //node
