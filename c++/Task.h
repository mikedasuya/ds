#ifndef __TASK_H
#define __TASK_H

#include <iostream>
#include "ThreadTask.h"
	
using namespace std;

class Task:public ThreadTask {
	private:
	int inden;
	public:
	Task(int identifier) {
		inden = identifier;
	}
	void execute() {
		cout << "Task"<<inden<<endl;
	
	}
	~Task() {
		cout <<endl<<"Task destrcutor called" <<endl;
	}
};

#endif //endif



