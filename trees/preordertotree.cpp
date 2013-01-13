#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "stack.h"
#include "traverse.h"

int copystack(stack<node*> *f1,stack<node*>* f2) {
		while (f1->size() > 0) {
			f2->push(f1->pop());
		}
}

int main() {

int ar[11] = {14,4,3,9,7,5,15,18,16,17,30};
node* root = NULL;
stack<node*> *st_primary = new stack<node*>();
stack<node*> *st_secondry = new stack<node*>();
for (int i = 0; i < 11;i++) {
	if (root == NULL) {
		root = new node(ar[i]);
		st_primary->push(root);
		continue;
	}
	node * mainelem = st_primary->pop();
	while (mainelem->data > ar[i]) {
		st_secondry->push(mainelem);
		if (st_primary->size() > 0) {
			mainelem = st_primary->pop();
		} else if (st_primary->size() == 0) {
			mainelem = st_secondry->pop();
			break;
		}
	}
	if (mainelem->data > ar[i]) {
		if (mainelem->left == NULL) {
			node * n1 = new node(ar[i]);
			mainelem->left = n1;
			st_primary->push(n1);
			st_primary->push(mainelem);
			copystack(st_secondry,st_primary);		
		} else if (mainelem->left != NULL) {
			st_primary->push(mainelem);
			mainelem = st_secondry->pop();
			node * n1 = new node(ar[i]);
			if (mainelem->data > ar[i] ) {
				if (mainelem->left != NULL) {
					printf("\n ----logic break 11 left--\n");fflush(stdout);
				} else {
					mainelem->left = n1;
					st_primary->push(n1);
					st_primary->push(mainelem);
					copystack(st_secondry, st_primary);
					
				}		
			} else if (mainelem->data < ar[i]) {
				if (mainelem->right != NULL) {
					printf("\n ----logic break 11 rpte --\n");fflush(stdout);
				} else {
					mainelem->right = n1;
					st_primary->push(mainelem);
					st_primary->push(n1);
					copystack(st_secondry, st_primary);
				}

			}
		}


	} else 	if (mainelem->data < ar[i]) {
			if (mainelem->right == NULL) {
				node * n1 = new node(ar[i]);
				mainelem->right = n1;
				st_primary->push(mainelem);
				st_primary->push(n1);
				copystack(st_secondry,st_primary);
			} else if (mainelem->right != NULL) {
				st_primary->push(mainelem);
				mainelem = st_secondry->pop();
				node *n1 = new node(ar[i]);
				if (mainelem->data > ar[i]) {
					if (mainelem->left != NULL) {
						printf("\n ------loginc brealk lpointer \n");fflush(stdout);
					} else {
						mainelem->left = n1;
						st_primary->push(n1);
						st_primary->push(mainelem);
						copystack(st_secondry, st_primary);
					}
					
				} else if (mainelem->data < ar[i]) {
					if (mainelem->right != NULL) {
						printf("\n --------logic break rpointer \n");fflush(stdout);
					} else {
						mainelem->right = n1;
						st_primary->push(mainelem);
						st_primary->push(n1);
						copystack(st_secondry, st_primary);
					} 
				}
			}
	}
} //for
	traverse(root);

}


