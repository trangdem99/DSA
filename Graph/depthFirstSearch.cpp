// Depth First Search in C++ code with love and passion by H.T.Nguyên
#include <iostream>
#include <string>

using namespace std;

struct Node {
	int vertex;
	Node* p_Next;
};

struct Graph {
	int numVertices;
	int* visited;
	Node** adjList;
};

Node* createNode(int vertex) {
	Node* temp = new Node;
	temp->vertex = vertex;
	temp->p_Next = nullptr;
	return temp;
}

Graph* createGraph(int vertices) {
	Graph* temp = new Graph;
	temp->numVertices = vertices;
	temp->adjList = new Node* [vertices];
	temp->visited = new int [vertices];

	for (int i = 0; i < vertices; i++) {
		temp->adjList[i] = nullptr;
		temp->visited = 0;
	}

	return temp;
}

void DFS(Graph* graph, int vertex) {
	Node* adjList = graph->adjList[vertex];
	Node* temp = adjList;

	graph->visited[vertex] = 1;
	cout << "Visited " << vertex << endl;

	while (temp != NULL) {
		int connectedVertex = temp->vertex;

		if (graph->visited[connectedVertex] == 0)
			DFS(graph, connectedVertex);

		temp = temp->p_Next;
	}
}

