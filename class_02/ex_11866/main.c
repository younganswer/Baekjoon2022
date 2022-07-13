#include <stdio.h>

#define MAX 1001

int N, K;
int people[MAX];

void init();
void solve();

int main() {
	init();
	solve();	
	return 0;
} // end of main

void init() {
	scanf("%d %d", &N, &K);
	people[0] = 0;
	for (int i=1; i<=N; i++) {
		people[i] = 1;
	}
	return;
}

void solve() {
	int removed = 0;
	int cur = 0;
	printf("<");
	while (removed < N) {
		int cnt = 0;
		while (cnt++ < K) {
			if (++cur == N+1) cur = 1;
			while (!people[cur])
				if (++cur == N+1) cur = 1;
		}
		if (removed++)
			printf(", ");
		printf("%d", cur);
		people[cur] = 0;
	}
	printf(">\n");
	return;
}