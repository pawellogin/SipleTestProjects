
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <time.h>
#include "functions.h"

using namespace std;

extern const int width , height;

//game_speed lower=faster
int game_speed = 200;


int main()
{
	int x = 0, y = 0;

	bool GameBoard[width][height];
	memset(GameBoard, 0, width * height * sizeof(bool));

	bool Temp[width][height];
	memset(Temp, 0, width * height * sizeof(bool));

	randStart(Temp);
	//blinkStart(Temp);

	while (true) {
		//use IsAlive() on Temp and copy results to GameBoard[][]
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {

				GameBoard[j][i] = IsAlive(Temp, j, i);
			}
			cout << endl;
		}
		
		//copy GameBoard[][] to Temp[][] for next generation
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				Temp[j][i] = GameBoard[j][i];
			}
		}

		//dispaly our game
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (GameBoard[j][i] == 1)cout << "# ";
				else cout<< "  ";
			} cout << endl;
		}
		Sleep(game_speed);
		system("cls");
	}




}

