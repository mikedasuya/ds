#include <iostream>
#include "ThreadPool.h"
#include <boost/thread.hpp>
#include <stdio.h>


ThreadPool * ptrt;

using namespace std;
void* f2(void *) {
	while (1) {
		ThreadTask * t1 = new Task(12);
		boost::shared_ptr<ThreadTask> pt(t1);
		ptrt->addTask(pt);

		ThreadTask * t2 = new Task(13);
		boost::shared_ptr<ThreadTask> pt1(t2);
		ptrt->addTask(pt1);
		
		ThreadTask * t3 = new Task(14);
		boost::shared_ptr<ThreadTask> pt2(t3);
		ptrt->addTask(pt2);
		
		ThreadTask * t4 = new Task(15);
		boost::shared_ptr<ThreadTask> pt3(t4);
		ptrt->addTask(pt3);
		
		sleep(4);
	}
}

int main() {
	ThreadPool th(2);
	ptrt = &th;
	/*for (int i = 0; i < 2;i++) {
		ThreadTask * t1 = new Task(i);
		boost::shared_ptr<ThreadTask> pt(t1);
		th.addTask(pt);
	}
	pthread_t tid;
	pthread_create(&tid, NULL, f2, NULL);
	while (1) {
		int ch;
		scanf("%d",&ch);
		if (ch == 10)  {
			break;
		}
		ThreadTask * t1 = new Task(8);
		boost::shared_ptr<ThreadTask> pt(t1);
		th.addTask(pt);
	}*/
	
	while (1) {
		int ch;
		scanf("%d",&ch);
		if (ch == 10)  {
			break;
		} else if (ch == 20) {
			pthread_t tid;
			pthread_create(&tid, NULL, f2, NULL);
		}
		ThreadTask * t1 = new Task(8);
		boost::shared_ptr<ThreadTask> pt(t1);
		th.addTask(pt);
	}
	th.wait();

}
