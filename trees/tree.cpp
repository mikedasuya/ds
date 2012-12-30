#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "node.h"

node * getNode(node *, int input);
void traverse(node *);

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
	traverse(root);

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

void traverse(node * root) {
	stack* st = new stack();
	st->push(root);
	while (st->size() > 0) {
		node * nod = st->pop();
		printf("\n ----whie:%d: --\n", nod->data);fflush(stdout);
		if (nod->right != NULL) {
			st->push(nod->right);
		}
		if (nod->left != NULL) {
			nod = nod->left;
			st->push(nod);
		}
	}

}
