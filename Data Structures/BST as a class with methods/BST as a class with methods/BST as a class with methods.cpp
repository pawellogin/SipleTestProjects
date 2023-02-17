#include <iostream>
#include <windows.h>

using namespace std;

class Node {
	int Data;
	Node* left;
	Node* right;

public:

	Node(int d = 30) {
		Data = d;
		left = NULL;
		right = NULL;
	}

	void insert(int value) {
		if (value < Data) {
			if (left == NULL) {
				left = new Node(value);
			}
			else {
				left->insert(value);
			}
		}
		else {
			if (right == NULL) {
				right = new Node(value);
			}
			else {
				right->insert(value);
			}
		}
	}

	void printInOrder() {
		if (left != NULL) {
			{
				left->printInOrder();
			}
		}

		cout << Data << ", ";

		if (right != NULL) {
			right->printInOrder();
		}

	}

	bool contains(int value) {
		if (Data == value) {
			return 1;
		}
		else if (value < Data) {
			if (left == NULL) {
				return 0;
			}
			else {
				return left->contains(value);
			}
		}
		else {
			if (right == NULL) {
				return 0;
			}
			else {
				return right->contains(value);
			}
		}
	}

	void deleteNode(int value) {
		return;
	}
};

int main() {

	int choice = 0;
	int value = 0;
	int firstNode = 0;

	cout << "creating first Node, enter its value ";
	cin >> firstNode;
	Node root(firstNode);
	system("cls");


	while (1) {
		root.printInOrder();
		cout << "\n1.insert()\n";
		cout << "2.contains()\n";
		cout << "3.deleteNode()\n";
		cout << "return 0\n";

		cin >> choice;
		system("cls");


		switch (choice) {
		case 1:
			cin >> value;
			root.insert(value);
			system("cls"); break;

		case 2:
			cin >> value;
			system("cls");
			cout << root.contains(value);
			Sleep(2000);
			system("cls"); break;

		case 3:
			cin >> value;
			root.deleteNode(value);
			system("cls"); break;

		case 4: return 0; break;

		default: cout << "enter correct option"; Sleep(2000); system("cls");
		}
	}

	return 0;
}