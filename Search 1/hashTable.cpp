// Hash Table in C++ code with love and passion by H.T.Nguyên
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

Node* hashTable[_SIZE_]{ nullptr };

int hashFunc(string s) {
	return (int)s[0];
}


void setHashTable() {
	for (int i = 0; i < _SIZE_; i++)
		hashTable[i] = NULL;
}

void pushBack(Node*& p, key x) {
	if (p == NULL)
		p = new Node{ x, NULL };
	else {
		Node* l = p;
		Node* temp = new Node{ x, NULL };

		if (temp == NULL) {
			cout << "Out of memory" << endl;
			return;
		}

		while (l != NULL && l->p_Next != NULL)
			l = l->p_Next;
		l->p_Next = temp;
	}
}

void showListNode(Node* p) {
	while (p != NULL) {
		cout << "     " << p->data.word << " " << p->data.meaning << endl;
		p = p->p_Next;
	}
}

void searchKey() {
	string s;
	cout << "Insert the word you want to look up: "; getline(cin >> ws, s);

	int k = hashFunc(s);

	if (hashTable[k] == NULL) {
		cout << "Cannot find word" << endl;
		return;
	}

	Node* temp = hashTable[k];

	while (temp != NULL) {
		if (temp->data.word == s) {
			cout << "The meaning of the word is: " << temp->data.meaning << endl;
			return;
		}
		temp = temp->p_Next;
	}

	cout << "Cannot find word" << endl;
}

void addKey() {
	key s;
	cout << "Insert the word you want to add: "; getline(cin >> ws, s.word);
	cout << "Insert the meaning of the word you want to add: "; getline(cin >> ws, s.meaning);
	cout << endl;

	int k = hashFunc(s.word);
	Node* p = hashTable[k];

	while (p != NULL) {
		if (p->data.word == s.word) {
			cout << "Word is already existed" << endl;
			return;
		}
		p = p->p_Next;
	}

	pushBack(hashTable[k], s);
	cout << "Adding successfully" << endl;
}

void deleteKey() {
	string s;
	cout << "Insert the word you want to delete: "; getline(cin >> ws, s);
	cout << endl;

	int k = hashFunc(s);
	if (hashTable[k] == NULL) {
		cout << "Cannot find word" << endl;
		return;
	}

	Node* p = hashTable[k];

	int flag = 0;

	while (p->p_Next != NULL) {
		if (p->data.word == s) {
			Node* temp = p->p_Next;
			p->p_Next = temp->p_Next;
			delete temp;
			cout << "Delete successfully" << endl;
			return;
		}

		if (p->p_Next->data.word == s) {
			Node* temp = p->p_Next;
			p->p_Next = temp->p_Next->p_Next;
			delete temp;
			cout << "Delete successfully" << endl;
			return;
		}

		p = p->p_Next;
	}

	cout << "Cannot find word" << endl;
}

void showHashTable() {
	for (int i = 0; i < _SIZE_; i++) {
		cout << "Table " << i << " : " << endl;
		Node* p = hashTable[i];
		showListNode(p);
	}
}

int main() {
	setHashTable();
	while (true) {
		int Mode;

		system("cls");
		cout << "Welcome to Hash Table Implementation !!!" << endl;
		cout << "1. Insert a key" << endl;
		cout << "2. Delete a key" << endl;
		cout << "3. Search a key" << endl;
		cout << "4. Show table" << endl;
		cout << "0. Exit program " << endl;
		cout << "Choose your mode: ";
		cin >> Mode;
		system("cls");

		if (Mode == 0)
			break;
		else if (Mode == 4)
			if (hashTable != nullptr)
				showHashTable();
			else
				cout << "Tree is empty" << endl;
		else {
			int key;
			cout << "Enter your key you want: ";
			cin >> key;
			system("cls");

			if (Mode == 1)
				addKey();
			else if (Mode == 2)
				deleteKey();
			else
				searchKey();
		}

		system("pause");
		system("cls");
	}

	cout << "Exiting..." << endl;
	return 0;
}