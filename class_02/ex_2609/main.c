#include <stdio.h>

int A, B;

void init();
void solve();
int gcd(int, int);
int lcm(int, int);

int main() {
	init();
	solve();
	return 0;
} // end of main

void init() {
	scanf("%d %d", &A, &B);
	return;
}

void solve() {
	printf("%d\n%d\n", gcd(A, B), lcm(A, B));
	return;
}

int gcd(int a, int b) {
	if (!b)
		return a;
	return gcd(b, a % b);
}

int lcm(int a, int b) {
	return (a * b / gcd(a, B));
}