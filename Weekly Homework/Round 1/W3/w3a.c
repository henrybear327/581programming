#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int two_power[16] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768};

int main()
{
    int test_cases;
    while(scanf("%d", &test_cases) != EOF && test_cases) {
        getchar();
        int total = 0;
        while(test_cases--) {
            char input[16 + 2] = {0};
            fgets(input, 18, stdin);
            int max_power = strlen(input) - 2;
            for(int i = 0; i <= max_power; i++) {
                total += two_power[max_power - i] * (input[i] - '0');
                //printf("%d %d %d\n", i, total, max_power);
            }
        }
        printf("%d\n", total);
    }
    return 0;
}