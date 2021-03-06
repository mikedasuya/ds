#include<stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"
#include "node.h"

node * getNode(node *, int input);
void convertTreeToArray(node *);
int main() {

int ar[8] = {34,2,4,7,68,45,23,6};
	int i = 0;
	node * root = NULL;
	while (i < 8) {
		int input= ar[i];
		if (root == NULL) {
			root = new node(ar[i]);	
		} else {
			node * ptr = getNode(root, ar[i]);
			if (ptr->data < ar[i]) {
				ptr->right = new node(ar[i]);
			} else if (ptr->data > ar[i]) {
				ptr->left = new node(ar[i]);
			}
		}
		i++;
	}
	convertTreeToArray(root);		
}

node * getNode(node * root, int data) {
	node * temp = root;
	while (1) {
		if (temp->data > data) {
			if (temp->left !=NULL) {
				temp = temp->left;
			} else {
				return temp;
			}		
		} else if (temp->data < data) {
			if (temp->right !=NULL) {
				temp = temp->right;
			} else {
				return temp;
			}
		}
	}
}


void convertTreeToArray(node * root) {
	Queue<int>* baseQueue = new Queue<int>();
	Queue<node*>* level0 = new Queue<node*>();
	level0->setElement(root);
	stack<Queue<node*>*> * s1 = new stack<Queue<node*>*>();
	s1->push(level0);
	Queue<node*> * perlevel = NULL;
	while(s1->size() > 0) {
	
		Queue<node*> *stlevel = s1->pop();
		perlevel = new Queue<node*>();
		while (stlevel->size() > 0) {
			node * ptr = stlevel->getElement();
			baseQueue->setElement(ptr->data);
			if (ptr->left != NULL) {
				perlevel->setElement(ptr->left);
			}
			if (ptr->right != NULL) {
				perlevel->setElement(ptr->right);
			}
		}
		if (perlevel->size() > 0) {	
			s1->push(perlevel);
		}
	}
	while (baseQueue->size() > 0) {
		printf("\n ------array :%d:---\n",baseQueue->getElement());fflush(stdout);
	}
}

