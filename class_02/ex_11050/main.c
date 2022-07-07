#include <stdio.h>

int N, K;
int pascal[10][10];

void init();
void solve();

int main() {
	init();
	solve();
	return 0;
} // end of main

void init() {
	scanf("%d %d", &N, &K);
	for (int i=1; i<=N; i++) {
		pascal[i][0] = pascal[i][i] = 1;
	}
	return;
}

void solve() {
	for (int i=2; i<=N; i++) {
		for (int j=1; j<i; j++) {
			pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
		}
	}
	printf("%d\n", pascal[N][K]);
	return;
}