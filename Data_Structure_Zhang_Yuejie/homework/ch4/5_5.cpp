#include <iostream>
#include <cstring>
using namespace std;

#define ROW 4
#define COL 4

void display(int arr[][COL], int row, int col) {
	for (int rx = 0; rx < row; rx++) {
		for (int cx = 0; cx < col; cx++) {
			cout << arr[rx][cx] << " ";
		}
		cout << endl;
	}
}

int main(void) {
	int arr[ROW][COL] = {
		{2,0,3,4},
		{5,1,1,2},
		{3,2,4,5},
		{1,2,3,0}
	};

	int aux[ROW][COL];
	memset(aux, 0, sizeof(aux));

	// find min in rows
	for (int rx = 0; rx < ROW; rx++) {
		int minCx = 0;
		for (int cx = 0; cx < COL; cx++) {
			if (arr[rx][cx] < arr[rx][minCx]) {
				minCx = cx;
			}
		}
		int min = arr[rx][minCx];
		for (int cx = 0; cx < COL; cx++) {
			if (arr[rx][cx] == min) {
				aux[rx][cx] += 1;
			}
		}
	}

	// find max in cols
	for (int cx = 0; cx < COL; cx++) {
		int maxRx = 0;
		for (int rx = 0; rx < ROW; rx++) {
			if (arr[rx][cx] > arr[maxRx][cx]) {
				maxRx = rx;
			}
		}
		int max = arr[maxRx][cx];
		for (int rx = 0; rx < ROW; rx++) {
			if (arr[rx][cx] == max) {
				aux[rx][cx] += 1;
			}
		}
	}

	display(aux, ROW, COL);

	// check for 2
	for (int rx = 0; rx < ROW; rx++) {
		for (int cx = 0; cx < COL; cx++) {
			if (aux[rx][cx] == 2) {
				cout << "Âí°°µã£º(" << rx + 1 << ", " << cx + 1 << ")" << endl;
			}
		}
	}

	return 0;
}