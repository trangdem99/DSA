// Balance Binary Search Tree in C++ code with love and passion by H.T.Nguyên
#include <iostream>
#include <string>

using namespace std;

struct Data {
	string word;
	string meaning;
};

struct Node {
	Data key;
	int height;
	Node* p_Left;
	Node* p_Right;
};

int max(int a, int b) {
	return (a > b) ? a : b;
}

int height(Node* p) {
	return (p == NULL) ? 0 : p->height;
}

int getBalanceFactor(Node* root) {
	return (root == NULL) ? 0 : (height(root->p_Left) - height(root->p_Right));
}

Node* newNode(string word, string meaning) {
	Node* temp = new Node;
	temp->key.word = word;
	temp->key.meaning = meaning;
	temp->height = 1;
	temp->p_Left = temp->p_Right = NULL;
	return temp;
}

Node* leftRotate(Node* root) {
	Node* right = root->p_Right;
	Node* temp = right->p_Left;
	right->p_Left = root;
	root->p_Right = temp;
	root->height = max(height(root->p_Left), height(root->p_Right)) + 1;
	right->height = max(height(right->p_Left), height(right->p_Right)) + 1;

	return right;
}

Node* rightRotate(Node* root) {
	Node* left = root->p_Left;
	Node* temp = left->p_Right;
	left->p_Right = root;
	root->p_Left = temp;
	root->height = max(height(root->p_Left), height(root->p_Right)) + 1;
	left->height = max(height(left->p_Left), height(left->p_Right)) + 1;

	return left;
}

Node* insertNode(Node* root, string word, string meaning) {
	if (root == NULL)
		return newNode(word, meaning);
	if (word < root->key.word)
		root->p_Left = insertNode(root->p_Left, word, meaning);
	else if (word > root->key.word)
		root->p_Right = insertNode(root->p_Right, word, meaning);
	else
		return root;

	// Rebalance
	root->height = 1 + max(height(root->p_Left), height(root->p_Right));

	int balance = getBalanceFactor(root);

	// Left height > Right height
	if (balance > 1)
		if (word < root->p_Left->key.word)
			return rightRotate(root);
		else if (word > root->p_Left->key.word) {
			root->p_Left = leftRotate(root->p_Left);
			return rightRotate(root);
		}

	// Left height < Right height
	if (balance < -1)
		if (word > root->p_Right->key.word)
			return leftRotate(root);
		else if (word < root->p_Right->key.word) {
			root->p_Right = rightRotate(root->p_Right);
			return leftRotate(root);
		}
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

	if (root == NULL)
		return root;

	// Rebalance
	root->height = 1 + max(height(root->p_Left), height(root->p_Right));

	int balance = getBalanceFactor(root);

	// Left height > Right height
	if (balance > 1)
		if (word < root->p_Left->key.word)
			return rightRotate(root);
		else if (word > root->p_Left->key.word) {
			root->p_Left = leftRotate(root->p_Left);
			return rightRotate(root);
		}

	// Left height < Right height
	if (balance < -1)
		if (word > root->p_Right->key.word)
			return leftRotate(root);
		else if (word < root->p_Right->key.word) {
			root->p_Right = rightRotate(root->p_Right);
			return leftRotate(root);
		}
	return root;
}

bool checkEmpty(Node* root) {
	return (root == NULL) ? false : true;
}

// How it work: create node root -> insertNode / deleteNode