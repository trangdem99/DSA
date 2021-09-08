// Binary Search Tree in C++ code with love and passion by H.T.Nguyên
#include <iostream>
#include <string>

using namespace std;

struct Data {
	string word;
	string meaning;
};

struct Node {
	Data key;
	Node* p_Left;
	Node* p_Right;
};

Node* newNode(string word, string meaning) {
	Node* temp = new Node;
	if (temp == NULL) {
		cout << "No memory left" << endl;
		return NULL;
	}
	temp->key.word = word;
	temp->key.meaning = meaning;
	temp->p_Left = temp->p_Right = NULL;
	return temp;
}

Node* insertNode(Node* root, string word, string meaning) {
	if (root == NULL)
		return newNode(word, meaning);
	if (root->key.word > word)
		root->p_Left = insertNode(root->p_Left, word, meaning);
	else
		root->p_Right = insertNode(root->p_Right, word, meaning);

	return root;
}

Node* findMinNode(Node* root) {
	Node* p = root;
	while (p && p->p_Left != NULL)
		p = p->p_Left;
	return p;
}

Node* deleteNode(Node* root, string word) {
	if (root == NULL)
		return root;

	if (root->key.word > word)
		root->p_Left = deleteNode(root->p_Left, word);
	else if (root->key.word < word)
		root->p_Right = deleteNode(root->p_Right, word);
	else {
		if (root->p_Left == NULL) {
			Node* temp = root->p_Right;
			free(root);
			return temp;
		}
		else if (root->p_Right == NULL) {
			Node* temp = root->p_Left;
			free(root);
			return temp;
		}

		Node* p = findMinNode(root->p_Right);
		root->key = p->key;

		root->p_Right = deleteNode(root->p_Right, p->key.word);
	}

	return root;
}

// How it work: create node root -> insertNode / deleteNode