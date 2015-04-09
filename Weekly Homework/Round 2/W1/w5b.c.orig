#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int test_cases;
    while(scanf("%d", &test_cases) != EOF) {
        while(test_cases--) {
        int boxs;
        scanf("%d", &boxs);
        
        int input[boxs];
        for(int i = 0; i < boxs; i++)
            scanf("%d", &input[i]);
        
        qsort(input, boxs, sizeof(int), cmp);
        
        /*
        for(int i = 0; i < boxs; i++)
            printf("%d ", input[i]);
        printf("\n");
        */
        
        int total = 0, weight = 2 * boxs - 1;
        for(int i = 0; i < boxs; i++) {
            total += (input[i] * weight);
            //printf("%d\n", total);
            weight -= 2;
        }
        
        printf("%d\n", total);
    }
    }
    return 0;
}