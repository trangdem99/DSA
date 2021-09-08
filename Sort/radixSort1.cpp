// Radix sort for number in C++ code with love and passion by H.T.Nguyên

#include <iostream>
using namespace std;

// print data
void printData(int* data, int size) {
    for (int i = 0; i < size; ++i) {
        cout << "  " << data[i];
    }
    cout << endl;
}


// Function to get the largest element from an array
int getMax(int* data, int n) {
    int max = data[0];
    for (int i = 1; i < n; i++)
        if (data[i] > max)
            max = data[i];
    return max;
}

// Using counting sort to sort the elements in the basis of significant places
void countingSort(int* data, int size, int place) {
    int* output = new int[size];
    int count[10] = {0};

    // Calculate count of elements
    for (int i = 0; i < size; i++)
        count[(data[i] / place) % 10]++;

    // Calculate cumulative count
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Place the elements in sorted order
    for (int i = size - 1; i >= 0; i--) {
        output[count[(data[i] / place) % 10] - 1] = data[i];
        count[(data[i] / place) % 10]--;
    }

    for (int i = 0; i < size; i++)
        data[i] = output[i];
}

// Main function to implement radix sort
void radixsort(int* data, int size) {
    // Get maximum element
    int max = getMax(data, size);

    // Apply counting sort to sort elements based on place value.
    for (int place = 1; max / place > 0; place *= 10)
        countingSort(data, size, place);
}

// How it work: create dynamic array -> radixsort