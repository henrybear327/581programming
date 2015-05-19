#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    double a;
    while (scanf("%lf", &a) != EOF) {
        printf("%.1lf\n", a * 1.6);
    }
    return 0;
}
