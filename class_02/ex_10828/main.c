#include <stdio.h>
#include <string.h>

#define MAX 10000

int N, sz_;
int stack[MAX];

void init();
void solve();

int main() {
	init();
	solve();	
	return 0;
} // end of main

void init() {
	scanf("%d", &N);
	stack[0] = 0; // Non-use value
	sz_ = 0;
	return;
}

void solve() {
	char command[6];
	int num;
	while (N--) {
		scanf("%s", command);
		if (!strcmp(command, "push")) {
			scanf(" %d", &num);
			stack[++sz_] = num;
		}
		else if (!strcmp(command, "pop")) {
			if (!sz_)
				printf("-1\n");
			else
				printf("%d\n", stack[sz_--]);
		}
		else if (!strcmp(command, "size"))
			printf("%d\n", sz_);
		else if (!strcmp(command, "empty"))
			printf("%d\n", !sz_);
		else if (!strcmp(command, "top")) {
			if (!sz_)
				printf("-1\n");
			else
				printf("%d\n", stack[sz_]);
		}
	}
	return;
}