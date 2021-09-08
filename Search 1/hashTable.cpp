#include <iostream>
#include <string>

using namespace std;

struct key {
	string word = "";
	string meaning = "";
};

struct Node {
	key data;
	Node* p_Next;
};

#define _SIZE_ 256 // ASCII Extended number - Size is customized number

Node* hashTable[_SIZE_];

int hashFunc(string s) {
	return (int)s[0];
}

void pushBack(Node*& p, key x) {
	if (p == NULL)
		p = new Node{ x, NULL };
	else {
		Node* l = p;
		Node* temp = new Node{ x, NULL }; \

			if (temp == NULL) {
				cout << "Out of memory" << endl;
				return;
			}

		while (l != NULL && l->p_Next != NULL)
			l = l->p_Next;
		l->p_Next = temp;
	}
}

void setHashTable() {
	for (int i = 0; i < _SIZE_; i++)
		hashTable[i] = NULL;
}

void showListNode(Node* p) {
	while (p != NULL) {
		cout << "     " << p->data.word << " " << p->data.meaning << endl;
		p = p->p_Next;
	}
}

void showHashTable() {
	for (int i = 0; i < _SIZE_; i++) {
		cout << "Table " << i << " : " << endl;
		Node* p = hashTable[i];
		showListNode(p);
	}
}

// Rule push back: 
/*
	int k = hashFunc(l.word); // l.word ->key
	pushBack(hashTable[k], l); 
*/