#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 1000000
#define MAX_SUM 2000000000

int N, M;
int trees[MAX_NUM];

void init();
void solve();
int get_tree(int);
int cmp(const void *, const void *);
int max(int, int);

int main() {
	init();
	solve();	
	return 0;
} // end of main

void init() {
	scanf("%d %d", &N, &M);
	for (int i=0; i<N; i++) {
		scanf("%d", &trees[i]);
	}
	qsort(trees, N, sizeof(int), cmp);
	return;
}

void solve() {
	int res=0, cur;
	int low=0, high=MAX_SUM, mid;
	while (low <= high) {
		mid = (low + high) / 2;
		cur = get_tree(mid);
		// mid가 커질 수록 cur는 작아진다.
		// 따라서 cur가 크면 mid를 높이고, cur가 작으면 mid를 낮추면된다.
		if (cur < M)
			high = mid - 1;
		else if (M <= cur) {
			low = mid + 1;
			res = max(res, mid);
		}
	}
	printf("%d\n", res);
	return;
}

int get_tree(int height) {
	long long res = 0;

	for (int i=N-1; (0<=i && height<trees[i]); i--) {
		res += (trees[i] - height);
		if (MAX_SUM <= res)
			return (MAX_SUM + 1);
	}
	return res;
}

int cmp(const void *a, const void *b) {
	if (*(int *)a > *(int *)b)
		return 1;
	else if (*(int *)a < *(int *)b)
		return -1;
	return 0;
}

int max(int a, int b) {
	return (a < b) ? b : a;
}