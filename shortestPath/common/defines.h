#ifndef __defined_h
#define __defined_h


class Edge {
	public:
	char getEdgeChar(int i) {
		char a = 'A';
		if (i == 0) {
			a = 'A';
		}
		if (i == 1) {
			a= 'B';
		}
		if (i == 2) {
			a = 'C';
		}
		if (i == 3) {
			a = 'D';
		}
		if (i == 4) {
			a = 'E';
		}
		if (i == 5) {
			a = 'F';
		}
		if (i == 6) {
			a = 'G'
		}
		return a;
	}
};


#endif

