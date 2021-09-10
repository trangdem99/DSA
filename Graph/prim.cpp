// Prim's algorithm in C++ code with love and passion by H.T.Nguyên
#include <iostream>

#define INFINITY 999999

using namespace std;

void addEdge(int** graph, int pos1, int pos2, int weight) {
	graph[pos1][pos2] = weight;
	graph[pos2][pos1] = weight;
}

void removeEdge(int** graph, int pos1, int pos2, int weight) {
	graph[pos1][pos2] = weight;
	graph[pos2][pos1] = weight;
}

int** createAdjMatrix(int numVertices) {
	int** graph = new int* [numVertices];

	for (int i = 0; i < numVertices; i++)
		graph[i] = new int[numVertices] {0};

	return graph;
}

void prim(int** graph, int numVertices) {
	// create a array to track selected vertex
	bool* selected = new bool[numVertices] {false};

	// store the result
	int* result = new int[numVertices] {0};

	// pick minimum weight edge
	int* key = new int[numVertices];

	for (int i = 0; i < numVertices; i++)
		key[i] = INFINITY;

	key[0] = 0;
	result[0] = -1;

	for (int i = 0; i < numVertices - 1; i++) {
		int min = INFINITY;
		int min_index;

		for (int j = 0; j < numVertices; j++)
			if (key[j] < min && selected[j] == false) {
				min = key[j];
				min_index = j;
			}
		selected[min_index] = true;

		for (int j = 0; j < numVertices; j++)
			if (graph[min_index][j] && graph[min_index][j] < key[j] && selected[j] == false) {
				result[j] = min_index;
				key[j] = graph[min_index][j];
			}
	}

	for (int i = 1; i < numVertices; i++)
		cout << result[i] << "-" << i << "   " << graph[i][result[i]] << endl;
}

void printGraph(int** graph, int numVertices) {
	for (int i = 0; i < numVertices; i++) {
		for (int j = 0; j < numVertices; j++)
			cout << graph[i][j] << " ";
		cout << endl;
	}
}

int main() {
	int numVertices; cout << "Enter the number of vertices: "; cin >> numVertices;
	int numEdges; cout << "Enter the number of edges: "; cin >> numEdges;
	int** graph = createAdjMatrix(numVertices);

	for (int i = 0; i < numVertices; i++) {
		int pos1, pos2, weight;
		cout << "Enter first vertex of edge " << i + 1 << " : "; cin >> pos1;
		cout << "Enter second vertex of edge " << i + 1 << " : "; cin >> pos2;
		cout << "Enter weight of edge " << i + 1 << " : "; cin >> weight;
		addEdge(graph, pos1 - 1, pos2 - 1, weight);
	}

	printGraph(graph, numVertices);

	prim(graph, numVertices);
	
	return 0;
}
