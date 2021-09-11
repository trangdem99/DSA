// Bubble sort in C++ code with love and passion by H.T.Nguyên
#include <iostream>

using namespace std;

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

int main() {
    int size;
    cout << "Input size: "; cin >> size;

    int* data = new int[size];

    for (int i = 0; i < size; i++) {
        cout << "Input element number " << i + 1 << " : ";
        cin >> data[i];
    }

    // Normal bubble sort
    //bubbleSort(data, size);

    // Optimized bubble sort
    //optimizedBubbleSort(data, size);

    cout << "Sorted Array in Ascending Order:" << endl;

    printData(data, size);

    return 0;
}