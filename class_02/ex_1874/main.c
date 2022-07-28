#include <stdio.h>

#define MAX 100001

int n, stack_sz, print_sz;
int to_print[2*MAX];
int stack[MAX];

void init();
void solve();

int main() {
	init();
	solve();	
	return 0;
} // end of main

void init() {
	scanf("%d", &n);
	stack_sz = print_sz = 0;
	return;
}

void solve() {
	int cur = 0;
	while (n--) {
		int num;
		scanf("%d", &num);
		while (cur < num) {
			stack[++stack_sz] = ++cur;
			to_print[print_sz++] = 1;
		}
		if (stack[stack_sz] == num) {
			stack[stack_sz--] = 0;
			to_print[print_sz++] = 0;
		}
		else {
			printf("NO\n");
			return;
		}
	}
	for (int i=0; i<print_sz; i++) {
		printf((to_print[i]) ? "+\n" : "-\n");
	}
	return;
}