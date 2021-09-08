// dijkstra's algorithm in C++ code with love and passion by H.T.Nguyên
#include <iostream>

#define INFINITY 999999

using namespace std;

void Dijkstra(int** graph, int n, int start) {
	int** cost = new int* [n];
	for (int i = 0; i < n; i++)
		cost[i] = new int[n];
	
	int* distance = new int[n];
	int* pred = new int[n];
	int* visited = new int[n];
	int count, mindistance, nextnode;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (graph[i][j] == 0)
				cost[i][j] = INFINITY;
			else
				cost[i][j] = graph[i][j];

	for (int i = 0; i < n; i++) {
		distance[i] = cost[start][i];
		pred[i] = start;
		visited[i] = 0;
	}

	// Distance of self loop is zero
	distance[start] = 0;
	visited[start] = 1;
	count = 1;

	while (count < n - 1) {
		mindistance = INFINITY;

		// Update the distance between neighbouring vertex and source vertex
		for (int i = 0; i < n; i++)
			if (distance[i] < mindistance && !visited[i]) {
				mindistance = distance[i];
				nextnode = i;
			}

		visited[nextnode] = 1;

		// Update all the neighbouring vertex distances
		for (int i = 0; i < n; i++)
			if (!visited[i])
				if (mindistance + cost[nextnode][i] < distance[i]) {
					distance[i] = mindistance + cost[nextnode][i];
					pred[i] = nextnode;
				}
		count++;
	}

	// Printing the distance
	for (int i = 0; i < n; i++)
		if (i != start)
			cout << "Distance from source to " << i << distance[i];
}

// How it work: create dynamic array tier 2 (graph) -> Dijkstra
