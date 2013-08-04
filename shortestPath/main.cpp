#include <iostream>
#include "LinkList.h"
#include <vector>
#include "GrNode.h"


int main() {

	int ar[7][7] = { {0,4,3,7,0,0,0},
					 {0,0,0,1,0,4,0},
					 {0,0,0,3,5,0,0},
					 {0,0,0,0,2,2,7},
					 {0,0,0,0,0,0,2},
					 {0,0,0,0,0,0,4},
					 {0,0,0,0,0,0,0},
					 };
	int j = 0;
	LinkList1 * link = new LinkList1();
	for (int i =0; i < 7;i++) {
		int path = ar[0][i];
		if (path > 0) {
			GrNode * node = new GrNode(0, i, ar);
			link->insert(node, ar);
		}
	}
	while (link->isIterationNeeded() ) {
		GrNode * node = link->getLatest();
		cout << "main"<<node->vect.size()<<endl;
		int row = node->endArc();
		for (int i = 0; i < 7; i++) {
			int path = ar[row][i];
			if (path > 0) {
				vector<pair<int,int> >::iterator iter = node->vect.begin();
				vector <pair<int, int> > vect1;
				while (iter != node->vect.end()) {
					pair<int,int> p = *iter;
					vect1.push_back(p);
					++iter;
				}
				GrNode *node = new GrNode(vect1, row, i, ar);
				link->insert(node, ar);
			}
		}
	}
	link->getLatest()->printArc();
}
