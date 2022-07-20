#include <stdio.h>
#include <stdlib.h>

#define MAX 500000

int N, M;
int num[MAX];

void init();
void solve();

int cmp(const void *, const void *);

int lower_bound(int);
int upper_bound(int);

int main() {
	init();
	solve();
	return 0;
} // end of main

void init() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d", &num[i]);
	}
	scanf("%d", &M);
	return;
}

void solve() {
	qsort(num, N, sizeof(int), cmp);
	while (M--) {
		int target;
		scanf("%d", &target);
		printf("%d ", upper_bound(target) - lower_bound(target));
	}
	printf("\n");
	return;
}

int cmp(const void *a, const void *b) {
	if (*(int *) a < *(int *) b)
		return -1;
	if (*(int *) a == *(int *) b)
		return 0;
	return 1;
}

// -10 -10 2 3 3 6 7 10 10 10
int lower_bound(int target) {
	int start = 0, end = N-1, mid;
	while (start < end) {
		mid = (start + end) / 2;
		if (num[mid] < target)
			start = mid + 1;
		else
			end = mid;
	}
	return end;
}

int upper_bound(int target) {
	int start = 0, end = N-1, mid;
	while (start < end) {
		mid = (start + end) / 2;
		if (num[mid] <= target)
			start = mid + 1;
		else
			end = mid;
	}
	// target이 num의 마지막 값일 때
	if (num[end] == target)
		return (end + 1);
	return end;
}