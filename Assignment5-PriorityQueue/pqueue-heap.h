#ifndef PQueue_Heap_Included
#define PQueue_Heap_Included

#include <string>

using namespace std;

class HeapPriorityQueue {
public:
	HeapPriorityQueue();
	
	~HeapPriorityQueue();
	
	int size();
	
	bool isEmpty();
	
	void enqueue(string value);
	
	string peek();
	
	string dequeueMin();

private:
	int length;
	int numOfElems;
	string* arr;
	void grow();
	void bubble_up(string value);
	void bubble_down();
};

#endif
