#include <stdio.h>

int N;

int init();
void solve();
int get_num_len(int);

int main() {
	while (init()) solve();
	return 0;
} // end of main

int init() {
	scanf("%d", &N);
	return N;
}

void solve() {
	int num[6] = {0, };
	int len = get_num_len(N);
	for (int i=0; i<len; i++) {
		num[len-1-i] = N % 10;
		N /= 10;
	}
	for (int i=0; i<len/2; i++) {
		if (num[i] != num[len-1-i]) {
			printf("no\n");
			return;
		}
	}
	printf("yes\n");
	return;
}

int get_num_len(int num) {
	int len = 0;
	while (num) {
		num /= 10;
		len++;
	}
	return len;
}