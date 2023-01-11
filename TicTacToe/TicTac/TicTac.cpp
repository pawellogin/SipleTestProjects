#include <iostream>
#include <Windows.h>
#include "functons.h"

using namespace std;

extern short int tab[3][3];
extern int player ;


int main() {
	memset(tab, 0, 9 * sizeof(short int));
	int player = 1;
	
	menu();

	while (1) {

	
		what_player();
		dispaly();
		play();
		
		if (end_of_game() == 2) {
			cout << endl;
			cout << "  DRAW" << endl;
			cout << endl;
			dispaly();
			exit(0);
		}
		if (end_of_game()==1) {
			cout << endl;
			cout << "  X WIN" << endl;
			cout << endl;
			dispaly();
			exit(0);
		}
		if(end_of_game()==0) {
			cout << endl;
			cout << "  O WIN" << endl;
			cout << endl;
			dispaly();
			exit(0);
		}
	}
}
