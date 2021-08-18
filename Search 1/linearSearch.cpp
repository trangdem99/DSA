#include <iostream>

using namespace std;

int linearSearch(int * data, int key, int size) {
	// Check each element by loop and if from begin to end
	for (int i = 0; i < n; i++)
		if (data[i] == key)
			return i;
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

	int k = linearSearch(data, key, size);

	if (k == -1)
		cout << "Cannot found your key in the array" << endl;
	else
		cout << "Found your key at " << k << " in the array" << endl;

	return 0;
}