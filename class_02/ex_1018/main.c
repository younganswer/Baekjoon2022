#include <stdio.h>

#define MAX 50

int N, M;
// White: 0, black: 1
int board[MAX][MAX];
int whiteFirst[8][8];
int blackFirst[8][8];
int min;

void init();
void solve();
int to_color(int, int);

int main() {
	init();
	solve();
	return 0;
} // end of main

void init() {
	scanf("%d %d", &N, &M);
	for (int i=0; i<N; i++) {
		char row[M];
		scanf("%s", row);
		for (int j=0; j<M; j++) {
			board[i][j] = (row[j] == 'W') ? 0 : 1;
		}
	}
	for (int i=0; i<8; i++) {
		for (int j=0; j<8; j++) {
			if (!(i % 2)) {
				whiteFirst[i][j] = j % 2;
				blackFirst[i][j] = (j + 1) % 2;
			} else {
				whiteFirst[i][j] = (j + 1) % 2;
				blackFirst[i][j] = j % 2;
			}
		}
	}
	min = 8 * 8;
	return;
}

void solve() {
	int cur;
	for (int i=0; i<=N-8; i++) {
		for (int j=0; j<=M-8; j++) {
			cur = to_color(i, j);
			if (cur < min) min = cur;
		}
	}
	printf("%d\n", min);
	return;
}

int to_color(int i, int j) {
	int whiteCnt = 0, blackCnt = 0;
	for (int di=0; di<8; di++) {
		for (int dj=0; dj<8; dj++) {
			if (whiteFirst[di][dj] != board[i+di][j+dj]) whiteCnt++;
			if (blackFirst[di][dj] != board[i+di][j+dj]) blackCnt++;
		}
	}
	return (whiteCnt < blackCnt) ? whiteCnt : blackCnt;
}