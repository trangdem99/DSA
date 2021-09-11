// Couting sort in C++ code with love and passion by H.T.Nguyên
#include <iostream>
#include <string>

using namespace std;

void countingSort(int* data, int size) {
    int* output = new int[size];
    int max = data[0];
    int min = data[0];
    int i;

    for (i = 1; i < size; i++) {
        if (data[i] > max)
            max = data[i];
        else if (data[i] < min)
            min = data[i];
    }

    int k = max - min + 1;
    int* count_array = new int[k];

    for (i = 0; i < k; i++)
        count_array[i] = 0;

    for (i = 0; i < size; i++)
        count_array[data[i] - min]++;


    for (i = 1; i < k; i++)
        count_array[i] += count_array[i - 1];

    for (i = 0; i < size; i++) {
        output[count_array[data[i] - min] - 1] = data[i];
        count_array[data[i] - min]--;
    }

    for (i = 0; i < size; i++)
        data[i] = output[i];

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

    countingSort(data, size);

    cout << "Sorted Array in Ascending Order:" << endl;

    printData(data, size);

    return 0;
}