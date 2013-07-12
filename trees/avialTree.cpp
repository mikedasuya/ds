#include "stack.h"
#include "avialnode.h"
#include "traverse.h"
#include "stdio.h"
#include "stdlib.h"


AVLNode * addNode(AVLNode * root, int data);
bool caluclateandBalanceInternal(AVLNode * ptr);
int calculateLevel(AVLNode * ptr);
bool addLevel(AVLNode * ptr, stack<AVLNode*> * childNodeStack);
AVLNode * rightleftRotationInternal(AVLNode * ptr);
bool rightleftRotation(AVLNode * ptr1);
AVLNode * rightrightRotationInternal(AVLNode * ptr);
bool rightrightRotation(AVLNode * ptr);
AVLNode * leftleftRotationInternal1(AVLNode * ptr);
bool leftleftRotation1(AVLNode * ptr);
AVLNode * leftrightRotationInternal1(AVLNode * ptr);
bool leftrightRotation(AVLNode * ptr);

bool balanceTree(AVLNode * ptr);
AVLNode * g_root = NULL;
int main() {
	int ar [10] = {9, 4, 3, 2, 1, 13, 12, 11, 14,17 };
	AVLNode * root = NULL;
	for (int i = 0; i < 10; i++) {
		int data = ar[i];
		if (root == NULL) {
			root = new AVLNode(data);
			g_root = root;
			continue;
		}
		AVLNode * ptr = addNode(g_root, data);
		ptr->balance = 0;
		AVLNode * parentNode = ptr->parent;
		while (parentNode != NULL) {
			caluclateandBalanceInternal(parentNode);
			parentNode = parentNode->parent; 
		}
	}
	traverse(g_root);
}

bool caluclateandBalanceInternal(AVLNode * ptr) {

	AVLNode * ptr1 = ptr;
	int leftlevel = 0;
	if (ptr->lptr != NULL) {
		leftlevel = calculateLevel(ptr->lptr);
		leftlevel = leftlevel + 1;
	}
	int rightlevel = 0;
	if (ptr->rptr != NULL) {
		 rightlevel = calculateLevel(ptr->rptr);
		 rightlevel = rightlevel + 1;
	}

	ptr->balance =  leftlevel - rightlevel;
	if (ptr->balance == -1 ||
		ptr->balance == 1 ||
		ptr->balance == 0) {
	} else if (ptr->balance == 2) {
		balanceTree(ptr);
	} else if (ptr->balance == -2) {
		balanceTree(ptr);
	}
	
	leftlevel = 0;

	if (ptr1->lptr != NULL) {
		leftlevel = calculateLevel(ptr1->lptr);
		leftlevel = leftlevel + 1;
	}
	rightlevel = 0;
	if (ptr1->rptr != NULL) {
		 rightlevel = calculateLevel(ptr1->rptr);
		 rightlevel = rightlevel + 1;
	}
	ptr1->balance = leftlevel - rightlevel;

}

//-2 +1
AVLNode * rightleftRotationInternal(AVLNode * ptr) {

			//right shift
			AVLNode * movePtr = ptr->rptr->lptr->rptr;	
			
			AVLNode * ptrmiddle = ptr->rptr;
			
			ptr->rptr = ptr->rptr->lptr;

			ptr->rptr->rptr = ptrmiddle;

			ptrmiddle->lptr = movePtr;

			if (ptr->rptr->rptr->lptr != NULL) {
				ptr->rptr->rptr->lptr->parent = ptr->rptr->rptr;
			}
			if (ptr->rptr->rptr != NULL) {
				ptr->rptr->rptr->parent = ptr->rptr;
			}
			if (ptr->rptr != NULL) {
				ptr->rptr->parent = ptr;
			}
			
			//left shift
			AVLNode * leftptr = ptr->rptr->lptr;
			AVLNode * mainPtr = ptr->rptr;
			mainPtr->lptr = ptr;
			ptr->rptr = leftptr;

			if (ptr->rptr != NULL) {
				ptr->rptr->parent = ptr;
			}
			ptr->parent = mainPtr;

			return mainPtr;
}

//-2 + 1
bool rightleftRotation(AVLNode * ptr1) {

	AVLNode * parent = ptr1->parent;
	if (parent == NULL) {
		AVLNode * ptr = rightleftRotationInternal(ptr1);
		g_root = ptr;
		g_root->parent = NULL;
	} else if ( parent->lptr != NULL && (parent->lptr->data == ptr1->data) ) {

		AVLNode * ptr = rightleftRotationInternal(ptr1);
		parent->lptr = ptr;
		parent->lptr->parent = parent;

	} else if (parent->rptr != NULL && parent->rptr->data == ptr1->data) {
		AVLNode * ptr = rightleftRotationInternal(ptr1);
		parent->rptr = ptr;
		parent->rptr->parent = parent;
	}
}

AVLNode * rightrightRotationInternal(AVLNode * ptr) {
			
			AVLNode * parentPtr = ptr->parent;
			//left shift
			AVLNode * leftptr = ptr->rptr->lptr;
			AVLNode * mainPtr = ptr->rptr;
			mainPtr->lptr = ptr;
			ptr->rptr = leftptr;

			if (ptr->rptr != NULL) {
				ptr->rptr->parent = ptr;
			}
			ptr->parent = mainPtr;
			return mainPtr;
}
//-2 -1
bool rightrightRotation (AVLNode * ptr) {
			
			AVLNode * parent = ptr->parent;
			if (parent == NULL) {
				AVLNode * ptr = rightrightRotationInternal(ptr);
				g_root = ptr;
				g_root->parent = NULL;
			} else if (parent->rptr != NULL && parent->rptr->data == ptr->data) {
				
				AVLNode * ptr = rightrightRotationInternal(ptr);
				parent->rptr = ptr;
				parent->rptr->parent = parent;

			} else if (parent->lptr != NULL && parent->lptr->data == ptr->data) {

				AVLNode * ptr = rightrightRotationInternal(ptr);
				parent->lptr = ptr;
				parent->lptr->parent = parent;

			}
	return true;
}

AVLNode * leftleftRotationInternal1(AVLNode * ptr) {
		
		AVLNode * rootptr = ptr->lptr;
		AVLNode * tempNode = rootptr->rptr;
		rootptr->rptr = ptr;
		ptr->lptr = tempNode;

		if (ptr->lptr != NULL) {
			ptr->lptr->parent = ptr;
		}

		if (rootptr->rptr != NULL) {
			rootptr->rptr->parent = rootptr; 
		}
		return rootptr;

}

bool leftleftRotation1(AVLNode * ptr) {
	AVLNode * parent = ptr->parent;
	if (parent == NULL) {
		if (ptr->lptr == NULL) {
			printf("\n ----error ---right rotation not possible\n");fflush(stdout);
			return false;
		}
		g_root = leftleftRotationInternal1(ptr);
		g_root->parent = NULL;

	} else if (parent != NULL) {
		if (parent->lptr != NULL && parent->lptr->data == ptr->data) {
			AVLNode * ptr1 = leftleftRotationInternal1(ptr);
			parent->lptr = ptr1;
			ptr1->parent = parent;
		} else if (parent->rptr != NULL && parent->rptr->data == ptr->data) {

			AVLNode * ptr1 = leftleftRotationInternal1(ptr);
			parent->rptr = ptr1;
			ptr1->parent = parent;
		}

	}
	return true;
}

// 2 -1
AVLNode * leftrightRotationInternal1(AVLNode * ptr) {
	
	//left shift 2 -1
	AVLNode * thirdleftptr = ptr->lptr->rptr->lptr;
	AVLNode * secondptr = ptr->lptr;
	ptr->lptr = ptr->lptr->rptr;
	ptr->lptr->lptr = secondptr;

	
	ptr->lptr->lptr->rptr = thirdleftptr;
	if (ptr->lptr->lptr->rptr != NULL) {
		secondptr->rptr->parent = secondptr;
	}
	if (ptr->lptr->lptr->lptr != NULL) {
		ptr->lptr->lptr->lptr->parent = ptr->lptr->lptr;
	}

	ptr->lptr->lptr->parent = ptr->lptr;
	if (ptr->lptr->rptr != NULL) {
		ptr->lptr->rptr->parent = ptr->lptr;
	}

	ptr->lptr->parent = ptr;

	//right shift
	AVLNode * temp1 = ptr->lptr;
	AVLNode * temprptr = temp1->rptr;
	temp1->rptr = ptr;
	ptr->lptr = temprptr;

	if (ptr->lptr != NULL) {
		ptr->lptr->parent = ptr;
	}
	ptr->parent = temp1;

	if (temp1->rptr != NULL) {
		temp1->rptr->parent = temp1;
	}

	return temp1;

}


bool leftrightRotation1(AVLNode * ptr) {
	AVLNode * parent = ptr->parent;
	if (ptr->parent == NULL) {

		g_root = leftrightRotationInternal1(ptr);
		g_root->parent = NULL;

	} else if (ptr->parent != NULL && ptr->parent->lptr != NULL && 
	            ptr->parent->lptr->data == ptr->data) {
		AVLNode * ptr1 = leftrightRotationInternal1(ptr);
		parent->lptr = ptr1;
		ptr1->parent = parent;

	} else if (ptr->parent != NULL && ptr->parent->rptr != NULL &&
				ptr->parent->rptr->data == ptr->data) {
		AVLNode * ptr1 = leftrightRotationInternal1(ptr);
		parent->rptr = ptr1;
		ptr1->parent = parent;

	}
}

bool balanceTree(AVLNode * ptr) {
	if (ptr->balance == 2) {
		int balance = calculateLevel(ptr->lptr);
		if (balance == 1) {
			leftleftRotation1(ptr);			
		} else if (balance == -1) {
			leftrightRotation1(ptr);
		}
	} else if (ptr->balance == -2) {

		int balance = calculateLevel(ptr->rptr);
		if (balance == 1) {
			rightleftRotation(ptr);
		} else if (balance == -1) {
			rightrightRotation(ptr);
		}
	} else {
		printf("\n ------balancing error---\n");fflush(stdout);
	}
}



bool addLevel(AVLNode * ptr, stack<AVLNode*> * childNodeStack) {
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

int calculateLevel(AVLNode * ptr) {
	int level = 0;
	stack<stack<AVLNode*>* > * stack_of_stack = new stack<stack<AVLNode*>*>();
	stack<AVLNode*> * childNode = new stack<AVLNode*>();
	addLevel(ptr, childNode);
	if (childNode->size() > 0) {
		level++;
		stack_of_stack->push(childNode);
	}
	while (stack_of_stack->size() > 0) {
		stack<AVLNode*>* st = stack_of_stack->pop();
		stack<AVLNode*>* childNode = new stack<AVLNode*>();
		while (st->size() > 0) {
			AVLNode * nodePtr = st->pop();
			addLevel(nodePtr, childNode);
		}
		if (childNode->size() > 0) {
			level++;
			stack_of_stack->push(childNode);

		}

	}
	return level;
}

AVLNode * addNode(AVLNode * root, int data) {
	AVLNode * ptr = root;
	while (1) {
		if (data < ptr->data) {
			if (ptr->lptr == NULL) {
				AVLNode * ptr1 = new AVLNode(data);
				ptr->lptr = ptr1;
				ptr1->parent = ptr;
				return ptr1;
			} else if (ptr->lptr != NULL) {
				ptr = ptr->lptr;
			}
		} else if (data > ptr->data) {
			if (ptr->rptr == NULL) {
				AVLNode * ptr2 = new AVLNode(data);
				ptr->rptr = ptr2;
				ptr2->parent = ptr;
				return ptr2;

			} else if (ptr->rptr != NULL) {
				ptr = ptr->rptr;
			}
		}
	}
	return NULL;
}
