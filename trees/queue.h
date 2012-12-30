#ifndef __QUEUE_H
#define __QUEUE_H

template <class T>
	class Queue {
	public:
	Queue() {
		setcounter = 0;
		getcounter = 0;
	}
	void setElement(T i) {
		st[++setcounter] = i;
	}
	T getElement() {
		return st[++getcounter];
	}
	int size() {
		return setcounter-getcounter;
	}
	private:
	T st[100];
	int setcounter;
	int getcounter;

	};

#endif
