 #include "pqueue-doublylinkedlist.h"
#include "error.h"

DoublyLinkedListPriorityQueue::DoublyLinkedListPriorityQueue() {
	elem = NULL;
	first = NULL;
	length = 0;
}

DoublyLinkedListPriorityQueue::~DoublyLinkedListPriorityQueue() {
	for (cell* c = elem; c != NULL;) {
		cell* nextt = c->front;
		delete c;
		c = nextt;
	}
}

int DoublyLinkedListPriorityQueue::size() {
	return length;
}

bool DoublyLinkedListPriorityQueue::isEmpty() {
	return size() == 0;
}

void DoublyLinkedListPriorityQueue::enqueue(string value) {
	if (isEmpty()) {
		cell* neww = new cell;
		neww->val = value;
		neww->back = NULL;
		neww->front = NULL;
		elem = neww;
	}
	else {
		cell* neww = new cell;
		neww->val = value;
		neww->back = NULL;
		neww->front = elem;
		elem->back = neww;
		elem = neww;
	}
	length++;
}

string DoublyLinkedListPriorityQueue::peek() {
	if (isEmpty()) error("Queue is empty!");
	first = elem;
	for (cell* c = elem; c != NULL; c = c->front) {
		if (c->val < first->val) first = c;
	}
	return first->val;
}

string DoublyLinkedListPriorityQueue::dequeueMin() {
	string s = peek();
	
	if (first->back == NULL && first->front != NULL) {
		first->front->back = NULL;
		elem = first->front;
	}
	else if (first->back != NULL && first->front == NULL) {
		first->back->front = NULL;
	}
	else if (first->back != NULL && first->front != NULL) {
		first->back->front = first->front;
		first->front->back = first->back;
	}
	else if (first->back == NULL && first->front == NULL) {
		elem = NULL;
	}
	delete first;
			
	length--;

	return s;
}
