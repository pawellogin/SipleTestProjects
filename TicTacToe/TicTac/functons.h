#include <iostream>
#include <Windows.h>

using namespace std;

//game arrey 
short int tab[3][3];
//player==1 ->circle,player==2 -> x
int player = 1;

void dispaly();
void menu();
void info();
void play();
int end_of_game();
void what_player();

void dispaly() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (tab[j][i] == 0)cout << "| |";
			if (tab[j][i] == 1)cout << "|O|";
			if (tab[j][i] == 2)cout << "|X|";
		}
		cout << endl;

	}
}

void menu() {
	int choice = NULL;
	cout << "---------------" << endl;
	cout << "1.NEW GAME" << endl;
	cout << "2.INFO" << endl;
	cout << "3.EXIT" << endl;
	cout << "---------------" << endl;
	cin >> choice;

	switch (choice) {
	case 1: system("cls"); break;
	case 2: info();
	case 3: exit(0);
	}

}

void info() {
	system("cls");
	cout << "To play the game use numpad" << endl;
	cout << "7|8|9" << endl << "4|5|6" << endl << "1|2|3" << endl;
	Sleep(4000);
	system("cls");
	menu();
}

void play() {
	int choice = 0;

	//put O in a place chosen by player

	if (player == 1) {
		cin >> choice;
		if (choice == 7 && tab[0][0] == 0) { tab[0][0] = 1; player = 2; }
		if (choice == 8 && tab[1][0] == 0) { tab[1][0] = 1; player = 2; }
		if (choice == 9 && tab[2][0] == 0) { tab[2][0] = 1; player = 2; }
		if (choice == 4 && tab[0][1] == 0) { tab[0][1] = 1; player = 2; }
		if (choice == 5 && tab[1][1] == 0) { tab[1][1] = 1; player = 2; }
		if (choice == 6 && tab[2][1] == 0) { tab[2][1] = 1; player = 2; }
		if (choice == 1 && tab[0][2] == 0) { tab[0][2] = 1; player = 2; }
		if (choice == 2 && tab[1][2] == 0) { tab[1][2] = 1; player = 2; }
		if (choice == 3 && tab[2][2] == 0) { tab[2][2] = 1; player = 2; }
		goto label;
	}

	//put X in a place chosen by player


	if (player == 2) {
		cin >> choice;
		if (choice == 7 && tab[0][0] == 0) { tab[0][0] = 2; player = 1; }
		if (choice == 8 && tab[1][0] == 0) { tab[1][0] = 2; player = 1; }
		if (choice == 9 && tab[2][0] == 0) { tab[2][0] = 2; player = 1; }
		if (choice == 4 && tab[0][1] == 0) { tab[0][1] = 2; player = 1; }
		if (choice == 5 && tab[1][1] == 0) { tab[1][1] = 2; player = 1; }
		if (choice == 6 && tab[2][1] == 0) { tab[2][1] = 2; player = 1; }
		if (choice == 1 && tab[0][2] == 0) { tab[0][2] = 2; player = 1; }
		if (choice == 2 && tab[1][2] == 0) { tab[1][2] = 2; player = 1; }
		if (choice == 3 && tab[2][2] == 0) { tab[2][2] = 2; player = 1; }
	}
label:

	system("cls");
}

int end_of_game() {
	int scoreO = 0;
	int scoreX = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (tab[j][i] == 1)scoreO++;
			if (tab[j][i] == 2)scoreX++;
			if (scoreO == 3) return 0;
			if (scoreX == 3) return 1;
		}
		scoreO = 0;
		scoreX = 0;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (tab[i][j] == 1)scoreO++;
			if (tab[i][j] == 2)scoreX++;
			if (scoreO == 3) return 0;
			if (scoreX == 3) return 1;
		}
		scoreO = 0;
		scoreX = 0;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (tab[j][i] == 1 && (j == i)) scoreO++;
			if (tab[j][i] == 2 && (j == i)) scoreX++;
			if (scoreO == 3) return 0;
			if (scoreX == 3) return 1;
		}

	}
	scoreO = 0;
	scoreX = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (tab[j][i] == 1 && ((j == 1 && i == 1) || (j == 0 && i == 2) || (j == 2 && i == 0)))
				scoreO++;
			if (tab[j][i] == 2 && ((j == 1 && i == 1) || (j == 0 && i == 2) || (j == 2 && i == 0)))
				scoreX++;
			if (scoreO == 3) return 0;
			if (scoreX == 3) return 1;
		}

	}
	scoreO = 0;
	scoreX = 0;

	//draw

	int temp = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (tab[j][i] == 1 || tab[j][i] ==2 ) temp++;
		}
		if (temp == 9) return 2;
		cout << endl << temp << endl;
	}
	temp = 0;



}

void what_player() {
	if (player == 1) {
		cout << endl;
		cout << " O TURN" << endl;
		cout << endl;
	}
	if (player == 2) {
		cout << endl;
		cout << " X TURN" << endl;
		cout << endl;
	}
}
