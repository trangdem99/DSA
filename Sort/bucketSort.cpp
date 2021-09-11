// Bucket Sort in C++ code with love and passion by H.T.Nguyên
#include <iostream>

using namespace std;
#define numBuckets 5 // Number of buckets
#define capBuckets 10  // Each bucket capacity

struct Node {
    int data;
    Node* p_Next;
};

Node* insertionSort(Node* list) {
    if (list == 0 || list->p_Next == 0)
        return list;

    Node* nodeList = list;
    Node* k = list->p_Next;
    nodeList->p_Next = nullptr;

    while (k != nullptr) {
        if (nodeList->data > k->data) {
            Node* temp = k;
            k = k->p_Next;
            temp->p_Next = nodeList;
            nodeList = temp;
            continue;
        }

        Node* p = nodeList;

        while (p->p_Next != nullptr)
            if (p->p_Next->data > k->data)
                break;
            else
                p = p->p_Next;

        if (p->p_Next != nullptr) {
            Node* temp = k;
            k = k->p_Next;
            temp->p_Next = p->p_Next;
            p->p_Next = temp;
            continue;
        }
        else {
            p->p_Next = k;
            k = k->p_Next;
            p->p_Next->p_Next = nullptr;
            continue;
        }
    }
    return nodeList;
}

// Print buckets
void printBucket(Node* list) {
    Node* temp = list;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->p_Next;
    }
    cout << endl;
}

void printBuckets(Node** buckets) {
    cout << "-------------" << endl;
    cout << "Bucktets after sorting: " << endl;
    for (int i = 0; i < numBuckets; i++) {
        cout << "Bucket " << i << " : " << endl;
        printBucket(buckets[i]);
        cout << endl;
    }
}

void printData(int* data, int size) {
    for (int i = 0; i < size; ++i) {
        cout << "  " << data[i];
    }
    cout << endl;
}

void BucketSort(int* data, int size) {
    // Create buckets and allocate memory size
    Node** buckets = new Node * [numBuckets];

    for (int i = 0; i < size; i++)
        buckets[i] = nullptr;

    // Fill the buckets with respective elements
    for (int i = 0; i < size; i++) {
        int pos = data[i] / capBuckets;
        struct Node* current = new Node{ data[i], buckets[pos] };
        buckets[pos] = current;
    }

    // Sort the elements of each bucket
    for (int i = 0; i < numBuckets; ++i)
        buckets[i] = insertionSort(buckets[i]);

    // Put sorted elements on array
    for (int j = 0, i = 0; i < numBuckets; ++i) {
        Node* temp = buckets[i];
        while (temp) {
            data[j++] = temp->data;
            temp = temp->p_Next;
        }
    }
}

int main() {
    cout << "Welcome to Bucket Sort Implementation !!!" << endl;
    int size;
    cout << "Input size: "; cin >> size;

    int* data = new int[size];

    for (int i = 0; i < size; i++) {
        cout << "Input element number " << i + 1 << " : ";
        cin >> data[i];
    }

    BucketSort(data, size);

    cout << "Sorted Array in Ascending Order:" << endl;

    printData(data, size);

    return 0;
}