#ifndef __node_h
#define __node_h


class node {
	public:
	node* left;
	node* right;
	int data;
	node(int input):left(NULL),right(NULL) {
		data = input; 
	}
	private:
	node(node&);
	node& operator=(const node&);
};

#endif
