#ifndef __GR_NODE_H
#define __GR_NODE_H
#include <string>
#include "defines.h"
#include <iostream>
#include <utility>
#include <vector>
#include <map>


using namespace std;

class GrNode {
	private:
	string arc;
	int val;
	vector<pair<int, int> > vect;
	int ar[7][7];
	int calculateVal( ) {
		vector<pair<int,int> >::iterator iter = vect.begin();
		int val = 0;
		while (iter != vect.end()) {
			pair<int, int> p = *iter;
			int start = p.first;
			int end = p.second;
			val = val + ar[start][end];
			++iter;
		}
		
		return val;
	}
	public:
	GrNode * next;
	 
	void assign(int r[7][7]) {
		for (int j = 0 ; j < 7; j++) {
			for (int k = 0; k < 7; k++) {
				ar[j][k] = r[j][k];
			}
		}
	}
	GrNode(int start, int end, int r[7][7]) {
	  assign(r);
	  pair<int, int> p(start, end);
	  vect.push_back(p);
	  calculateVal();
	  next = NULL;	
	}
	GrNode(vector< pair<int,int> > vec, int start, int end, int r[7][7]) {
	
	
	  assign(r);
	  vect = vec;
	  pair<int, int> p(start, end);
	  vect.push_back(p);
	  calculateVal();	
	  next = NULL;
	
	}
	bool setArc(vector< pair<int, int> > vec) {
		vect = vec;
		calculateVal();
	}

	vector< pair<int, int> > getArc() {
		return vect;
	}
	int getVal() {
		return val;
	}
	int endArc() {
		vector < pair<int, int> >::iterator end = vect.end();
		pair<int, int> p = *end;
		int endelement = p.second;
		return endelement;
	}
	int startArc() {
		vector < pair<int, int> >::iterator start = vect.begin();
		pair<int, int> p = *start;
		int endelement = p.first;
		return endelement;
	}



	void printArc() {

		vector<pair<int , int > >::iterator iter = vect.begin();
		string str;
		while (iter != vect.end()) {
			pair<int, int> p = *iter;
			int start = p.first;
			int end = p.second;
			Edge * ed = new Edge();
			str += ed->getEdgeChar(start);
			str += ed->getEdgeChar(end);
		}
		cout << endl << "edge " << str<<endl;
		cout << endl << "edge " << val<<endl;
	}

};



#endif //NODE_H
