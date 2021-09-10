// Red Black Tree in C++ code with love and passion by H.T.Nguyên
#include <iostream>

using namespace std;

struct Node {
	int key;
	int color;
	Node* p_Parent;
	Node* p_Left;
	Node* p_Right;
};

Node* createNode(int key) {
	Node* temp = new Node;
	temp->key = key;
	temp->color = 1;
	temp->p_Parent = nullptr;
	temp->p_Left = nullptr;
	temp->p_Right = nullptr;
	return temp;
}

Node* searchNode(Node* root, int key) {
	if (root == nullptr)
		return nullptr;
	if (root->key == key)
		return root;
	if (root->key > key)
		return searchNode(root->p_Left, key);
	else
		return searchNode(root->p_Right, key);
}

Node* minimumNode(Node* root) {
	return (root->p_Left == nullptr) ? root : minimumNode(root->p_Left);
}

void leftRotate(Node*& root, Node* main) {
	Node* temp = main->p_Right;
	main->p_Right = temp->p_Left;

	if (temp->p_Left != nullptr)
		temp->p_Left->p_Parent = main;

	temp->p_Parent = main->p_Parent;

	if (main->p_Parent == nullptr)
		root = temp;
	else if (main == main->p_Parent->p_Left)
		main->p_Parent->p_Left = temp;
	else
		main->p_Parent->p_Right = temp;

	temp->p_Left = main;
	main->p_Parent = temp;
}

void rightRotate(Node*& root, Node* main) {
	Node* temp = main->p_Left;
	main->p_Left = temp->p_Right;

	if (temp->p_Right != nullptr)
		temp->p_Right->p_Parent = main;

	temp->p_Parent = main->p_Parent;

	if (main->p_Parent == nullptr)
		root = temp;
	else if (main == main->p_Parent->p_Right)
		main->p_Parent->p_Right = temp;
	else
		main->p_Parent->p_Left = temp;

	temp->p_Right = main;
	main->p_Parent = temp;
}

void insertFix(Node*& root, Node* main) {
	while (main->p_Parent->color == 1) {
		if (main->p_Parent == main->p_Parent->p_Parent->p_Right) {
			Node* temp = main->p_Parent->p_Parent->p_Left;

			if (temp == nullptr)
				return;

			if (temp->color == 1) {
				temp->color = 0;
				main->p_Parent->color = 0;
				main->p_Parent->p_Parent->color = 1;
				main = main->p_Parent->p_Parent;
			}
			else {
				if (main == main->p_Parent->p_Left) {
					main = main->p_Parent;
					rightRotate(root, main);
				}

				main->p_Parent->color = 0;
				main->p_Parent->p_Parent->color = 1;
				leftRotate(root, main->p_Parent->p_Parent);
			}
		}
		else {
			Node* temp = main->p_Parent->p_Parent->p_Right;

			if (temp == nullptr)
				return;

			if (temp->color == 1) {
				temp->color = 0;
				main->p_Parent->color = 0;
				main->p_Parent->p_Parent->color = 1;
				main = main->p_Parent->p_Parent;
			}
			else {
				if (main == main->p_Parent->p_Right) {
					main = main->p_Parent;
					leftRotate(root, main);
				}

				main->p_Parent->color = 0;
				main->p_Parent->p_Parent->color = 1;
				rightRotate(root, main->p_Parent->p_Parent);
			}
		}
		if (main == root)
			break;
	}
	root->color = 0;
}

void insertNode(Node*& root, int key) {
	Node* newNode = createNode(key);
	Node* y = nullptr;
	Node* x = root;

	// Find the suitable position to insert the new Node
	while (x != nullptr) {
		y = x;
		if (newNode->key < x->key)
			x = x->p_Left;
		else
			x = x->p_Right;
	}

	newNode->p_Parent = y; // Mark parent of new node to the chosen node

	// Put the new node to the correct poistion
	if (y == nullptr)
		root = newNode;
	else if (newNode->key < y->key)
		y->p_Left = newNode;
	else
		y->p_Right = newNode;

	// Check if the new node is root node or not
	if (newNode->p_Parent == nullptr) {
		newNode->color = 0;
		return;
	}

	// Check if the new node is child of root node or not
	if (newNode->p_Parent->p_Parent == nullptr)
		return;

	insertFix(root, newNode);
	cout << "Insert success" << endl;
}

void rbTransplant(Node*& root, Node* p, Node* q) {
	if (p->p_Parent == nullptr)
		root = q;
	else if (p == p->p_Parent->p_Left)
		p->p_Parent->p_Left = q;
	else
		p->p_Parent = q->p_Parent;
}

void deleteFix(Node*& root, Node* main) {
	while (main != root && main->color == 0) {
		if (main == main->p_Parent->p_Left) {
			Node* temp = main->p_Parent->p_Right;

			if (temp->color == 1) {
				temp->color = 0;
				main->p_Parent->color = 1;
				leftRotate(root, main->p_Parent);
				temp = main->p_Parent->p_Right;
			}

			if (temp->p_Left->color == 0 && temp->p_Right->color == 0) {
				temp->color = 1;
				main = main->p_Parent;
			}
			else {
				if (temp->p_Right->color == 0) {
					temp->p_Left->color = 0;
					temp->color = 1;
					rightRotate(root, temp);
					temp = main->p_Parent->p_Right;
				}

				temp->color = main->p_Parent->color;
				main->p_Parent->color = 0;
				temp->p_Right->color = 0;
				leftRotate(root, main->p_Parent);
				main = root; 
			}
		}
		else {
			Node* temp = main->p_Parent->p_Left;
			
			if (temp->color == 1) {
				temp->color = 0;
				main->p_Parent->color = 1;
				rightRotate(root, main->p_Parent);
				temp = main->p_Parent->p_Left;
			}

			if (temp->p_Right->color == 0 && temp->p_Left->color == 0) {
				temp->color = 1;
				main = main->p_Parent;
			}
			else {
				if (temp->p_Left->color == 0) {
					temp->p_Right->color = 0;
					temp->color = 1;
					leftRotate(root, temp);
					temp = main->p_Parent->p_Left;
				}

				temp->color = main->p_Parent->color;
				main->p_Parent->color = 0;
				temp->p_Left->color = 0;
				rightRotate(root, main->p_Parent);
				main = root;
			}
		}
	}
	main->color = 0;
}

void deleteNode(Node*& root, int key) {
	Node* z = nullptr; // The seleceted node
	Node* main, * temp;
	Node* p = root;
	while (p != nullptr)
		if (p->key == key)
			z = p;
		else if (p->key <= key)
			p = p->p_Right;
		else
			p = p->p_Left;

	if (z == nullptr) {
		cout << "Cannot find your key in the tree." << endl;
		return;
	}

	temp = z;
	int orginal_color = temp->color;
	if (z->p_Left == nullptr) {
		main = z->p_Right;
		rbTransplant(root, z, z->p_Right);
	}
	else if (z->p_Right == nullptr) {
		main = z->p_Left;
		rbTransplant(root, z, z->p_Left);
	}
	else {
		temp = minimumNode(z->p_Right);
		orginal_color = temp->color;
		main = temp->p_Right;
		if (temp->p_Parent == z)
			main->p_Parent = temp;
		else {
			rbTransplant(root, temp, temp->p_Right);
			temp->p_Right = z->p_Right;
			temp->p_Right->p_Parent = temp;
		}
		rbTransplant(root, z, temp);
		temp->p_Left = z->p_Left;
		temp->p_Left->p_Parent = temp;
		temp->color = z->color;
	}
	delete z;
	if (orginal_color == 0) {
		deleteFix(root, main);
	}
	cout << "Delete success" << endl;
}

void printTree(Node*& root) {
	if (root != nullptr) {
		printTree(root->p_Left);
		cout << root->key << " - " << root->color << endl;
		printTree(root->p_Right);
	}
}

int main() {
	Node* root = new Node{};
	while (true) {
		int Mode;

		system("cls");
		cout << "Welcome to Red Black Tree Implementation !!!" << endl;
		cout << "1. Insert a node" << endl;
		cout << "2. Delete a node" << endl;
		cout << "3. Search a node" << endl;
		cout << "4. Show the tree" << endl;
		cout << "0. Exit program " << endl;
		cout << "Choose your mode: "; 
		cin >> Mode;
		system("cls");

		if (Mode == 0)
			break;
		else if (Mode == 4)
			printTree(root);
		else {
			int key;
			cout << "Enter your key you want: "; 
			cin >> key;
			system("cls");

			if (Mode == 1)
				insertNode(root, key);
			else if (Mode == 2)
				deleteNode(root, key);
			else
				if (searchNode(root, key) != nullptr)
					cout << "Found your key in the tree" << endl;
				else
					cout << "Cannot find your key in the tree" << endl;
		}

		system("pause");
		system("cls");
	}

	cout << "Exiting..." << endl;
	return 0;
}
