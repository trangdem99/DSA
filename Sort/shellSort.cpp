// Shell sort in C++ code with love and passion by H.T.Nguyên

#include <iostream>
using namespace std;

// print data
void printData(int* data, int size) {
  for (int i = 0; i < size; ++i) {
    cout << "  " << data[i];
  }
  cout << endl;
}

// Shell sort
void shellSort(int* data, int n) {
  // Rearrange elements at each n/2, n/4, n/8, ... intervals
  for (int interval = n / 2; interval > 0; interval /= 2) {
    for (int i = interval; i < n; i += 1) {
      int temp = data[i];
      int j;
      for (j = i; j >= interval && data[j - interval] > temp; j -= interval) {
        data[j] = data[j - interval];
      }
      data[j] = temp;
    }
  }
}

int main() {
  int size;
  cout << "Input size: "; cin >> size;

  int *data = new int[size];
  
  for (int i = 0; i < size; i++){
    cout << "Input element number " << i + 1 << " : ";
    cin >> data[i];
  }

  shellSort(data, size);

  cout << "Sorted Array in Ascending Order:" << endl;

  printData(data, size);

  return 0;
}