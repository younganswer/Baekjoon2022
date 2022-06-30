#include <stdio.h>

int a, b, c;

int init();
void solve();
void swap(int *, int *);

int main() {
    while (init()) solve();    
    return 0;
} // end of main

int init() {
    scanf("%d %d %d", &a, &b, &c);
    if (!a && !b && !c) return 0;
    return 1;
}

void solve() {
    if (c < a) swap(&a, &c);
    if (c < b) swap(&b, &c);
    if (a*a + b*b == c*c)
        printf("right\n");
    else
        printf("wrong\n");
    return;
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}