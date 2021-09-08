// Red Black Tree in C++ code with love and passion by H.T.Nguyên
#include <iostream>
#include <string>

using namespace std;

struct Data {
	string word;
	string meaning;
};

struct Node {
	Data key;
	int color;
	Node* p_Parent;
	Node* p_Left;
	Node* p_Right;
};

Node* createNode(Data key) {
	Node* temp = new Node;
	temp->key = key;
	temp->color = 1;
	temp->p_Parent = nullptr;
	temp->p_Left = nullptr;
	temp->p_Right = nullptr;
	return temp;
}

Node* searchNode(Node* root, string word) {
	if (root == nullptr)
		return nullptr;
	if (root->key.word == word)
		return root;
	if (root->key.word > word)
		return searchNode(root->p_Left, word);
	else
		return searchNode(root->p_Right, word);
}

Node* minimumNode(Node* root) {
	return (root->p_Left == nullptr) ? root : minimumNode(root->p_Left);
}

void leftRotate(Node*& root, Node* x) {
	Node* y = x->p_Right;
	x->p_Right = y->p_Left;

	if (y->p_Left != nullptr)
		y->p_Left->p_Parent = x;

	y->p_Parent = x->p_Parent;

	if (x->p_Parent == nullptr)
		root = y;
	else if (x == x->p_Parent->p_Left)
		x->p_Parent->p_Left = y;
	else
		x->p_Parent->p_Right = y;

	y->p_Left = x;
	x->p_Parent = y;
}

void rightRotate(Node*& root, Node* x) {
	Node* y = x->p_Left;
	x->p_Left = y->p_Right;

	if (y->p_Right != nullptr)
		y->p_Right->p_Parent = x;

	y->p_Parent = x->p_Parent;

	if (x->p_Parent == nullptr)
		root = y;
	else if (x == x->p_Parent->p_Right)
		x->p_Parent->p_Right = y;
	else
		x->p_Parent->p_Left = y;

	y->p_Right = x;
	x->p_Parent = y;
}

void insertFix(Node*& root, Node* p) {
	Node* q;
	while (p->p_Parent->color == 1) {
		if (p->p_Parent == p->p_Parent->p_Parent->p_Right) {
			q = p->p_Parent->p_Parent->p_Left;

			if (q == nullptr)
				return;

			if (q->color == 1) {
				q->color = 0;
				p->p_Parent->color = 0;
				p->p_Parent->p_Parent->color = 1;
				p = p->p_Parent->p_Parent;
			}
			else {
				if (p == p->p_Parent->p_Left) {
					p = p->p_Parent;
					rightRotate(root, p);
				}

				p->p_Parent->color = 0;
				p->p_Parent->p_Parent->color = 1;
				leftRotate(root, p->p_Parent->p_Parent);
			}
		}
		else {
			q = p->p_Parent->p_Parent->p_Right;

			if (q == nullptr)
				return;

			if (q->color == 1) {
				q->color = 0;
				p->p_Parent->color = 0;
				p->p_Parent->p_Parent->color = 1;
				p = p->p_Parent->p_Parent;
			}
			else {
				if (p == p->p_Parent->p_Right) {
					p = p->p_Parent;
					leftRotate(root, p);
				}

				p->p_Parent->color = 0;
				p->p_Parent->p_Parent->color = 1;
				rightRotate(root, p->p_Parent->p_Parent);
			}
		}
		if (p == root)
			break;
	}
	root->color = 0;
}

void insertNode(Node*& root, Data key) {
	Node* temp = createNode(key);
	Node* y = nullptr;
	Node* x = root;

	// Find the suitable position to insert the new Node
	while (x != nullptr) {
		y = x;
		if (temp->key.word < x->key.word)
			x = x->p_Left;
		else
			x = x->p_Right;
	}

	temp->p_Parent = y; // Mark parent of new node to the chosen node

	// Put the new node to the correct poistion
	if (y == nullptr)
		root = temp;
	else if (temp->key.word < y->key.word)
		y->p_Left = temp;
	else
		y->p_Right = temp;


	if (temp->p_Parent == nullptr) {
		temp->color = 0;
		return;
	}

	if (temp->p_Parent->p_Parent == nullptr)
		return;

	insertFix(root, temp);
}

void rbTransplant(Node*& root, Node* p, Node* q) {
	if (p->p_Parent == nullptr)
		root = q;
	else if (p == p->p_Parent->p_Left)
		p->p_Parent->p_Left = q;
	else
		p->p_Parent = q->p_Parent;
}

void deleteFix(Node*& root, Node* p) {
	Node* q;
	while (p != root && p->color == 0) {
		if (p == p->p_Parent->p_Left) {
			q = p->p_Parent->p_Right;
			if (q->color == 1) {
				q->color = 0;
				p->p_Parent->color = 1;
				leftRotate(root, p->p_Parent);
				q = p->p_Parent->p_Right;
			}

			if (q->p_Left->color == 0 && q->p_Right->color == 0) {
				q->color = 1;
				p = p->p_Parent;
			}
			else {
				if (q->p_Right->color == 0) {
					q->p_Left->color = 0;
					q->color = 1;
					rightRotate(root, q);
					q = p->p_Parent->p_Right;
				}

				q->color = p->p_Parent->color;
				p->p_Parent->color = 0;
				q->p_Right->color = 0;
				leftRotate(root, p->p_Parent);
				p = root;
			}
		}
		else {
			q = p->p_Parent->p_Left;
			if (q->color == 1) {
				q->color = 0;
				p->p_Parent->color = 1;
				leftRotate(root, p->p_Parent);
				q = p->p_Parent->p_Left;
			}

			if (q->p_Right->color == 0 && q->p_Left->color == 0) {
				q->color = 1;
				p = p->p_Parent;
			}
			else {
				if (q->p_Left->color == 0) {
					q->p_Right->color = 0;
					q->color = 1;
					leftRotate(root, q);
					q = p->p_Parent->p_Left;
				}

				q->color = p->p_Parent->color;
				p->p_Parent->color = 0;
				q->p_Left->color = 0;
				rightRotate(root, p->p_Parent);
				p = root;
			}
		}
	}
	p->color = 0;
}

bool deleteNode(Node*& root, string word) {
	Node* z = nullptr;
	Node* x, * y;
	Node* p = root;
	while (p != nullptr)
		if (p->key.word == word)
			z = p;
		else if (p->key.word <= word)
			p = p->p_Right;
		else
			p = p->p_Left;

	if (z == nullptr)
		return false;

	y = z;
	int orginal_color = y->color;
	if (z->p_Left == nullptr) {
		x = z->p_Right;
		rbTransplant(root, z, z->p_Right);
	}
	else if (z->p_Right == nullptr) {
		x = z->p_Left;
		rbTransplant(root, z, z->p_Left);
	}
	else {
		y = minimumNode(z->p_Right);
		orginal_color = y->color;
		x = y->p_Right;
		if (y->p_Parent == z)
			x->p_Parent = y;
		else {
			rbTransplant(root, y, y->p_Right);
			y->p_Right = z->p_Right;
			y->p_Right->p_Parent = y;
		}
		rbTransplant(root, z, y);
		y->p_Left = z->p_Left;
		y->p_Left->p_Parent = y;
		y->color = z->color;
	}
	delete z;
	if (orginal_color == 0) {
		deleteFix(root, x);
	}
}

// How it work: create node root -> insertNode / deleteNode