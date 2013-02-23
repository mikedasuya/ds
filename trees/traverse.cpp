#include <stdio.h>
#include <stdlib.h>
#include "traverse.h"
#include "stack.h"
#include "node.h"
#include "queue.h"


void traverse(node * root) {
	stack<node*>* st = new stack<node*>();
	st->push(root);
        node * ptr = root;
	while (st->size() > 0) {
		while (ptr->left != NULL) {
			ptr = ptr->left;
			st->push(ptr);
		}
		node * elem = st->pop();
		printf("\n ----Vl--:%d: \n",elem->data);
		if (elem->right != NULL) {
			st->push(elem->right);
			ptr = elem->right;
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

