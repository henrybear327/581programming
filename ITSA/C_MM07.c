#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int a;
    while (scanf("%d", &a) != EOF) {
        printf("%d %d %d\n", a, a * a, a * a * a);
    }
    return 0;
}
