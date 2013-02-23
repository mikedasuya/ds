#ifndef __node_h
#define __node_h


class node {
	public:
	node* left;
	node* right;
	node * father;
	int data;
	node(int input):left(NULL),right(NULL),father(NULL) {
		data = input; 
	}
	private:
	node(node&);
	node& operator=(const node&);
};

#endif
