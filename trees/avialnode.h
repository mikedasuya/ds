#ifndef __AVIAL_NODE_H1
#define __AVIAL_NODE_H1

#include <cstddef>

struct AVLNode {
	AVLNode * lptr;
	AVLNode * rptr;
	AVLNode * parent;
	int data;
	int balance;
	AVLNode(int dat) {
		lptr = NULL;
		rptr = NULL;
		parent = NULL;
		data = dat;
		balance = 99;
	}
	~AVLNode() {
		//delete lptr;
		//delete rptr;
		
	}
};



#endif //avial_node
