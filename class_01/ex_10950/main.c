#include <stdio.h>

int T;

void init();
void solve();

int main() {
    init();
    while (T--) solve();    
    return 0;
} // end of main

void init() {
    scanf("%d", &T);
    return;
}

void solve() {
    int A, B;
    scanf("%d %d", &A, &B);
    printf("%d\n", A+B);
    return;
}