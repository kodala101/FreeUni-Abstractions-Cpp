#include "Trailblazer.h"
#include "TrailblazerGraphics.h"
#include "TrailblazerTypes.h"
#include "TrailblazerPQueue.h"
#include "random.h"

using namespace std;

/* Function: shortestPath
 * 
 * Finds the shortest path between the locations given by start and end in the
 * specified world.	 The cost of moving from one edge to the next is specified
 * by the given cost function.	The resulting path is then returned as a
 * Vector<Loc> containing the locations to visit in the order in which they
 * would be visited.	If no path is found, this function should report an
 * error.
 *
 * In Part Two of this assignment, you will need to add an additional parameter
 * to this function that represents the heuristic to use while performing the
 * search.  Make sure to update both this implementation prototype and the
 * function prototype in Trailblazer.h.
 */
Vector<Loc> shortestPath( Loc start, Loc end, Grid<double>& world, double costFunction(Loc one, Loc two, Grid<double>& world), double heuristic(Loc start, Loc end, Grid<double>& world) ) {
	Map<Loc, Loc> pathMap;		//This map keeps parent-child relationships between adjacent Locs in order to generate path in the end.
	Set<Loc> green;			//This set keeps Locs for which we have already found the smallest path. 		
	TrailblazerPQueue<Loc> yellow;		//Structure for Locs we still need to process.
	Map<Loc, double> yellsAndLengths;		//This map stores Locs as keys and their current costs as values. 
	yellow.enqueue(start, heuristic(start, end, world));
	yellsAndLengths.put(start, 0);
	pathMap.put(start, start);
	colorCell(world, start, YELLOW);

	while (!yellow.isEmpty()) {
		Loc min = yellow.dequeueMin();
		green.add(min);
		colorCell(world, min, GREEN);
		if (min == end) break;
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (i == 0 && j == 0) continue;		//We need to skip this case, because Loc won't change.
				if (world.inBounds(min.row + i, min.col + j)) {
					Loc next;
					next.row = min.row + i;
					next.col = min.col + j;
					if (yellsAndLengths.containsKey(next)) {
						double nextCost = costFunction(min, next, world);
						if (yellsAndLengths[min] + nextCost < yellsAndLengths[next]) {
							yellsAndLengths[next] = yellsAndLengths[min] + nextCost;
							yellow.decreaseKey(next, yellsAndLengths[min] + nextCost + heuristic(next, end, world));
							pathMap[next] = min;		//Updating the parent-child relationship.
						}
					}
					else if (!green.contains(next)) {
						double nextCost = costFunction(min, next, world);
						yellow.enqueue(next, yellsAndLengths[min] + nextCost + heuristic(next, end, world));
						colorCell(world, next, YELLOW);
						yellsAndLengths.put(next, yellsAndLengths[min] + nextCost);
						pathMap.put(next, min);
					}
					//If Set 'green' contains next, nothing happens.
				}
			}
		}
	}

	//Generate the shortest path from start to end using pathMap;
	Vector<Loc> path;		
	Loc curr = end;
	while (curr != start) {
		path.insert(0, curr);
		curr = pathMap[curr];
	}
	path.insert(0, start);
	
    return path;
}

//This function will create a rectengular grid (each node will be only connected to its left, wight, top and bottom node),
//will randomize weights of edges, will add each node as a single cluster in Vector 'clusters' and will add each edge
//in queue with priority equall to its weight.
void createGraphs(Grid<bool>& connectedNodes, Grid<double>& weightOfEdges, Vector< Set<int> >& clusters, TrailblazerPQueue<Edge>& queue, int numRows, int numCols) {
	for (int i = 0; i < connectedNodes.numRows(); i++) {
		for (int j = 0; j < connectedNodes.numCols(); j++) {
			weightOfEdges[i][j] = -1;		//Set every potential edge weight -1.
			if (connectedNodes[i][j] == false && abs(i - j) == 1) {
				if ((i % numCols == 0 && j > i) || (j % numCols == 0 && i > j)) {	//Rows last node and next rows first node should not be connected.
					connectedNodes[i][j] = true;
					connectedNodes[j][i] = true;
				}
				if (i % numCols != 0 && j % numCols != 0) {
					connectedNodes[i][j] = true;
					connectedNodes[j][i] = true;
				}
			}
			if (connectedNodes[i][j] == false && abs(i - j) == numCols) {		//Top-down connection.
				connectedNodes[i][j] = true;
				connectedNodes[j][i] = true;
			}
		}
	}

	for (int i = 0; i < weightOfEdges.numRows(); i++) {
		Set<int> oneClas;	
		oneClas.add(i);		
		clusters.add(oneClas);		//This will add each node as a cluster (Set) in Vector of all clusters - 'clusters'.
		for (int j = 0; j < weightOfEdges.numCols(); j++) {
			if (connectedNodes[i][j] && weightOfEdges[i][j] == -1) {
				weightOfEdges[i][j] = randomReal(0, 1);
				weightOfEdges[j][i] = weightOfEdges[i][j];
				Edge side;
				Loc first;
				Loc second;
				first.row = i / numCols;		//Calculating the position of nodes in the graph with their indices.
				first.col = i % numCols;
				second.row = j / numCols;
				second.col = j % numCols;
				side.start = first;
				side.end = second;
				queue.enqueue(side, weightOfEdges[i][j]);
			}
		}
	}
}

//This function will return true if both nodes of given Edge 'e' are in the same cluster
//and will return false if they are not.
bool isIncluster(Edge& e, Vector< Set<int> >& clusters, Set<int>& s1, Set<int>& s2, int numRows, int numCols, int& a, int& b) {
	int startInd = e.start.row * numCols + e.start.col;		//Calculating index of the node with position in the graph
	int endInd = e.end.row * numCols + e.end.col;
	for (int i = 0; i < clusters.size(); i++) {
		bool b1 = false;
		bool b2 = false;
		if (clusters[i].contains(startInd) && !clusters[i].contains(endInd)) {
			s1 = clusters[i];		//Saving the starting node's cluster and its index in Vector.
			a = i;
			b1 = true;
		}
		if (!clusters[i].contains(startInd) && clusters[i].contains(endInd)) {
			s2 = clusters[i];		//Saving the ending node's cluster and its index in Vector.
			b = i;
			b2 = true;
		}
		if (b1 && b2) return false;
		if (clusters[i].contains(startInd) && clusters[i].contains(endInd)) return true;
	}
	return false;
}

Set<Edge> createMaze(int numRows, int numCols) {
	Grid<bool> connectedNodes(numRows * numCols, numRows * numCols);		//(i;j) cell in this grid is true if i-th and j-th nodes are connected in graph and false if they are not.
	Grid<double> weightOfEdges(numRows * numCols, numRows * numCols);		//(i;j) cell in this grid keeps the weight of the edge between i-th and j-th nodes.
	Set<Edge> maze;
	Vector< Set<int> > clusters;		//Each Set in this Vector represents clusters of numbered nodes.
	TrailblazerPQueue<Edge> queue;
	createGraphs(connectedNodes, weightOfEdges, clusters, queue, numRows, numCols);

	while (!queue.isEmpty()) {
		Edge e = queue.dequeueMin();

		Set<int> s1;
		Set<int> s2;
		int a = 0;
		int b = 0;
		if (!isIncluster(e, clusters, s1, s2, numRows, numCols, a, b)) {
			if (a > b) {
				clusters.remove(a);
				clusters.remove(b);
			}
			else {
				clusters.remove(b);
				clusters.remove(a);
			}
			maze.add(e);
			clusters.add(s1 + s2);		//Merging the clusters.
		}
	}

    return maze;
}

//Generating Huge maze map takes about 40 second - just in case.