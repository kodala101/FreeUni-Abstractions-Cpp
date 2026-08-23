#include "pqueue-vector.h"
#include "error.h"

VectorPriorityQueue::VectorPriorityQueue() {
	indexOfSmallest = 0;
}

VectorPriorityQueue::~VectorPriorityQueue() {
}

int VectorPriorityQueue::size() {
	return queue.size();
}

bool VectorPriorityQueue::isEmpty() {
	return size() == 0;
}

void VectorPriorityQueue::enqueue(string value) {
	queue.push_back(value);
}

string VectorPriorityQueue::peek() {
	if (isEmpty()) error("Queue is empty!");
	return findFirst();
}

string VectorPriorityQueue::dequeueMin() {
	string first = peek();
	queue.erase(queue.begin() + indexOfSmallest);
	return first;
}

string VectorPriorityQueue::findFirst() {
	string prev = queue[0];
	indexOfSmallest = 0;	//In case first string is the smallest one (for loop starts with i = 1).
	for (int i = 1; i < size(); i++) {
		if (queue[i] < prev) {
			prev = queue[i];
			indexOfSmallest = i;
		}
	}
	return prev;
}

