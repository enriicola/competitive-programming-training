#include <stdio.h>

int main(void) {
    int tests;
    scanf("%d", &tests);

    while (tests--) {
        int k, x;
        scanf("%d %d", &k, &x);

        for (int i = 0; i < k; i++)
            if ((x-1) % 3 == 0 && (x-1) != 0)
                x = (x - 1) / 3;
            else
                x = x * 2;
        
        printf("%d\n", x);
    }
    return 0;
}