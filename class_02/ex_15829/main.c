#include <stdio.h>

#define ull unsigned long long
#define MAX 51
#define R 31
#define MOD 1234567891

int L;
char str[MAX];

void init();
void solve();
ull my_pow(int, int);

int main() {
    init();
    solve();
    return 0;
} // end of main

void init() {
    scanf("%d %s", &L, str);
    return;
}

void solve() {
    ull res = 0;
    for (int i=0; i<L; i++) {
        res += ((str[i] - 'a' + 1) * my_pow(R, i)) % MOD;
        res %= MOD;
    }
    printf("%d\n", res);
    return;
}

ull my_pow(int base, int power) {
    ull res = 1;
    while (power--) {
        res *= base;
        res %= MOD;
    }
    return res;
}