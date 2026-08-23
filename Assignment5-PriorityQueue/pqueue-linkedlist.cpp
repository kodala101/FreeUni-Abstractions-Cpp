#include "pqueue-linkedlist.h"
#include "error.h"

LinkedListPriorityQueue::LinkedListPriorityQueue() {
	elem = NULL;
	length = 0;
}

LinkedListPriorityQueue::~LinkedListPriorityQueue() {
	for (cell* c = elem; c != NULL;) {
		cell* nextt = c->next;
		delete c;
		c = nextt;
	}
}

int LinkedListPriorityQueue::size() {
	return length;
}

bool LinkedListPriorityQueue::isEmpty() {
	return size() == 0;
}

void LinkedListPriorityQueue::enqueue(string value) {
	if (isEmpty()) {
		cell* neww = new cell;
		neww->val = value;
		neww->next = NULL;
		elem = neww;
		length++;
	}
	else if (value < elem->val) {
		cell* neww = new cell;
		neww->val = value;
		neww->next = elem;
		elem = neww;
		length++;
	}
	else {
		cell* save = NULL;
		for (cell* c = elem; c != NULL; c = c->next) {
			save = c;	//After for loop save will be the last element of linked list.
			if (c->next != NULL && value >= c->val && value <= c->next->val) {
				cell* neww = new cell;
				neww->val = value;

				neww->next = c->next;	
				c->next = neww;

				length++;
				return;
			}
		}
		cell* neww = new cell;	//If the programme reaches this line that means that VALUE is larger than every other string and we have to add it in the last position.
		neww->val = value;
		neww->next = NULL;
		save->next = neww;
		length++;
	}
}

string LinkedListPriorityQueue::peek() {
	if (size() == 0) error("Queue is empty!");
	return elem->val;
}

string LinkedListPriorityQueue::dequeueMin() {
	string s = peek();
	cell* ret = elem;
	elem = elem->next;
	delete ret;
	length--;
	return s;
}
