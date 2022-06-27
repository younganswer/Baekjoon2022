#include <stdio.h>

void solve();

int main() {
    solve();
    return 0;
} // end of main

void solve() {
    int A, B;
    while (1) {
        scanf("%d %d", &A, &B);
        if (!A && !B) break;
        printf("%d\n", A+B);
    }
    return;    
}