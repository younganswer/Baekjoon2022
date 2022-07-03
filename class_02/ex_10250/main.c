#include <stdio.h>

int H, W, N;

void init();
void solve();

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        init();
        solve();
    }
    return 0;
} // end of main

void init() {
    scanf("%d %d %d", &H, &W, &N);
    return;
}

void solve() {
    int X=1, Y=0;
    while (N--) {
        Y++;
        if (Y == H+1) {
            X++;
            Y = 1;
        }
    }
    printf("%d", Y);
    if (X < 10) printf("0");
    printf("%d\n", X);
    return;
}