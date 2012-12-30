#include "stack.h"


stack::stack():index(0) {
 
}

stack::~stack() {
}
void stack::push(node* ptr) {
	arr[++index] = ptr;
}
node * stack::pop() {
	return arr[index--];
}
int stack::size() {
	return index;
}
