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

// How it work: create dynamic array -> binarySearch (left = 0, right = n - 1)