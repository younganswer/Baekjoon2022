#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int N, M;
int nums[MAX];

void init();
void solve();
int cmp(const void *, const void *);
int binary_search(int);

int main() {
	init();
	solve();	
	return 0;
} // end of main

void init() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d", &nums[i]);
	}
	return;
}

void solve() {
	qsort(nums, N, sizeof(int), cmp);
	scanf("%d", &M);
	while (M--) {
		int num;
		scanf("%d", &num);
		(binary_search(num) == -1) ? printf("0\n") : printf("1\n");
	}
	return;
}

// binary_search Big-O notation -> O(logN)
int binary_search(int target) {
	int start = 0, end = N-1, mid;
	while (start <= end) {
		mid = (start + end) / 2;
		if (target == nums[mid])
			return mid;
		else if (target < nums[mid])
			end = mid - 1;
		else
			start = mid + 1;
	}
	return -1;
}

// qsort의 cmp함수는 int를 리턴하는 함수를 인자로 받는다.
// return (*(int *)a - *(int *)b); => overflow, underflow 가 일어나며 데이터 손실에 의해 음 양이 서로 바뀔 수 있음
// return (*(long long *)a - *(long long *)b); => 반환 시에 int 자료형에 맞추게 되며, 같은 현상 발생
int cmp(const void *a, const void *b) {
	return (*(int *)a > *(int *)b);
}