#include <stdlib.h>
#include <stdio.h>
#include <math.h>

long long int factorial[13];

int main()
{
    int i;
    factorial[0] = 1;
    for(i = 1; i < 13; i++) {
        factorial[i] = i * factorial[i - 1];
        //printf("%d %lld\n", i, factorial[i]);
    }

    int test_cases;
    while(scanf("%d", &test_cases) != EOF) {
        while(test_cases--) {
            long long int n, k;
            scanf("%lld %lld", &n, &k);

            printf("%lld\n", factorial[n] / (factorial[k] * factorial[n - k]));
        }
    }
    return 0;
}