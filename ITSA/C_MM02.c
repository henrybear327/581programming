#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int bottom, height;
    while (scanf("%d %d", &bottom, &height) != EOF) {
        printf("%.1f\n", (double)bottom * height / 2);
    }
    return 0;
}
