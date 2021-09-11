// Linear Search in C++ code with love and passion by H.T.Nguyên
#include <iostream>

using namespace std;

int linearSearch(int* data, int key, int size) {
	// Check each element by loop and if from begin to end
	for (int i = 0; i < size; i++)
		if (data[i] == key)
			return i;
	return -1;
}

int main() {
	cout << "Welcome to Linear Search Implementation !!!" << endl;
	int size, key;
	cout << "Input size: "; cin >> size;
	int* data = new int[size];

	for (int i = 0; i < size; i++) {
		cout << "Input element number " << i + 1 << " : ";
		cin >> data[i];
	}

	cout << "Enter the number you want to find: "; cin >> key;
	if (linearSearch(data, key, size) != -1)
		cout << "Found your key in the array" << endl;
	else
		cout << "Cannot find your key in the array" << endl;

	return 0;
}