#include <stdio.h>

#define MAX 1001

int N;
int is_prime[MAX];

void init();
void solve();

int main() {
	init();
	solve();
	return 0;
} // end of main

void init() {
	is_prime[0] = is_prime[1] = 0;
	for (int i=2; i<=1000; i++) {
		is_prime[i] = 1;
	}
	for (int i=2; i*i<=1000; i++) {
		if (!is_prime[i])
			continue;
		for (int j=2*i; j<=1000; j+=i) {
			is_prime[j] = 0;
		}
	}
	return;
}

void solve() {
	scanf("%d", &N);
	int cnt = 0;
	while (N--) {
		int target;
		scanf("%d", &target);
		if (is_prime[target])
			cnt++;
	}
	printf("%d\n", cnt);
	return;
}