#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    double a;
    while (scanf("%lf", &a) != EOF) {
        // 82.45
        printf("%.1lf\n", round(a * a * 10) / 10);
    }
    return 0;
}
