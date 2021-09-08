// Topological Sorting (Normal) in C++ code with love and passion by H.T.Nguy�n
#include <iostream>

using namespace std;

void topologicalSorting(int** graph, int n) {
	int* deg = new int[n] {0};
	int* flag = new int[n] {0};

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			deg[i] = deg[i] + graph[j][i];

	cout << "The topological order is: "; 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (deg[j] == 0 && flag[j] == 0) {
				cout << j + 1;
				flag[j] = 1;
			}

			for (int k = 0; k < n; k++) {
				if (graph[k][j] == 1)
					deg[j]--;
			}
		}
	}
}

// How it work: create dynamic array tier 2 (graph) -> topologicalSorting