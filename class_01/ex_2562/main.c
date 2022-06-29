#include <stdio.h>

int arr[9];
int idx;

void init();
void solve();

int main() {
    init();
    solve();    
    return 0;
} // end of main

void init() {
    for (int i=0; i<9; i++) 
        scanf("%d", &(arr[i]));
    idx = 0;
    return;
}

void solve() {
    int max = 0;
    for (int i=0; i<9; i++) {
        if (max < arr[i]) {
            max = arr[i];
            idx = i;
        }
    }
    printf("%d\n%d\n", max, idx+1);
    return;
}