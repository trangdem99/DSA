// Selection sort in C++ code with love and passion by H.T.Nguyên

#include <iostream>
using namespace std;

// function to print an array
void printArray(int* data, int size) {
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

void selectionSort(int* data, int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {

            // To sort in descending order, change > to < in this line.
            // Select the minimum element in each loop.
            if (data[j] < data[min_idx])
            min_idx = j;
        }

        // put min at the correct position
        int temp = data[min_idx];
        data[min_idx] = data[i];
        data[i] = temp;
    }
}