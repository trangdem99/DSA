// Tim sort in C++ code with love and passion by H.T.Nguyên
#include<iostream>

using namespace std;

const int _SIZE_ = 64;

void insertionSort(int arr[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void merge(int* data, int first, int mid, int last) {
    int* temp = new int[last - first + 1];
    int first1 = first, last1 = mid;
    int first2 = mid + 1, last2 = last;
    int cur = 0;

    // Until we reach either end of either last1 or last2, pick larger among elements first1 and first2 and place them in the correct position
    while ((first1 <= last1) && (first2 <= last2)) {
        if (data[first1] <= data[first2]) {
            temp[cur] = data[first1];
            first1++;
        }
        else {
            temp[cur] = data[first2];
            first2++;
        }
        cur++;
    }

    // Pick up the remaining elements and put in remaining position in sorted array
    while (first1 <= last1) {
        temp[cur] = data[first1];
        first1++;
        cur++;
    }

    // Pick up the remaining elements and put in remaining position in sorted array
    while (first2 <= last2) {
        temp[cur] = data[first2];
        first2++;
        cur++;
    }

    // Transfer back to the main arrray
    for (int i = 0; i < cur; i++)
        data[i + first] = temp[i];

}

void timSort(int* data, int size) {
    // Sort individual subarrays of size _SIZE_
    for (int i = 0; i < size; i += _SIZE_)
        insertionSort(data, i, min((i + _SIZE_ - 1), (size - 1)));

    // Merge sub array
    for (int i = _SIZE_; i < size; i = 2 * i) {
        for (int left = 0; left < size; left += 2 * i) {
            int mid = left + i - 1;
            int right = min((left + 2 * i - 1), (size - 1));

            if (mid < right)
                merge(data, left, mid, right);
        }
    }
}

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

    timSort(data, size);

    cout << endl << "The array after Sorting: ";

    printData(data, size);

    return 0;
}