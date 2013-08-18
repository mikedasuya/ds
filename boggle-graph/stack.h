#ifndef __stack_h
#define __stack_h

//class node;

template <class T>
class stack {
	public:
	stack() {
		index = -1;
	}
	~stack() {
	}
	int size() {
		return index;
	}
	void push(T i) {
		index++;
		arr[index] = i;
	}
	T pop() {
		return arr[index--];
	}
	private:
	stack<T>(stack<T>&);
	stack<T>& operator = (const stack<T>&);
	int index;
	T arr[100];
};

#endif
