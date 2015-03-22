#include <stdio.h>
#include <string.h>

int main()
{
    int test_cases;
    scanf("%d", &test_cases);
    while(test_cases--) {
        long long int x, y, N;
        scanf("%lld %lld %lld", &x, &y, &N);
        int pre_cycle = 0, cycle_length = -1;
        int remainder_check[20000] = {0};
        long long int remainder_list[20000];
        memset(remainder_list, -1, sizeof(remainder_list));

        long long int exp, remainder = 1;
        for(exp = 1; exp <= y; exp++) {
            //printf("loop\n");
            remainder = remainder * x;
            remainder = remainder % N;
            //printf("remainder = %lld\n", remainder);

            if(remainder_check[remainder] == 0) {
                remainder_check[remainder] = exp;
                remainder_list[exp] = remainder;
            } else {
                cycle_length = exp - remainder_check[remainder];
                pre_cycle = remainder_check[remainder];
                break;
            }
        }

        if(cycle_length == -1)
            printf("%lld\n", remainder);
        else
            printf("%lld\n", remainder_list[(y - pre_cycle) % cycle_length + pre_cycle]);
    }

    return 0;
}