#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define YES 1
#define NO 0

int main()
{
    int test_cases;
    while(scanf("%d", &test_cases) != EOF && test_cases) {
        int Q1, Q2, R1, R2;
        while(test_cases-- && scanf("%d %d %d %d", &Q1, &R1, &Q2, &R2) != EOF) {
            int first_time = YES, num_1 = Q1 - R1, num_2 = Q2 - R2, D = 1;
            while(D <= num_1 && D <= num_2) {
                if(num_1 % D == 0 && num_2 % D == 0) {
                    if(first_time == NO)
                        printf(" ");
                    first_time = NO;
                    printf("%d", D);
                }
                D++;
            }
            printf("\n");
        }
    }
    return 0;
}