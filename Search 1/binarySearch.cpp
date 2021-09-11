// Binaray Search in C++ code with love and passion by H.T.Nguyên
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
	cout << "Welcome to Binary Search Implementation !!!" << endl;
	int size, key;
	cout << "Input size: "; cin >> size;
	int* data = new int[size];


	for (int i = 0; i < size; i++) {
		cout << "Input element number " << i + 1 << " : ";
		cin >> data[i];
	}

	cout << "Enter the number you want to find: "; cin >> key;
	if (binarySearch(data, key, 0, size - 1) != -1)
		cout << "Found your key in the array" << endl;
	else
		cout << "Cannot find your key in the array" << endl;

	return 0;
}