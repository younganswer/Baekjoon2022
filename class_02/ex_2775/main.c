#include <stdio.h>

int k, n;
int apartment[14][15];

void init();
void solve();

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		init();
		solve();
	}	
	return 0;
} // end of main

void init() {
	scanf("%d\n%d", &k, &n);
	for (int j=0; j<=n; j++) {
		apartment[0][j] = j;
	}
	return;
}

void solve() {
	for (int i=1; i<=k; i++) {
		for (int j=1; j<=n; j++) {
			if (j == 1) {
				apartment[i][j] = apartment[i-1][j];
				continue;
			}
			apartment[i][j] = apartment[i][j-1] + apartment[i-1][j];
		}
	}
	printf("%d\n", apartment[k][n]);
	return;
}