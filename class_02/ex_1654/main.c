#include <stdio.h>

#define MAX 10000

// int 범위에서 overflow가 발생하여 값들이 비트 조작에 의해 음수로 바뀌었고 디버깅이 쉽지 않았다.
// 그래서, 모든 값들을 unsigned long long 자료형으로 다루어 해당 이슈를 해결해주었다.
#define ull unsigned long long

ull N, K;
ull cables[MAX];
ull start, end, mid;

void init();
void solve();
ull cnt_by_length(int);

int main() {
	init();
	solve();
	return 0;
} // end of main

void init() {
	start = end = 1;
	scanf("%lld %lld", &K, &N);
	for (ull i=0; i<K; i++) {
		scanf("%lld", &cables[i]);
		if (end < cables[i])
			end = cables[i];
	}
	return;
}

void solve() {
	int res;
	while (start <= end) {
		// start + end 에서 int overflow 발생 가능
		mid = (start + end) / 2;
		if (N <= cnt_by_length(mid)) {
			start = mid + 1;
			res = mid;
		}
		else
			end = mid - 1;
	}
	printf("%d\n", res);
	return;
}

ull cnt_by_length(int cur_length) {
	ull cnt = 0;
	for (ull i=0; i<K; i++) {
		// cnt에서 int overflow 발생 가능
		cnt += cables[i] / cur_length;
	}
	return cnt;
}