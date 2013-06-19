#include <stdio.h>
#include <stdlib.h>

class widget {
};

template < class T>
class op {
	T* create() {
			return new T();
	}
};

template < template < class T> class op> 
	class widgetMgr:public op<widget> {
};


template<class T, class U>
void swap(T a, T b, U c) {

}

int main() {

	widgetMgr< op > mgr;
	int a,b;
	char c;
	swap<int, char>(a,b, c);
}
