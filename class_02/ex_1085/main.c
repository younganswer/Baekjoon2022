#include <stdio.h>

int min = 1000;
int x, y, w, h;

void init();
void solve();

int main() {
    init();
    solve();
    return 0;
} // end of main

void init() {
    scanf("%d %d %d %d", &x, &y, &w, &h);
    return;
}

void solve() {
    min = (x < w-x) ? x : w-x;
    min = (min < y) ? min : y;
    min = (min < h-y) ? min : h-y;
    printf("%d\n", min);
    return;
}