#include <iostream>
#include <windows.h>

using namespace std;

int* top = NULL;

void display(int* stack, int size) {
	for (int i = size-1; i >= 0; i--) {
		cout << *(stack+i) << endl;
	}	 
}

void push(int* stack,int size) {
	if (top == stack + size) {
		cout << "stack is full!";
		Sleep(1000);
		system("cls");
		return;
	}

	int data = 0;
	cout << "enter data" << endl;
	cin >> data;
	system("cls");

	*top = data;
	top += 1;
}

void pop(int* stack) {
	if (top == stack) {
		cout << "stack is empty!";
		Sleep(1000);
		system("cls");

		return;
	}

	*(top-1) = 0;
	top -=1;
}

int main() {
	int choice = 0;
	int size = 6;

	cout << "enter a size of your stack" << endl;
	cin >> size;
	system("cls");
	
	int* stack = new int[size];
	top = stack;
	memset(stack, 0, size*sizeof(int));

	while (1) {
		display(stack, size);
		cout << "-------------\n";
		cout << "|  1 push |\n|  2 pop  |\n|  3 exit |\n";
		cout << "-------------";

		cin >> choice;
		system("cls");

		switch (choice) {
		case 1: push(stack,size); break;

		case 2: pop(stack) ; break;

		case 3: exit(0);  break;

		default: cout << "choose correct option!";
			Sleep(2000); system("cls");
		}
	}
	return 0;
}

