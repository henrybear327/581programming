#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int gcd(int x, int y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);

    /*
        while b:
            a, b = b, a % b
        return a

        while (b) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    */
}

int main()
{
    int x, y;
    while (scanf("%d %d", &x, &y) != EOF) {
        if (x > y) {
            int temp = x;
            x = y;
            y = temp;
        }
        printf("%d\n", gcd(x, y));
    }
    return 0;
}
