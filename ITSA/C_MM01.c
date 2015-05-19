#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int top, bottom, height;
    while (scanf("%d %d %d", &top, &bottom, &height) != EOF) {
        printf("Trapezoid area:%.1f\n", (double)(top + bottom) * height / 2);
    }
    return 0;
}