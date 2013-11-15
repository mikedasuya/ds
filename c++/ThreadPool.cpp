#include "ThreadPool.h"
#include <iostream>
#include <pthread.h>
#include <queue>
#include "ThreadTask.h"

using namespace std;
std::queue< boost::shared_ptr<ThreadTask> > myqueue;
pthread_mutex_t lock;
pthread_cond_t  cond;
bool condition;

	void execute(boost::shared_ptr<ThreadTask>);

	void * f1(void * ide) {
		while (1) {
			int * valint = (int*)ide;

			if (myqueue.size() > 0) {
				pthread_mutex_lock(&lock);
				boost::shared_ptr<ThreadTask> ptr = (boost::shared_ptr<ThreadTask>)myqueue.front();
				cout <<endl <<" valint thread -ide" <<*valint<<endl;
				pthread_mutex_unlock(&lock);
				execute(ptr);
			} else {
					pthread_mutex_lock(&lock);
					cout <<endl <<"Waitint on the tthread"<< *valint <<endl;
					pthread_cond_wait(&cond,&lock);
					if (myqueue.size() > 0) {
						boost::shared_ptr<ThreadTask> ptr = (boost::shared_ptr<ThreadTask>)myqueue.front();
						pthread_mutex_unlock(&lock);
						execute(ptr);
					} else {
						pthread_mutex_unlock(&lock);
					}
					
				
			}
		}

	}

	void execute(boost::shared_ptr<ThreadTask> ptr) {
			ptr.get()->execute();
			myqueue.pop();
	}

	ThreadPool::ThreadPool(int numberofThreads) {
		lock = PTHREAD_MUTEX_INITIALIZER;
		cond = PTHREAD_COND_INITIALIZER;
		for (int i = 0;i < numberofThreads;i++) {
			pthread_t tid;
			cout<<endl <<"thread created"<<endl;
			pthread_create(&tid, NULL, f1, (void*)&i);
			vectTid.push_back(&tid);
		}
	}

	bool ThreadPool::addTask(boost::shared_ptr<ThreadTask> ptr) {
		pthread_mutex_lock(&lock);
		myqueue.push(ptr);
		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&lock);
	}

	bool ThreadPool::wait() {
		vector<pthread_t*>::iterator iter = vectTid.begin();
		while (iter != vectTid.end()) {
			pthread_t* ptid = *iter;
			pthread_join(*ptid, NULL);
			iter++;
		}
	}

	bool ThreadPool::stop() {

	}

	ThreadPool::~ThreadPool() {

	}
	