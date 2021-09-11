#include <iostream>

using namespace std;

void flip(int* data, int size)
{
    for (int i = 0; i < size; i++, size--) {
        int temp = data[i];
        data[i] = data[size];
        data[size] = temp;
    }
}

// Returns index of the maximum element in arr[0..n-1]  
int findMax(int* data, int size)
{
    int max_i = 0;
    for (int i = 0; i < size; ++i)
        if (data[i] > data[max_i])
            max_i = i;
    return max_i;
}

// The main function that sorts given array using flip operations 
void pancakeSort(int* data, int size)
{
    for (int curr_size = size; curr_size > 1; --curr_size)
    {
        // Find index of the maximum element in arr[0..curr_size-1] 
        int max_i = findMax(data, curr_size);

        //Move the maximum element to end of current array if it's not already at the end 
        if (max_i != curr_size - 1)
        {
            //To move at the end, first move maximum number to beginning  
            flip(data, max_i);

            // Now move the maximum number to end by reversing current array 
            flip(data, curr_size - 1);
        }
    }
}

// A utility function to print n array of size n  
void printData(int* data, int n)
{
    for (int i = 0; i < n; ++i)
        cout << data[i] << " ";
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

    pancakeSort(data, size);

    cout << "Sorted Array in Ascending Order:" << endl;

    printData(data, size);

    return 0;
}