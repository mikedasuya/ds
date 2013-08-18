#include <stdio.h>
#include<iostream>
#include <stdlib.h>
#include <hash_set>
#include <hash_map>
#include <vector>
#include <unordered_set>
#include "stack.h"
#include <utility>

using namespace std;                                
using namespace __gnu_cxx;

struct Node {
	Node * next;
	Node * previous;
	stack<char> stack_char;
	char c;
	Node() {
		next = NULL;
		previous = NULL;
	}
};


typedef hash_map<char,vector<char>*> MMap;

typedef std::unordered_set<char> Set;

vector<char>* findAdjacent(int i, int j, char[3][3]);


char getChar(int, int,char[3][3]);

int main() {
	char ar[3][3] = { {'a','b','c'},
					{'d','e','f'},
					{'g','h','i'}
				   };
	MMap map;

	for (int i = 0; i < 3; i++) {
		for (int j = 0;j < 3; j++) {
			char c = ar[i][j];
			vector<char> * vect_adj = findAdjacent(i, j, ar);
			cout<< "---1 ---"<<endl;
			for (int i = 0; i < vect_adj->size(); i++) {
				char t = vect_adj->at(i);
				cout<< t;
			}
			cout << endl;
			map[c] = vect_adj;
		}
	}
	Set set;
	MMap::iterator iter_map = map.begin();
	char c_root  = iter_map->first;
	vector<char> * vect_char_root = iter_map->second;
	Node * root_node = new Node(); 
    root_node->c = c_root;
	set.insert(c_root);	
	Node * root_ptr = root_node;
	Node *mvptr = root_node;
	vector<char>::iterator iter2 = vect_char_root->begin();
	while (iter2 != vect_char_root->end()) {
		char c = *iter2;
		cout << c;
		root_ptr->stack_char.push(c);
		iter2++;
	}
	cout <<endl << mvptr->stack_char.size() - 1 ;
	while (root_ptr->stack_char.size() > -1) {

		while (mvptr->stack_char.size() > -1) {
			char c = mvptr->stack_char.pop();
			Node * n1 = new Node();
			n1->c = c;
			set.insert(c);
			vector<char>* vect_ptr = map[c];
			vector<char>::iterator iter1 = vect_ptr->begin();
			while (iter1 != vect_ptr->end()) {
				char c = *iter1;
				Set::iterator iter_set = set.find(c);
				if (iter_set != set.end()) {
					} else {
					n1->stack_char.push(c);
				}
				iter1++;
			}
			mvptr->next = n1;
			n1->previous = mvptr;
			mvptr = n1;
		}
		Node * ptr1 = root_node;
		cout <<endl;
		while (ptr1->next != NULL) {
			cout <<ptr1->c;
			ptr1 = ptr1->next;
		}
		cout <<endl;
		while (mvptr->stack_char.size() == -1) {
			Node * back_ptr = mvptr->previous;
			set.erase(mvptr->c);
			mvptr = back_ptr;
			mvptr->next = NULL;

		}
	
	
	} //end this while loop
	
}


vector<char>* findAdjacent(int i, int j, char ar [3][3]) {
	vector<char> * tempVect = new vector<char>();
	int temp_i = i;
	int temp_j = j;
	//i-- j--
	temp_i = i;
	temp_j = j;	
	temp_i--;
	temp_j--;
	char c = getChar( temp_i, temp_j, ar);
	if (c != '$') {
		tempVect->push_back(c);
	}
	// i-- j
	temp_i = i;
	temp_j = j;	
	temp_i--;
	c = getChar( temp_i, temp_j, ar);
	if (c != '$') {
		tempVect->push_back(c);
	}

	//i-- j++
	temp_i = i;
	temp_j = j;	
	temp_i--;
	temp_j++;
	c = getChar( temp_i, temp_j, ar);
	if (c != '$') {
		tempVect->push_back(c);
	}
	//i j--

	temp_i = i;
	temp_j = j;	
	temp_j--;
	c = getChar( temp_i, temp_j, ar);
	if (c != '$') {
		tempVect->push_back(c);
	}


	//i j++
	temp_i = i;
	temp_j = j;	
	temp_i;
	temp_j++;
	c = getChar( temp_i, temp_j, ar);
	if (c != '$') {
		tempVect->push_back(c);
	}

	//i++ j--
	temp_i = i;
	temp_j = j;	
	temp_i++;
	temp_j--;
	c = getChar( temp_i, temp_j, ar);
	if (c != '$') {
		tempVect->push_back(c);
	}
	
	//i++ j
	temp_i = i;
	temp_j = j;	
	temp_i++;
	temp_j;
	c = getChar( temp_i, temp_j, ar);
	if (c != '$') {
		tempVect->push_back(c);
	}
	//i++ j++
	temp_i = i;
	temp_j = j;	
	temp_i++;
	temp_j++;
	c = getChar( temp_i, temp_j, ar);
	if (c != '$') {
		tempVect->push_back(c);
	}
	cout <<endl <<"For character :" << ar[i][j] <<endl;
	vector<char>::iterator iter = tempVect->begin();
	while (iter != tempVect->end()) {
		char c1	= *iter;
		cout << c1 << ":" ;
		iter++;
	}
	cout <<endl;
	return tempVect;
}

char getChar(int i, int j, char ar[3][3]) {	
				
		if (-1 < i && i < 3 && -1 < j && j < 3 ) {
			cout << "Get Char "<<i <<j << ar[i][j]<<endl;
			return ar[i][j];
		}
		return '$';
}





