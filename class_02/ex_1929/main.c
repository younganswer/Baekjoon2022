#include <stdio.h>

#define MAX 1000001

int N, M;
int is_prime[MAX];

void init();
void solve();

int main() {
	init();
	solve();
	return 0;
} // end of main

void init() {
	scanf("%d %d", &M, &N);
	return;
}

void solve() {
	is_prime[0] = is_prime[1] = 0;
	for (int i=2; i<=N; i++) {
		is_prime[i] = 1;
	}
	for (int i=2; i*i<=N; i++) {
		if (!is_prime[i])
			continue;
		for (int j=2*i; j<=N; j+=i) {
			is_prime[j] = 0;
		}
	}
	for (int i=M; i<=N; i++) {
		if (is_prime[i]) printf("%d\n", i);
	}
	return;
}