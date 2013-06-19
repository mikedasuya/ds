


template<class T>

class SortedStack {
	SortedStack(T ar[], int size) {
		counter = -1;
	}

T pop() {

	counter--;
	if (counter < 0) {
		return array[i]	
	} else {
			cout <<endl<<"Stack is empty"<<endl;
	}

	return NULL;
}

bool push(T obj) {
	counter++;
	array[counter] = obj;
	selectionSort(array);

}

int size() {
	return counter;
}

bool selectionSort(T ar[], int size) {
	if (size == 0) {
		return;
	}
	for (int i = 0; i <= size; i++) {
					
		T obj = ar[i];
		for (int j = 0; j < i; j++) {
			if (ar[i].key > obj.i) {
				for (int k = 0; k <
			}
		}

	}

}
	private:
	int counter;
	T array[MAXLIMIT];



};

