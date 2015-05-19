#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int x;
    while (scanf("%d", &x) != EOF) {
        if (x == 2)
            printf("YES\n");
        else if (x == 1 || x % 2 == 0)
            printf("NO\n");
        else {
            int i, flag = 0;
            for (i = 3; i < x; i += 2) {
                if (x % i == 0) {
                    flag = 1;
                    printf("NO\n");
                }
            }
            if (flag == 0)
                printf("YES\n");
        }
    }
    return 0;
}
