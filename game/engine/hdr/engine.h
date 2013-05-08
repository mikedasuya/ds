#ifndef __ENGINE_H
#define __ENGINE_H

#include "Common.h"

namespace ENGINE {

class Engine {
	private:
	int ar[3][3];
	private:
	int column(INPUT val);
	bool colum0Contains(INPUT val);
	bool colum1Contains(INPUT val);
	bool colum2Contains(INPUT val);
	int diagnals(INPUT val);
        int rows(INPUT val);
	bool row0Contain(INPUT val);
	bool row1Contain(INPUT val);
	bool row2Contain(INPUT val);
	bool assign(int ar[3][3]);
		
	public:
	
	Engine();
	int evaluateState(int ar[3][3], INPUT val);
	
};

}

#endif
