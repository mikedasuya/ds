#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
#include "traverse.h"
#include "node.h"

//int copystack(stack<node*> *,stack<node*>*);

int main() {

	int ar[8] = {1,4,6,7,20,21,24,26};
	stack<node*>* s1_primary = new stack<node*>();
	stack<node*>* s1_secondary = new stack<node*>();
	node * root = NULL;
	for (int i =0; i < 8; i++) {
		int var= ar[i];
		copystack(s1_primary, s1_secondary);
		if (root == NULL) {
			root = new node(var);
			s1_primary->push(root);
			continue;
		}
		node *element = s1_secondary->pop();
		if (element->left != NULL &&
			element->right != NULL) {
		    element = s1_secondary->pop();
			
		}
		if (element != NULL) {
			if (element->left == NULL) {
				element->left = new node(var);
				s1_primary->push(element);
				copystack(s1_secondary, s1_primary);	
				s1_primary->push(element->left);
			} else if (element ->right == NULL) {
				element->right = new node(var);
				s1_primary->push(element);
				copystack(s1_secondary, s1_primary);
				s1_primary->push(element->right);
			}
		}
		
	}
	//traverse(root);
	convertTreeToArray(root);
}

	//int copystack(stack<node*> * f1, stack<node*>* f2) {
	//	while (f1->size() > 0) {
	//		f2->push(f1->pop());
	//	}
	//}
