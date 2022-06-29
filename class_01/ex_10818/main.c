#include <stdio.h>

int N;
int min, max;

void init();
void solve();

int main() {
    init();
    solve();    
    return 0;
} // end of main

void init() {
    scanf("%d", &N);
    min = 1000000;
    max = -1000000;
    return;
}

void solve() {
    int num;
    for (int i=0; i<N; i++) {
        scanf("%d", &num);
        if (num < min) min = num;
        if (max < num) max = num;
    }
    printf("%d %d\n", min, max);
    return;
}