#include "stack.h"

int main() {
	int ar [7] = {9, 4, 3, 2, 1, 13, 12, 11, 14,17 };
	AVNode * root = NULL;
	for (int i = 0; i < 7; i++) {
		int input = ar[i];
		if (root == NULL) {
			root = new AVNode(data);
			continue;
		}
		AVNode * ptr = addNode(root, input);
		AVNode * parentNode = ptr->parent;
		while (parentNode != NULL) {
			caluclateandBalanceInternal(parentNode);
			parentNode = parentNode->parent; 
		}
	}
}

bool calculateandBalanceInternal(Node * ptr) {
	int leftlevel = 0;
	if (ptr->lptr != NULL) {
		leftlevel = calculate(ptr->left);
		leftlevel = leftlevel + 1;
	}
	int rightlevel = 0;
	if (ptr->rptr != NULL) {
		 rightlevel = calculate(ptr->rptr);
		 rightlevel = rightlevel + 1;
	}
	ptr->balance =  leftlevel - rightlevel;
	if (ptr->balance == -1 ||
		ptr->balance == 1 ||
		ptr->balance == 0) {
	} else if (ptr->balance == 2) {
		balanceTree(ptr);
	} else if (ptr->balance == -2) {

	}
}

bool leftleftRotation(AVLNode * ptr) {
	if (ptr->left == NULL) {
		printf("\n ----left left rotation error there is error ---\n");fflush(stdout);
		return false;
	} 
	AVLNode * parent = ptr->parent;
	if (parent == NULL) {
			root = ptr->rptr;
			AVLNode * rptrRoot = root->lptr;
			root->lptr = ptr;
			ptr->rptr = rptrRoot;
			if (ptr->rptr != NULL) {
				ptr->rptr->parent = ptr;
			}
			ptr->parent = root;
			root->parent = NULL;

	} else {

		if (parent->lptr != NULL && parent->lptr->data == ptr->data) {

			parent->lptr = ptr->rptr;
			ptr->parent = parent->lptr;

			AVLNode * rptrRoot = ptr->rptr->lptr;
			ptr->rptr = rptrRoot;
			if (ptr->rptr != NULL) {
				ptr->rptr->parent = ptr;
			}
			parent->lptr->lptr = ptr;

			parent->lptr->parent = parent;

		} else if (parent->rptr != NULL && parent->rptr->data == ptr->data) {
			
			
			parent->rptr = ptr->rptr;
			ptr->parent = parent->rptr;

			AVLNode * rptrRoot = ptr->rptr->lptr;
			
			ptr->rptr = rptrRoot;
			ptr->rptr->parent = ptr;
			parent->rptr->lptr = ptr;
			parent->rptr->parent = parent;

		}

	}
}

bool rightrightRotation(AVLNode * ptr) {
	AVLNode * parent = ptr->parent;
	if (parent == NULL) {
		if (ptr->lptr == NULL) {
			printf("\n ----error ---right rotation not possible\n");fflush(stdout);
			return false;
		}
		root = ptr->lptr;
		root->parent = NULL;
		AVLNode * tempNode = root->rptr;
		root->rptr = ptr;
		ptr->parent = root;
		ptr->lptr = tempNode;
		if (ptr->lptr != NULL) {
			ptr->lptr->parent = ptr;
		}

	} else if (parent != NULL) {
		if (parent->lptr != NULL && parent->lptr->data == ptr->data) {

			AVLNode * root = ptr->lptr;
			root->parent = parent;
			AVLNode * tempNode = root->rptr;
			root->rptr = ptr;
			ptr->parent = root;
			ptr->lptr = tempNode;
			if (ptr->lptr != NULL) {
				ptr->lptr->parent = ptr;
			}
			parent->lptr = root;
		} else if (parent->rptr != NULL && parent->rptr->data == ptr->data) {

			AVLNode * root = ptr->lptr;
			root->parent = parent;
			AVLNode * tempNode = root->rptr;
			root->rptr = ptr;
			ptr->parent = root;
			ptr->lptr = tempNode;
			if (ptr->lptr != NULL) {
				ptr->lptr->parent = ptr;
			}
			parent->rptr = root;
		}

	}
}

bool leftRightRotation(AVLNode * ptr) {
	if (ptr->parent == NULL) {
		/////first left rotation
		AVLNode* temp = ptr->lptr;
		AVLNode * leftOfthird = temp->rptr->lptr;
		ptr->lptr = temp->rptr;
		ptr->lptr->lptr = temp;
		temp->rptr = leftOfthird;

		if (temp->rptr != NULL) {
			temp->rptr->parent = temp;
		}
		temp->parent = ptr->lptr;
		ptr->lptr->parent = ptr;
		////right rotation
		AVLNode * localroot = ptr->lptr;
		AVLNode * temp1 = localroot->rptr;

		localroot->rptr = ptr;

		ptr->lptr = temp1;

		localroot->parent = NULL;
		
		ptr->parent = localroot;
		if (ptr->lptr != NULL) {
			ptr->lptr->parent = ptr;
		}


	} else if (ptr->parent != NULL &&
	           parent->rptr != NULL &&
			   parent->rptr->data == ptr->data) {
		AVLNode* temp = ptr->lptr;
		AVLNode * leftOfthird = temp->rptr->lptr;
		ptr->lptr = temp->rptr;
		ptr->lptr->lptr = temp;
		temp->rptr = leftOfthird;

		if (temp->rptr != NULL) {
			temp->rptr->parent = temp;
		}
		temp->parent = ptr->lptr;
		ptr->lptr->parent = ptr;
		////right rotation
		AVLNode * localroot = ptr->lptr;
		AVLNode * temp1 = localroot->rptr;

		localroot->rptr = ptr;

		ptr->lptr = temp1;
		ptr->parent = localroot;
		if (ptr->lptr != NULL) {
			ptr->lptr->parent = ptr;
		}

		parent->rptr = localroot;
		localroot->parent = parent;
	} else if (ptr->parent != NULL &&
	           parent->lptr != NULL &&
			   parent->lptr->data == ptr->data) {
		AVLNode* temp = ptr->lptr;
		AVLNode * leftOfthird = temp->rptr->lptr;
		ptr->lptr = temp->rptr;
		ptr->lptr->lptr = temp;
		temp->rptr = leftOfthird;

		if (temp->rptr != NULL) {
			temp->rptr->parent = temp;
		}
		temp->parent = ptr->lptr;
		ptr->lptr->parent = ptr;
		////right rotation
		AVLNode * localroot = ptr->lptr;
		AVLNode * temp1 = localroot->rptr;

		localroot->rptr = ptr;

		ptr->lptr = temp1;
		ptr->parent = localroot;
		if (ptr->lptr != NULL) {
			ptr->lptr->parent = ptr;
		}

		parent->rptr = localroot;
		localroot->parent = parent;
	}
}

AVLNode * rightleftRotationInternal(AVLNode * ptr) {
	
	//right shift
	AVLNode * thirdleftptr = ptr->lptr->rptr->lptr;
	AVLNode * secondptr = ptr->lptr;
	ptr->lptr = ptr->lptr->rptr;
	ptr->lptr->lptr = secondptr;

	
	ptr->lptr->lptr->rptr = thirdleftptr;
	if (ptr->lptr->lptr->rptr != NULL) {
		ptr->lptr->lptr->rptr->parent = lptr->lptr->lptr;
	}

	ptr->lptr->lptr->parent = ptr->lptr;
	ptr->lptr->parent = ptr;

	//left shift
	AVLNode * temp1 = ptr->lptr;

	AVLNode * temprptr = temp1->rptr;

	temp1->rptr = ptr;

	ptr->rptr = temprptr;
	if (ptr->rptr != NULL) {
		ptr->rptr->parent = ptr;
	}
	ptr->parent = temp1;
	return temp1;

}


bool rightleftRotation(AVLNode * ptr) {
	AVLNode * parent = ptr->parent;
	if (ptr->parent == NULL) {

		root = rightleftRotationInernal(ptr);
		root->parent = NULL;

	} else if (ptr->parent != NULL && ptr->parent->lptr != NULL && 
	            ptr->parent->lptr->data == ptr->data) {
		AVLNode * ptr1 = rightleftRotationInternal(ptr);
		parent->lptr = ptr1;
		ptr1->parent = parent;

	} else if (ptr->parent != NULL && ptr->parent->rptr != NULL &&
				ptr->parent->rptr->data == ptr->data) {
		AVLNode * ptr1 = rightleftRotationInternal(ptr);
		parent->rptr = ptr1;
		ptr1->parent = parent;

	}
}

bool balance(AVLNode * ptr) {
	if (ptr->balance == 2) {
		int balance = calulateLevel(ptr->left);
		if (balance == 1) {
			rightrightRotation(ptr);			
		} else if (balance == -1) {
			rightleftRotation(ptr);
		}
	}

	} else if (ptr->balance == -2) {

		int balance = calulateLevel(ptr->left);
		if (balance == 1) {
			leftRightRotation(ptr);
		} else if (balance == -1) {
			leftleftRotation(ptr);
		}
	} else {
		printf("\n ------balancing ---\n",
	}
}



bool addLevel(AVNode * ptr, stack<AVNode*> * childNodeStack) {
	if (ptr->lptr == NULL && ptr->rptr == NULL) {
	} else if (ptr->lptr != NULL && ptr->rptr == NULL) {
		childNodeStack->push(ptr->lptr);
	} else if (ptr->lptr == NULL && ptr->rptr != NULL) {
		childNodeStack->push(ptr->rptr);
	} else if (ptr->lptr != NULL && ptr->rptr != NULL) {
		childNodeStack->push(ptr->lptr);
		childNodeStack->push(ptr->rptr);
	}
}
int calculateLevel(AVNode * ptr) {
	int level = 0;
	stack<stack<AVNode*>* > stack_of_stack = new stack<stack<AVNode*>*>();
	stack<AVNode*> * childNode = new stack<AVNode*>();
	addLevel(ptr, childNode);
	if (childNode->size() > 0) {
		level++;
		stack_of_stack->push(childNode);
	}
	while (stack_of_stack->size() > 0) {
		stack<AVNode*> st = stack_of_stack->pop();
		stack<AVNode*> * childNode = new stack<AVNode*>();
		while (st->size() > 0) {
			AVNode * nodePtr = st->pop();
			if (nodePtr->lptr != NULL) {
				addLevel(nodePtr->lptr, childNode);
			}
			if (nodePtr->rptr != NULL) {
				addLevel(nodePtr->rptr, childNode);
			}

		}
		if (childNode->size() > 0) {
			level++;
			stack_of_stack->push(childNode);

		}

	}
	return level;
}

AVNode * addNode(AVNode * root, int data) {
	AVNode * ptr = root;
	if (data < ptr->data) {
		if (ptr->lptr == NULL) {
			AVNode * ptr1 = new AVNode(data);
			ptr->lptr = ptr1;
			ptr1->parent = ptr;
			return ptr1;
		} else if (ptr->lptr != NULL) {
			addNode(ptr->lptr);
		}
	} else if (data > ptr->data) {
		if (ptr->rptr == NULL) {
			AVNode * ptr2 = new AVNode(data);
			ptr->rptr = ptr2;
			ptr2->parent = ptr;
			return ptr2;

		} else if (ptr->rptr != NULL) {
			addNode(ptr->rptr);
		}
	}
}
