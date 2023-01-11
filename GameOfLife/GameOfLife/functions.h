#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <time.h>


using namespace std;

const int width = 30, height = 30;

void randStart(bool Temp[width][height]) {
	srand(time(0));

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if ((rand() % 100) < 50) Temp[j][i] = 0;
			else Temp[j][i] = 1;
		}
	}
}

void blinkStart(bool Temp[width][height]) {

	for (int i = 3; i <=width-3 ; i=i+5) {
		for (int j = -1; j <= 1; j++) {
			Temp[(i)][(height / 2) - j] = 1;
		}
	}
}

bool IsAlive(bool Game[width][height], int x, int y) {

	int alive = 0;

	//lewo
	if (Game[x - 1][y] == 1 && x > 0) { alive++; }

	//prawo
	if (Game[x + 1][y] == 1 && x < width) { alive++; }

	//dol
	if (Game[x][y + 1] == 1 && y < height) { alive++; }

	//gora
	if (Game[x][y - 1] == 1 && y > 0) { alive++; }

	//lewy-gorny
	if (Game[x - 1][y - 1] == 1 && x > 0 && y > 0) { alive++; }

	//lewy-dolny
	if (Game[x - 1][y + 1] == 1 && x > 0 && y < height) { alive++; }

	//prawy-gorny
	if (Game[x + 1][y - 1] == 1 && x < width && y>0) { alive++; }

	//prawy-dolny
	if (Game[x + 1][y + 1] == 1 && x < width && y < height) { alive++; }

	if (Game[x][y] == 1 && alive < 2) return false;

	if (Game[x][y] == 1 && (alive == 2 || alive == 3)) return true;

	if (alive > 3) return false;

	if (Game[x][y] == 0 && alive == 3)return true;

	return false;
}


