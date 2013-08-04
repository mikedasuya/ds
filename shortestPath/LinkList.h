#ifndef __LINK_LIST
#define __LINK_LIST

#include "GrNode.h"
#include <ext/hash_map>

using namespace std;

class LinkList1 {
	private:
	GrNode * root;
	int count;
	multimap<int, int> mapEndArc;
	public:
	LinkList1() {
		count = 0;
	}
	int size() {
		return count;
	}
	bool insert(GrNode * ptr, int ar[7][7]) {
	 if (root == NULL) {
		 	root = new GrNode(ptr->startArc(), ptr->endArc(), ar);
			root->setArc(ptr->getArc());
			mapEndArc.insert(pair<int,int>(ptr->startArc(), ptr->endArc()));
			return true;
	 }
	 multimap<int, int>::iterator iter1 = mapEndArc.find(ptr->endArc());
	 if (iter1 != mapEndArc.end()) {
		GrNode * moveptr = root;
		while (moveptr->endArc() != ptr->endArc()) {
			moveptr = moveptr->next;

		}
		if (moveptr->getVal() > ptr->getVal()) {
			moveptr->setArc(ptr->getArc());
		}

	 } else {
		if (ptr->getVal() < root->getVal() ||
			ptr->getVal() == root->getVal() ) {
			ptr->next = root->next;
			root = ptr;
			mapEndArc.insert(pair<int, int>(root->endArc(), root->endArc()));
		} else if (ptr->getVal() > root->getVal()) {
			GrNode * mvptr = root;
			while (mvptr->next != NULL &&
				   mvptr->getVal() < ptr->getVal()) {
				mvptr = mvptr->next;
		
			}
			ptr->next = mvptr->next;
			mvptr->next = ptr;
			mapEndArc.insert(pair<int, int>(ptr->endArc(), ptr->endArc()));

		}
	 }

	}

	GrNode * getLatest() {
		GrNode * mvptr = root;
		root = root->next;
		mvptr->next = NULL;
		mapEndArc.erase(mvptr->endArc());
		return mvptr;
	}

	bool isIterationNeeded() {
		int count = 0;
		GrNode * mvptr = root;
		while (mvptr->next != NULL) {
			count++;
		}
		if (count > 1 && root->endArc() == 6) {
			return false;
		} 
		if (count == 1) {
			return false;
		}
		return true;
	}

};


#endif

