#include <iostream>

using namespace std;

int binarySearch(int* data, int key, int left, int right) {
	if (right >= left) {
		int mid = left + (right - left) / 2;

		// Check if the value of the middle element is the key that we found or not
		if (data[mid] == key)
			return mid;
		// Check if the key is higher than value of the middle element the go right
		else if (data[mid] > key)
			return binarySearch(data, key, left, mid - 1);

		// Else then go right
		return binarySearch(data, key, mid + 1, right);
	}

	return -1;
}

int main() {
	int size;
	cout << "Input size: "; cin >> size;

	int* data = new int[size];

	for (int i = 0; i < size; i++) {
		cout << "Input element number " << i + 1 << " : ";
		cin >> data[i];
	}

	int key;
	cout << "Input the key you want to find: " << endl;
	cin >> key;

	int k = binarySearch(data, key, 0, size - 1);

	if (k == -1)
		cout << "Cannot found your key in the array" << endl;
	else
		cout << "Found your key at " << k << " in the array" << endl;

	return 0;
}