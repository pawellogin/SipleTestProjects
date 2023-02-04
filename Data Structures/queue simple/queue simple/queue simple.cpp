#include <iostream>
#include <windows.h>

using namespace std;

int* rear = NULL;
int* front = NULL;

void display(int* queue, int size) {
	for (int i = 0; i < size; i++) {
		cout << *(queue + i) <<" ";
	}
	cout << endl;
}

void push(int* queue, int size) {
	if (rear == queue + size) {
		cout << "queue is full!";
		Sleep(1000);
		system("cls");
		return;
	}

	int data = 0;
	cout << "enter data" << endl;
	cin >> data;
	system("cls");

	*rear = data;
	rear += 1;
}

void pop(int* queue,int size) {
	if (rear == queue) {
		cout << "queue is empty!";
		Sleep(1000);
		system("cls");
		return;
	}

	int temp = 0;
	int i = 0;
	while (i<size-1 ){
		*(queue + i) = *(queue + i + 1);	
		i++;
	}
	*(queue + size-1) = 0;
	rear --;
}

int main() {
	int choice = 0;
	int size = 0;

	cout << "enter a size of your queue" << endl;
	cin >> size;
	system("cls");

	int* queue = new int[size];
	rear = queue;
	front = queue;
	memset(queue, 0, size * sizeof(int));

	while (1) {
		display(queue, size);
		cout << "-------------\n";
		cout << "|  1 push |\n|  2 pop  |\n|  3 exit |\n";
		cout << "-------------\n";

		cin >> choice;
		system("cls");

		switch (choice) {
		case 1: push(queue, size); break;

		case 2: pop(queue,size); break;

		case 3: exit(0);  break;

		default: cout << "choose correct option!";
			Sleep(2000); system("cls");
		}
	}
	return 0;
}

