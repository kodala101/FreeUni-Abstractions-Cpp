#ifndef PQueue_DoublyLinkedList_Included
#define PQueue_DoublyLinkedList_Included

#include <string>

using namespace std;

class DoublyLinkedListPriorityQueue {
public:
	DoublyLinkedListPriorityQueue();
	
	~DoublyLinkedListPriorityQueue();
	
	int size();
	
	bool isEmpty();
	
	void enqueue(string value);
	
	string peek();
	
	string dequeueMin();

private:
	struct cell {
		string val;
		cell* back;
		cell* front;
	};

	cell* elem;
	cell* first;
	int length;
};

#endif
