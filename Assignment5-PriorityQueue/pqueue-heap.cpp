#include "pqueue-heap.h"
#include "error.h"

const int ARR_SIZE = 10;

HeapPriorityQueue::HeapPriorityQueue() {
	arr = new string[ARR_SIZE];
	length = ARR_SIZE;
	numOfElems = 0;
}

HeapPriorityQueue::~HeapPriorityQueue() {
	delete[] arr;
}

int HeapPriorityQueue::size() {
	return numOfElems;
}

bool HeapPriorityQueue::isEmpty() {
	return size() == 0;
}

void HeapPriorityQueue::enqueue(string value) {
	if (numOfElems == length) grow();
	if (isEmpty()) {
		arr[0] = value;
		numOfElems++;
	}
	else {
		arr[numOfElems] = value;
		numOfElems++;
		bubble_up(value);
	}
}

string HeapPriorityQueue::peek() {
	if (isEmpty()) error("Queue is empty!");
	return arr[0];
}

string HeapPriorityQueue::dequeueMin() {
	if (size() == 1) {
		string s = peek();
		numOfElems--;
		return s;
	} 

	string change = peek();
	arr[0] = arr[numOfElems - 1];
	numOfElems--;

	bubble_down();

	return change;
}

void HeapPriorityQueue::grow() {
	length *= 2;
	string* big = new string[length];
	for (int i = 0; i < size(); i++) big[i] = arr[i];
	delete[] arr;
	arr = big;
}

void HeapPriorityQueue::bubble_up(string value) {
	int index = numOfElems - 1;
	while (value < arr[(index - 1) / 2]) {
		arr[index] = arr[(index - 1) / 2];
		arr[(index - 1) / 2] = value;
		index = (index - 1) / 2;
		if (index == 0) break;
	}
}

void HeapPriorityQueue::bubble_down() {
	int index = 0;
	while (true) {
		int leftChild = 2 * index + 1;
		int rightChild = 2 * index + 2;
		int smallestChild = index;

		if (leftChild < numOfElems && arr[leftChild] < arr[smallestChild]) smallestChild = leftChild;

		if (rightChild < numOfElems && arr[rightChild] < arr[smallestChild]) smallestChild = rightChild;

		if (smallestChild == index) break;

		string save = arr[index];
		arr[index] = arr[smallestChild];
		arr[smallestChild] = save;
		index = smallestChild;
	}
}
