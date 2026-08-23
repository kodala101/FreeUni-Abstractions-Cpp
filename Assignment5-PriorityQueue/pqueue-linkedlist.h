#ifndef PQueue_LinkedList_Included
#define PQueue_LinkedList_Included

#include <string>

using namespace std;

class LinkedListPriorityQueue {
public:
	LinkedListPriorityQueue();
	
	~LinkedListPriorityQueue();
	
	int size();
	
	bool isEmpty();
	
	void enqueue(string value);
	
	string peek();
	
	string dequeueMin();
	
private:
	struct cell {
		string val;
		cell* next;
	};
	cell* elem;
	int length;
};

#endif
