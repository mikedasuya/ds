#ifndef __ENGINE_H
#define __ENGINE_H

#include "Common.h"


class Engine {
	private:
	INPUT forWhom;
	private:
	int column(int ar[3][3], INPUT val);
	bool colum0Contains(int ar[3][3], INPUT val);
	bool colum1Contains(int ar[3][3], INPUT val);
	bool colum2Contains(int ar[3][3], INPUT val);
	public:
	
	Engine(INPUT input );
	int evaluateState(int ar[3][3]);
	
};


#endif
