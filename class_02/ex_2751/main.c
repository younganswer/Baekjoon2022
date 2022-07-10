#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

int N;
int arr[MAX];

void init();
void solve();
int cmp(const void *, const void *);

int main() {
	init();
	solve();
	return 0;
} // end of main

void init() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d", &arr[i]);
	}
	return;
}

void solve() {
	qsort(arr, N, sizeof(arr[0]), cmp);
	for (int i=0; i<N; i++) {
		printf("%d\n", arr[i]);
	}
	return;
}

int cmp(const void *a, const void *b) {
	return (*(int *)a > *(int *)b);
}