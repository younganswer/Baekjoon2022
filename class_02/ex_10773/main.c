#include <stdio.h>

#define MAX 100000

int K, sz_;
int money[MAX];

void init();
void solve();

int main() {
	init();
	solve();	
	return 0;
} // end of main

void init() {
	scanf("%d", &K);
	sz_ = 0;
	return;
}

void solve() {
	int res = 0;
	while (K--) {
		scanf("%d", &money[sz_]);
		if (!money[sz_])
			money[--sz_] = 0;
		else
			sz_++;
	}
	for (int i=0; i<sz_; i++) {
		res += money[i];
	}
	printf("%d\n", res);
	return;
}