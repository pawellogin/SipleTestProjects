#include <iostream>
#include <windows.h>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;

	Node() {
		data = 0;
		left = NULL;
		right = NULL;
	}
};



Node* insert(Node* root,int value) {
	if (root == NULL) {
		root = new Node;
		root->data = value;
		return root;
	}

	else {
		if (value < root->data) {
			if(root->left==NULL){
				root->left = new Node;
				root->left->data = value;
			}
			else insert(root->left,value);
		}

		if (value > root->data) {
			if (root->right == NULL) {
				root->right = new Node;
				root->right->data = value;
			}
			else insert(root->right, value);
		}
	}
}

void InOrder(Node* root) {

	if (root->left != NULL) {
		InOrder(root->left);
	}

	if (root->data != NULL) {
		cout << root->data<<" ";
	}

	if (root->right != NULL) {
		InOrder(root->right);
	}
}

bool IsPresent(Node* root, int value) {
	if (root->left != NULL) {
		if (IsPresent(root->left, value)) {
			return 1;
		}
	}

	if (root->data == value ) {
		return 1;
	}

	if (root->right != NULL) {
		if (IsPresent(root->right, value)) {
			return 1;
		}
	}

	return 0;
}

int menu(Node* root) {
	int value=0;
	InOrder(root);
	cout << endl;
	cout << "1. insert a number"<<endl;
	cout << "2. is a number present" << endl;
	cin >> value;
	return value;
}

int main() {
	int choice = 0;
	int value = 0;
	Node* root = NULL;

	cout << "enter a root of a tree"<<endl;
	cin >> value;
	root=insert(root,value);
	system("cls");
	
	

	while (1) {
		
		choice=menu(root);
		system("cls");

		switch (choice) {
		case 1: 
			cout << "enter a number : ";
			cin >> value;
			insert(root, value); system("cls"); break;
		case 2:
			cout << "enter a number : ";
			cin >> value;
			system("cls");
			cout << IsPresent(root, value); Sleep(2000);
			system("cls"); break;
		case 3: break;
		case 4: return 0; break;
		}

	}
	

	return 0;
}