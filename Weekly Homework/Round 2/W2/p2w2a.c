#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int check_triangle(int input[], int i, int j, int k)
{
    if(input[i] + input[j] > input[k] && input[i] + input[k] > input[j] && input[j] + input[k] > input[i])
        return 1;
    return 0;
}

int main()
{
    int segment;
    while(scanf("%d", &segment) != EOF && segment) {
        int input[segment];
        for(int i = 0; i < segment; i++)
            scanf("%d", &input[i]);

        qsort(input, segment, sizeof(int), cmp);

        int total = 0;
        for(int i = 0; i < segment; i++) {
            for(int j = i + 1; j < segment; j++) {
                int sum_of_two = input[i] + input[j];
                for(int k = 0; input[k] < sum_of_two; k++) {
                    if(k == i || k == j)
                        continue;
                    total += check_triangle(input, i, j, k);
                }
            }
        }

        printf("%d\n", total / 3);

    }

    return 0;
}