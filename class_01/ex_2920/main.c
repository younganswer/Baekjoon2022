#include <stdio.h>

int main() {
    int prev = 0, cur = 0;
    for (int i=0; i<8; i++) {
        prev = cur;
        scanf("%d", &cur);
        if (!prev) continue;
        if ((prev-cur)*(prev-cur) != 1) {
            printf("mixed\n");
            return 0;
        }
    }
    if (cur == 8)
        printf("ascending\n");
    else
        printf("descending\n");
    return 0;
} // end of main