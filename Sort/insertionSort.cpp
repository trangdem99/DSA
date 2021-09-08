// Insertion sort in C++ code with love and passion by H.T.Nguyên

#include <iostream>
using namespace std;

// print data
void printData(int* data, int size) {
    for (int i = 0; i < size; ++i) {
        cout << "  " << data[i];
    }
    cout << endl;
}

void insertionSort(int* data, int size) {
    for (int i = 1; i < size; i++) {
        int key = data[i];
        int j = i - 1;

        // Compare key with each element on the left of it until an element smaller than it is found.
        // For descending order, change key < data[j] to key > data[j].
        while (key < data[j] && j >= 0) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

// How it work: create dynamic array -> insertionSort