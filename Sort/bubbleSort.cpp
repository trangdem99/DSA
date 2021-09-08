// Bubble sort in C++ code with love and passion by H.T.Nguyên

#include <iostream>
using namespace std;

// perform bubble sort
void bubbleSort(int *data, int size) {

    // loop to access each array element
    for (int i = 0; i < (size - 1); i++) {
      
        // loop to compare array elements
        for (int j = 0; j < size - i - 1; j++) {

            // compare two adjacent elements change > to < to sort in descending order
            if (data[j] > data[j + 1]) {

                // swapping elements if elements are not in the intended order
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
    }
  }
}

// perform bubble sort
void optimizedBubbleSort(int *data, int size) {

    // loop to access each array element
    for (int i = 0; i < (size - 1); i++) {
    
        // check if swapping occurs
        int swapped = 0;

        // loop to compare array elements
        for (int j = 0; j < size - i - 1; j++) {

            // compare two adjacent elements change > to < to sort in descending order
            if (data[j] > data[j + 1]) {

                // swapping elements if elements are not in the intended order
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;

                swapped = 1;
            }
        }

        // No swapping means the array is already sorted so no need of further comparison
        if (swapped == 0)
            break;
    }
}

// print data
void printData(int* data, int size) {
    for (int i = 0; i < size; ++i) {
        cout << "  " << data[i];
    }
    cout << endl;
}

// How it work: create dynamic array -> bubbleSort / optimizedBubbleSort