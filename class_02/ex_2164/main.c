#include <stdio.h>

int N;

void init();
void solve();
int my_pow(int, int);

int main() {
	init();
	solve();	
	return 0;
} // end of main

void init() {
	scanf("%d", &N);
	return;
}

// 각 depth마다 지워지는 카드들과 처음 출력되는 카드에 초점을 둔 점화식
// N이 2^k 이면, 답은 N
// 처음 시작 수는 1
// N이 짝수라면, 다음 시작 수는 tmp += my_pow(2, depth)
// N이 홀수라면, 다음 시작 수는 tmp += 3 * my_pow(2, depth)
// N이 홀수일때, 답을 업데이트

// 1 2 3 4 5 6 7 8 9 10 11 12 13 14
// 1: (3, 5, 7, 9, 11, 13)	N == 14, depth == 0, start == 1, res == 14
// 2: (6, 10, 14)			N == 7,  depth == 1, start == 2, res == 14
// 8:						N == 3,  depth == 2, start == 8, res == 4
// 							N == 1,  ...                   , res == 12 

// 공간복잡도: O(0) - 5 * sizeof(int) * n^0
// 시간복잡도: O(log2(N)) (N을 계속 2로 나누면서 계산)

void solve() {
	int res = N, depth = 0, start = 1;
	while (1 < N) {
		if (N % 2) {
			res = start + my_pow(2, depth);
			start += 3 * my_pow(2, depth);
		}
		else
			start += my_pow(2, depth);
		depth++;
		N /= 2;
	}
	printf("%d\n", res);
	return;
}

int my_pow(int base, int power) {
	int res = 1;
	while (power--)
		res *= base;
	return res;
}