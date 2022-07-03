#include <stdio.h>

int N;

void init();
void solve();
int get_N_length();
int get_sum(int);

int main() {
    init();
    solve();
    return 0;
} // end of main

void init() {
    scanf("%d", &N);
    return;
}

void solve() {
    for (int i=N-get_N_length()*9; i<N; i++) {
        if (get_sum(i) == N) {
            printf("%d\n", i);
            return;
        }
    }
    printf("0\n");
    return;
}

int get_N_length() {
    int len = 0;
    int tmp = N;
    while (tmp) {
        len++;
        tmp /= 10;
    }
    return len;
}

int get_sum(int num) {
    int sum = num;
    while (num) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}