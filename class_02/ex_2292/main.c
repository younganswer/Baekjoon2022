#include <stdio.h>

int N;

void init();
void solve();

int main() {
    init();
    solve();
    return 0;
} // end of main

void init() {
    scanf("%d", &N);
    return;
}

void solve() {
    int cur = 1;
    int layer = 0;
    while (cur < N) {
        layer++;
        cur += 6 * layer;
    }
    printf("%d\n", layer + 1);
    return;
}