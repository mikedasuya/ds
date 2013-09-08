#include <iostream>
#include <stdlib.h>
#include <vector>
#include <utility>
#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

struct Node {
	int data;
	Node * lptr;
	Node * rptr;
	Node * parent;
	Node(int d) {
		lptr = NULL;
		rptr = NULL;
		parent = NULL;
		data = d;
	}
};

void swapData(Node *);
int main() {

	int ar[10] = { 7, 1, 9, 4 , 3 ,2 ,11,13,16,23 };
	Node * root = NULL;
	stack<Node*>* st_parent = new stack<Node*>();
	stack<Node*>* st_child = new stack<Node*>();
	for (int i = 0; i < 10; i++) {
		if (root == NULL) {
			root = new Node(ar[i]);
			root->parent = NULL;
			st_parent->push(root);
			continue;
		}
		Node * elemt = st_parent->top();
		st_parent->pop();
		if (elemt->rptr != NULL && elemt->lptr != NULL) {
			if (st_parent->size() > 0) {
				elemt = st_parent->top();
				st_parent->pop();
			} else {
				st_parent = st_child;
				st_child = new stack<Node*>();
				elemt = st_parent->top();
				st_parent->pop();
			}
		}
		if (elemt->lptr == NULL) {
			Node * ptr = new Node(ar[i]);
			elemt->lptr = ptr;
			ptr->parent = elemt;
			st_parent->push(elemt);
			st_child->push(ptr);
			swapData(ptr);

		} else if (elemt->rptr == NULL) {
			Node * ptr = new Node(ar[i]);
			elemt->rptr = ptr;
			ptr->parent = elemt;
			st_parent->push(elemt);
			st_child->push(ptr);
			swapData(ptr);

		}
	}
	cout <<endl<< "Root is"<< root->data <<endl;
}

void swapData(Node * ptr) {

	Node * parent = ptr->parent;
	while (parent != NULL) {
		if (ptr->data > parent->data) {
			int temp = parent->data;
			parent->data = ptr->data;
			ptr->data = temp;
		}
		ptr = parent;
		parent = ptr->parent;
	}

}
