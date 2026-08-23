#ifndef PQueue_Vector_Included
#define PQueue_Vector_Included

#include <string>
#include <vector>

using namespace std;

class VectorPriorityQueue {
public:
	VectorPriorityQueue();

	~VectorPriorityQueue();

	int size();

	bool isEmpty();

	void enqueue(string value);

	string peek();

	string dequeueMin();

private:
	vector<string> queue;

	string findFirst();

	int indexOfSmallest;

};

#endif
