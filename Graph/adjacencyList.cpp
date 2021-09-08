// Adjacency List in C++ code with love and passion by H.T.Nguyên
#include <iostream>
#include <string>

using namespace std;

struct Node {
	int vertex;
	Node* p_Next;
};

struct Graph {
	int numVertices;
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

	for (int i = 0; i < vertices; i++)
		temp->adjList[i] = nullptr;

	return temp;
}

void addEdge(Graph* graph, int src, int des) {
	Node* temp = createNode(des);
	temp->p_Next = graph->adjList[src];
	graph->adjList[src] = temp;
	temp = createNode(src);
	temp->p_Next = graph->adjList[des];
	graph->adjList[des] = temp;
}

// How it work: createGraph -> addEdge