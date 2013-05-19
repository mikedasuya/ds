#ifndef __PARAM_H
#define __PARAM_H
namespace ENGINE {
struct Param {
     Param(int row1, int colu):row(row1), column(colu) {
     }
     int row;
     int column;
};

}
#endif //PARAM
