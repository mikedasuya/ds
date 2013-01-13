#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define internal 1
#define data 0

enum type {data = 0,internl =1};
class node {
	public:
	node(type):lptr(NULL),
			rptr(NULL),
			father(NULL),
			data(0),
			countleftelem(0) {
		
	}
	node *lptr;
	node * rptr;	
	node * father;
	int dataa;
	int countleftelem;
	private:
	int type;
	
};

int ar[9] = {1,2,3,4,5,6,7,8,9};
int main() {
	node * root = NULL;
	stack<node*>s_prim = new stack<node*>();
	stack<node*>s_sec = new stack<node*>();
	for (int i = 0; i < 9; i++) {
		if (root == NULL) {
			root = new node(internal);
			root->lptr = new node(data);
			root->lptr->dataa = ar[i];
			root->father = NULL;
			s_prim->push(root->lptr);
			s_prim->push(root);
			continue;

		}
		node* elem = s_prim->pop();
		copystack(s_prim,s_sec);
		if (elem->lptr == NULL) {
			node * n1 = new node(data);
			elem->lptr = n1;
			n1->father = elem;
			copystack(s_sec, s_prim);
			s_prim->push(elem);
			incrleftnodecount(n1);
			
			
		} else if (elem->rptr == NULL) {
			node * n1= new node(data);
			elem->rptr = n1;
			copystack(s_sec,s_prim);
			s_prim->push(elem);
		} else if (elem->rptr != NULL
				&& elem->lptr != NULL) {
			if ( (elem->lptr->type == internal) &&
			     (elem->rptr->type == internal)) {
			}
			if ((elem->lptr->type == internal) &&
			    (elem->rptr->type == data)) {
			}
			if ((elem->rptr
		}
		
		
		
	}
}

void incrleftnodecount(node * n1) {
	if (node->type == data) &&
	   (node->father == root) {
	} else if (node->type == data) &&
	  (node->father != root) {
		node = node->father;
		while(node->father != NULL) {
			node->countleftelem = 1;
			
			
		}
	}
	
}

