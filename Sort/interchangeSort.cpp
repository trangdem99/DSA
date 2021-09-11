// Interchange sort in C++ code with love and passion by H.T.Nguyên
#include <iostream>

using namespace std;

// print data
void printData(int* data, int size) {
    for (int i = 0; i < size; ++i) {
        cout << "  " << data[i];
    }
    cout << endl;
}

void interchangeSort(int* data, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (data[j] < data[i])
                swap(data[j], data[i]);
}

int main() {
    cout << "Welcome to Interchange Sort Implementation !!!" << endl;
    int size;
    cout << "Input size: "; cin >> size;

    int* data = new int[size];

    for (int i = 0; i < size; i++) {
        cout << "Input element number " << i + 1 << " : ";
        cin >> data[i];
    }

    interchangeSort(data, size);
    cout << "Sorted array in Acsending Order:\n";
    printData(data, size);
}