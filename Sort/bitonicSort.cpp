#include<iostream>
using namespace std;

void printData(int* data, int size) {
	for (int i = 0; i < size; ++i) {
		cout << "  " << data[i];
	}
	cout << endl;
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

/*The parameter dir indicates the sorting direction, ASCENDING or DESCENDING; if (a[i] > a[j]) agrees with the direction, then a[i] and a[j] are interchanged.*/
void compAndSwap(int* data, int i, int j, int dir) {
	if (dir == (data[i] > data[j]))
		swap(data[i], data[j]);
}

/*It recursively sorts a bitonic sequence in ascending order, if dir = 1, and in descending order otherwise (means dir=0). The sequence to be sorted starts at index position low, the parameter cnt is the number of elements to be sorted.*/
void bitonicMerge(int* data, int low, int cnt, int dir) {
	if (cnt > 1) {
		int k = cnt / 2;
		for (int i = low; i < low + k; i++)
			compAndSwap(data, i, i + k, dir);
		bitonicMerge(data, low, k, dir);
		bitonicMerge(data, low + k, k, dir);
	}
}

/* This function first produces a bitonic sequence by recursively sorting its two halves in opposite sorting orders, and then calls bitonicMerge to make them in the same order */
void bitonicSort(int* data, int low, int cnt, int dir) {
	if (cnt > 1) {
		int k = cnt / 2;

		// sort in ascending order since dir here is 1
		bitonicSort(data, low, k, 1);

		// sort in descending order since dir here is 0
		bitonicSort(data, low + k, k, 0);

		// Will merge whole sequence in ascending order since dir=1.
		bitonicMerge(data, low, cnt, dir);
	}
}

int main() {
	cout << "Welcome to Bitonic Sort Implementation !!!" << endl;
	int size;
	cout << "Input size: "; cin >> size;

	int* data = new int[size];

	for (int i = 0; i < size; i++) {
		cout << "Input element number " << i + 1 << " : ";
		cin >> data[i];
	}

	bitonicSort(data, 0, size, 1);

	cout << "Sorted Array in Ascending Order:" << endl;

	printData(data, size);

	return 0;
}
