// Radix sort for alphabet in C++ code with love and passion by H.T.Nguyên

#include <iostream>
#include <string>
using namespace std;

// print data
void printData(string* data, int size) {
	for (int i = 0; i < size; ++i) {
		cout << "  " << data[i];
	}
	cout << endl;
}

// Function to change alphabet to number (ASCII)
int chartToIndex(char a) {
	if (a >= 'a')
		return a - 'a' + 1;
	else
		return a - 'A' + 1;
}

// Function to get the largest element from list
int maxLength(string* name, int n) {
	int max = name[0].length();
	for (int i = 1; i < n; i++)
		if (name[i].length() > max)
			max = name[i].length();
	return max;
}

// Using counting sort to sort the elements in the basis of significant places
void countSort(string* name, int n, int pos) {
	string* output = new string[n];
	int count[27] = { 0 };
	
    // Calculate count of elements
	for (int i = 0; i < n; i++)
		if (name[i].length() > pos)
			count[chartToIndex(name[i][pos])]++;
		else
			count[0]++;

    // Calculate cumulative count
	for (int i = 1; i < 27; i++)
		count[i] += count[i - 1];

	// Place the elements in sorted order
	for (int i = n - 1; i >= 0; i--) {
		if (name[i].length() > pos){
			output[count[chartToIndex(name[i][pos])] - 1] = name[i];
			count[chartToIndex(name[i][pos])]--;
		}
		else {
			output[count[0] - 1] = name[i];
			count[0]--;
		}
	}
	
	for (int i = 0; i < n; i++)
		name[i] = output[i];
	
	delete[]output;
}

// Main function to implement radix sort
void radixSort(string* name, int n) {

    // Get maximum element
	int max = maxLength(name, n);

    // Apply counting sort to sort elements based on place value.
	for (int i = max - 1; i >= 0; i--)
		countSort(name, n, i);
}