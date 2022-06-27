#include <stdio.h>

void solve();

int main() {
    solve();
    return 0;
} // end of main

void solve() {
    int A, B;
    while (scanf("%d %d", &A, &B) != EOF)
        printf("%d\n", A+B);
    return;
}