#ifndef __THREAD__POOL
#define __THREAD__POOL

#include <vector>
#include <pthread.h> 
#include <boost/thread.hpp>
#include "Task.h"


using namespace std;



class ThreadPool {
	public:
	ThreadPool(int numberofThreads);
	bool addTask(boost::shared_ptr<ThreadTask> );
	bool wait();
	bool stop();
	~ThreadPool();	
	void execute(int ide);
	private:
	bool stopVar;
		
	
	vector<pthread_t *> vectTid;
	ThreadPool(ThreadPool&);
	
	
	ThreadPool& operator=(const ThreadPool&);
};

#endif //ThreadPool
