#include <stdio.h>

#define MAX 50

char str[MAX+1];

void init();
void solve();

int main() {
	int N;
	scanf("%d", &N);
	while (N--) {
		init();
		solve();
	}
	return 0;
} // end of main

void init() {
	scanf("%s", str);
	return;
}

void solve() {
	int stack = 0;
	for (int i=0; str[i]; i++) {
		if (str[i] == '(')
			stack++;
		else if (str[i] == ')') {
			stack--;
			if (stack < 0)
				break;
		}
	}
	if (stack)
		printf("NO\n");
	else
		printf("YES\n");
	return;
}