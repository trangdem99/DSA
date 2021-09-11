// Heap sort in C++ code with love and passion by H.T.Nguyên
#include <iostream>

using namespace std;

// print data
void printData(int* data, int size) {
    for (int i = 0; i < size; ++i) {
        cout << "  " << data[i];
    }
    cout << endl;
}
// Function to swap 2 elements
void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void heapify(int* data, int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && data[left] > data[largest])
        largest = left;
  
    if (right < n && data[right] > data[largest])
        largest = right;
  
    // Swap and continue heapifying if root is not largest
    if (largest != i) {
        swap(data[i], data[largest]);
        heapify(data, n, largest);
    }
  }
  
// main function to do heap sort
void heapSort(int* data, int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(data, n, i);
  
    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
        swap(data[0], data[i]);
  
        // Heapify root element to get highest element at root again
        heapify(data, i, 0);
    }
}

int main() {
    cout << "Welcome to Heap Sort Implementation !!!" << endl;
    int size;
    cout << "Input size: "; cin >> size;

    int* data = new int[size];

    for (int i = 0; i < size; i++) {
        cout << "Input element number " << i + 1 << " : ";
        cin >> data[i];
    }

    heapSort(data, size);

    cout << "Sorted Array in Ascending Order:" << endl;

    printData(data, size);

    return 0;
}