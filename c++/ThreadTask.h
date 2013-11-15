#ifndef __THREAD_TASK_H
#define __THREAD_TASK_H


class ThreadTask {
	public:
	ThreadTask() {

	}
	virtual void execute() = 0;

	virtual ~ThreadTask() {
	}
};


#endif

