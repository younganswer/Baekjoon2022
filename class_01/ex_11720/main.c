#include <stdio.h>

#define MAX 101

int N, res;

void init();
void solve();

int main() {
    init();
    solve();
    return 0;
} // end of main

void init() {
    scanf("%d", &N);
    res = 0;
    return;
}

void solve() {
    char num[MAX];
    scanf("%s", num);
    for (int i=0; i<N; i++)
        res += num[i] - '0';
    printf("%d\n", res);
    return;
}