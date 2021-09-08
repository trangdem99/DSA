// Adjacency Matrix in C++ code with love and passion by H.T.Nguyên
#include <iostream>
#include <string>

using namespace std;

void addEdge(bool** adjMatrix, int i, int j) {
	adjMatrix[i][j] = true;
	adjMatrix[j][i] = true;
}

void removeEdge(bool** adjMatrix, int i, int j) {
	adjMatrix[i][j] = false;
	adjMatrix[j][i] = false;
}

bool** createAdjMatrix(bool** adjMatrix, int numVertices) {
	bool** adjMatrix = new bool* [numVertices];

	for (int i = 0; i < numVertices; i++)
		adjMatrix[i] = new bool[numVertices] {false};

	return adjMatrix;
}

// How it work: createAdjMatrix -> addEdge