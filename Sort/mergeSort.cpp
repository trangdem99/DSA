// Merge sort in C++ code with love and passion by H.T.Nguyên
#include <iostream>

using namespace std;

// print data
void printData(int* data, int size) {
	for (int i = 0; i < size; ++i) {
		cout << "  " << data[i];
	}
	cout << endl;
}

void merge(int* data, int first, int mid, int last) {
	int* temp = new int[last - first + 1];
	int first1 = first, last1 = mid;
	int first2 = mid + 1, last2 = last;
	int cur = 0;

    // Until we reach either end of either last1 or last2, pick larger among elements first1 and first2 and place them in the correct position
	while ((first1 <= last1) && (first2 <= last2)) {
		if (data[first1] <= data[first2]) {
			temp[cur] = data[first1];
			first1++;
		}
		else {
			temp[cur] = data[first2];
			first2++;
		}
		cur++;
	}

    // Pick up the remaining elements and put in remaining position in sorted array
	while (first1 <= last1) {
		temp[cur] = data[first1];
		first1++;
		cur++;
	}

    // Pick up the remaining elements and put in remaining position in sorted array
	while (first2 <= last2) {
		temp[cur] = data[first2];
		first2++;
		cur++;
	}

    // Transfer back to the main arrray
	for (int i = 0; i < cur; i++)
		data[i + first] = temp[i];

}

void mergeSort(int* data, int first, int last) {
	if (first >= last)
		return;

    // Mid is the point where the array is divided into two subarrays
	int mid = (first + last) / 2;
	mergeSort(data, first, mid);
	mergeSort(data, mid + 1, last);

    // Merge the sorted subarrays
	merge(data, first, mid, last);
}

int main() {
	cout << "Welcome to Merge Sort Implementation !!!" << endl;
	int size;
	cout << "Input size: "; cin >> size;

	int* data = new int[size];

	for (int i = 0; i < size; i++) {
		cout << "Input element number " << i + 1 << " : ";
		cin >> data[i];
	}

	mergeSort(data, 0, size - 1);

	cout << "Sorted Array in Ascending Order:" << endl;

	printData(data, size);

	return 0;
}