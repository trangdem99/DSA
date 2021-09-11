#include <iostream>

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

void cycleSort(int* data, int n)
{
	int writes = 0;

	// traverse array elements and put it to on the right place
	for (int c_start = 0; c_start <= n - 2; c_start++) {
		int item = data[c_start];

		// Find position where we put the item.
		int pos = c_start;
		for (int i = c_start + 1; i < n; i++)
			if (data[i] < item)
				pos++;

		if (pos == c_start)
			continue;

		while (item == data[pos])
			pos += 1;

		if (pos != c_start) {
			swap(item, data[pos]);
			writes++;
		}

		// Rotate rest of the cycle
		while (pos != c_start) {
			pos = c_start;

			for (int i = c_start + 1; i < n; i++)
				if (data[i] < item)
					pos += 1;

			while (item == data[pos])
				pos += 1;

			if (item != data[pos]) {
				swap(item, data[pos]);
				writes++;
			}
		}
	}
}

int main() {
	cout << "Welcome to Cycle Sort Implementation !!!" << endl;
	int size;
	cout << "Input size: "; cin >> size;

	int* data = new int[size];

	for (int i = 0; i < size; i++) {
		cout << "Input element number " << i + 1 << " : ";
		cin >> data[i];
	}

	cycleSort(data, size);

	cout << "Sorted Array in Ascending Order:" << endl;

	printData(data, size);

	return 0;
}
