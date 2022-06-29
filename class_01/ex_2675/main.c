#include <stdio.h>

int R;
char str[21];

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
    scanf("%d %s", &R, str);
    return;
}

void solve() {
    int idx = 0;
    while (str[idx]) {
        for (int i=0; i<R; i++) {
            printf("%c", str[idx]);
        }
        idx++;
    }
    printf("\n");
    return;
}