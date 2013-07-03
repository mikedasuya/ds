#ifndef __AVIAL_NODE_H
#define __AVIAL_NODE_H

struct AVNode {
	AVNode * lptr;
	AVNode * rptr;
	AVNode * parent;
	int data;
	int balance;
	AVNode(int dat) {
		lptr = NULL;
		rptr = NULL;
		parent = NULL;
		data = dat;
		balance = 99;
	}
	~AVNode() {
		//delete lptr;
		//delete rptr;
		
	}
};



#endif //avial_node
