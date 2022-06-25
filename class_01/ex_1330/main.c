#include <stdio.h>

int main() {
    int A, B;
    scanf("%d %d", &A, &B);
    if (B < A) printf(">");
    else if (A < B) printf("<");
    else printf("==");
    printf("\n");
    return 0;
} // end of main