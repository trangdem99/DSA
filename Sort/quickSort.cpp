// Quick sort in C++ code with love and passion by H.T.Nguyên

#include <iostream>
using namespace std;

// print data
void printData(int* data, int size) {
	for (int i = 0; i < size; ++i) {
		cout << "  " << data[i];
	}
	cout << endl;
}

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

int partition(int* data, int low, int high) {
  
	// select the rightmost element as pivot
	int pivot = data[high];

	// pointer for greater element
	int i = low - 1;

	// traverse each element of the array and compare them with the pivot
	for (int j = low; j < high; j++)
		if (data[j] < pivot) {

			// if element smaller than pivot is found then swap it with the greater element pointed by i
			i++;

			// swap element at i with element at j
			swap(data[i], data[j]);
		}

	// swap pivot with the greater element at i
	swap(data[i + 1], data[high]);

	// return the partition point
	return (i + 1);
}

void quickSort(int * data, int low, int high) {
	if (low < high) {

		// find the pivot element such that
		// elements smaller than pivot are on left of pivot
		// elements greater than pivot are on righ of pivot
		int pi = partition(data, low, high);

		// recursive call on the left of pivot
		quickSort(data, low, pi - 1);

		// recursive call on the right of pivot
		quickSort(data, pi + 1, high);
	}
}