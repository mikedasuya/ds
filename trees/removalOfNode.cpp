#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "traverse.h"

node* makeTree(int ar[]);
node * findElement(node *root, int data);
node *getnode(node * ptr, int data);
void deleteElem(node* root, int data); 
node * findSmallest(node * ptr);
node * findElement(node *root, int data);

int main() {
	int ar[] = {6,2,0,9,1,8,4,3,7,11};
	node * root = makeTree(ar);
	printf("\n before deleting \n");
//	traverse(root);
//	deleteElem(root, 1);
	traverse(root);
	deleteElem(root, 9);
	traverse(root);
}

node* makeTree(int ar[]) {
	node * root = NULL;
	for (int i = 0; i < 10; i++) {
		int data = ar[i];
		if (root == NULL) {
			root = new node(ar[i]);
			continue;
		}
		node* baseElem = getnode(root, ar[i]);
		if (baseElem->data > data) {
			node * elem = new node(ar[i]);
			baseElem->left = elem;
			elem->father = baseElem;			
		} else if (baseElem->data < data) {
			node *elem =new node(ar[i]);
			baseElem->right = elem;
			elem->father=baseElem;
		}
	}
	return root;
}

node *getnode(node * ptr, int data) {
	while (1) {
		if (data < ptr->data) {
			if (ptr->left != NULL) {
				ptr =ptr->left;
			} else if (ptr->left == NULL) {
				return ptr;
			}
		
		}
		if (data > ptr->data) {
			if (ptr->right != NULL) {
				ptr = ptr->right;
			} else if (ptr->right== NULL) {
				return ptr;
			}
		}
	}
}


void deleteElem(node* root, int data) {
	node * ptr = root;
	node * elem = findElement(ptr, data);
	if (elem == NULL) {
		printf("\n Cannot delete as no element found \n");fflush(stdout);
	}
	if (elem->right == NULL && elem->left == NULL) {
		printf("\n -------delete Elem -----leaf node \n");
		node * father = elem->father;
		if (father == NULL) {
			root = NULL;
			delete elem;	
		}
		if (father->data > elem->data) {
			father->left=NULL;
			delete elem;
		} else {
			father->right = NULL;
			delete elem;
		}
		return;
		
	} else 	if (elem->right != NULL && elem->left == NULL) {
		node * father = elem->father;
		if (father == NULL) {
			root = elem->right;
			elem->right->father = NULL;	
		}
		if (father->data > elem->data) {
			father->left = elem->right;
			elem->right->father = father;
		} else if (father->data < elem->data) {
			father->right = elem->right;
			elem->right->father = father;
		}
		return;
		
		
	} else if (elem->right == NULL && elem->left != NULL) {
		node * father = elem->father;
		if (father == NULL) {
			root = elem->left;
			elem->left->father = NULL;
		}
		if (father->data > elem->data) {
			father->left = elem->left;
			elem->left->father= father;
		} else if (father->data < elem->data) {
			father->right = elem->left;
			elem->left->father= father;
		}
		return;
	} else if (elem->right != NULL && elem->left != NULL) {
		node * selem = findSmallest(elem->right);
		elem->data = selem->data; 	
		return;
		
	}

}

node * findSmallest(node * ptr) {
	while (ptr->left !=NULL) {
		ptr =ptr->left;
	}
	node * father= ptr->father;
	if (father->data < ptr->data) {
		if (ptr->right != NULL) {
			father->right = ptr->right;
			ptr->right->father = father;
		}
		father->right = NULL;
	} else if (father->data > ptr->data) {
		if (ptr->right != NULL) {
			father->left = ptr->right;
			ptr->right->father = father;
		}
	}
	return ptr;
		
}

node * findElement(node *root, int data) {
	
	while (1) {
		if (data == root->data) {
			return root;
		}
		if (data < root->data) {
			if (root->left != NULL) {
				root = root->left;
			} else {
				return NULL;
			}
		}
		if (data > root->data) {
			if (root->right != NULL) {
				root = root->right;
			} else {
				return NULL;
			}
		}
	}
	


}

