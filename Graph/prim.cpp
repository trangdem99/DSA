#include <iostream>

#define INFINITY 999999

using namespace std;

void prim(int** graph, int n) {
	// set number of edge to 0
	int no_edge = 0;

	// create a array to track selected vertex
	// selected will become true otherwise false
	int* selected = new int[n];

	// the number of egde in minimum spanning tree will be
	// always less than (n -1), where n is number of vertices in graph

	// choose 0th vertex and make it true
	selected[0] = true;

	while (no_edge < n - 1) {
		int x = 0;  //  row number
		int y = 0;  //  col number
		int min = INFINITY;

		for (int i = 0; i < n; i++) {
			if (selected[i]) {
				for (int j = 0; j < n; j++) {
					if (!selected[j] && graph[i][j]) {  // not in selected and there is an edge
						if (min > graph[i][j]) {
							min = graph[i][j];
							x = i;
							y = j;
						}
					}
				}
			}
		}

		cout << x << " - " << y << " : " << graph[x][y] << endl;
		selected[y] = true;
		no_edge++;
	}
}

// How it work: create dynamic array tier 2 (graph) -> prim