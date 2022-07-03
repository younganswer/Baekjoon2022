#include <stdio.h>

#define MAX 100

int N, M;
int cards[MAX];
int max;

void init();
void solve();

int main() {
    init();
    solve();    
    return 0;
} // end of main

void init() {
    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++) {
        scanf("%d", &(cards[i]));
    }
    max = 0;
    return;
}

void solve() {
    for (int i=0; i<N-2; i++) {
        for (int j=i+1; j<N-1; j++) {
            for (int k=j+1; k<N; k++) {
                int cur = cards[i] + cards[j] + cards[k];
                if (cur <= M && max < cur) max = cur;
            }
        }
    }
    printf("%d\n", max);
    return;
}