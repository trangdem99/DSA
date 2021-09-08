// Binary Search Tree in C++ code with love and passion by H.T.Nguyên
#include <iostream>
#include <string>

using namespace std;

struct Data_BST {
	string word;
	string meaning;
};

struct Node_BST {
	Data_BST key;
	Node_BST* p_Left;
	Node_BST* p_Right;
};

Node_BST* newNode_BST(string word, string meaning) {
	Node_BST* temp = new Node_BST;
	if (temp == NULL) {
		cout << "No memory left" << endl;
		return NULL;
	}
	temp->key.word = word;
	temp->key.meaning = meaning;
	temp->p_Left = temp->p_Right = NULL;
	return temp;
}

Node_BST* insertNode_BST(Node_BST* root, string word, string meaning) {
	if (root == NULL)
		return newNode_BST(word, meaning);
	if (root->key.word > word)
		root->p_Left = insertNode_BST(root->p_Left, word, meaning);
	else
		root->p_Right = insertNode_BST(root->p_Right, word, meaning);

	return root;
}

Node_BST* findMinNode_BST(Node_BST* root) {
	Node_BST* p = root;
	while (p && p->p_Left != NULL)
		p = p->p_Left;
	return p;
}

Node_BST* deleteNode_BST(Node_BST* root, string word) {
	if (root == NULL)
		return root;

	if (root->key.word > word)
		root->p_Left = deleteNode_BST(root->p_Left, word);
	else if (root->key.word < word)
		root->p_Right = deleteNode_BST(root->p_Right, word);
	else {
		if (root->p_Left == NULL) {
			Node_BST* temp = root->p_Right;
			free(root);
			return temp;
		}
		else if (root->p_Right == NULL) {
			Node_BST* temp = root->p_Left;
			free(root);
			return temp;
		}

		Node_BST* p = findMinNode_BST(root->p_Right);
		root->key = p->key;

		root->p_Right = deleteNode_BST(root->p_Right, p->key.word);
	}

	return root;
}