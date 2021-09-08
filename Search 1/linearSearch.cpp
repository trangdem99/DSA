// Linear Search in C++ code with love and passion by H.T.Nguy�n
#include <iostream>

using namespace std;

int linearSearch(int * data, int key, int size) {
	// Check each element by loop and if from begin to end
	for (int i = 0; i < size; i++)
		if (data[i] == key)
			return i;
	return -1;
}
