#include <stdio.h>

#define MAX 81

char str[MAX];

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
    scanf("%s", str);
    return;
}

void solve() {
    int stack = 0, score = 0;
    for (int i=0; str[i]; i++) {
        if (str[i] == 'O') {
            ++stack;
            score += stack;
        }
        else
            stack = 0;
    }
    printf("%d\n", score);
    return;
}