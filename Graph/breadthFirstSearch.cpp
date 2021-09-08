#include <iostream>
#include <queue>

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
	temp->adjList = new Node * [vertices];
	temp->visited = new int[vertices];

	for (int i = 0; i < vertices; i++) {
		temp->adjList[i] = nullptr;
		temp->visited = 0;
	}

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

void BFS(Graph* graph, int startVertex) {
	queue<int> q;

	graph->visited[startVertex] = 1;
	q.push(startVertex);

	while (!q.empty()) {
		int currentVertex = q.front();
		cout << "Visited " << currentVertex << " ";
		q.pop();

		Node* temp = graph->adjList[currentVertex];
		
		while (temp) {
			int adjVertex = temp->vertex;
			if (graph->visited[adjVertex] == 0) {
				graph->visited[adjVertex] = 1;
				q.push(adjVertex);
			}
			temp = temp->p_Next;
		}
	}
}

// How it work: createGraph -> addEdge -> BFS