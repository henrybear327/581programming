#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct data {
    int time_needed;
    int deadline;
} data;

int cmp(const void *a, const void *b)
{
    return (((data *)a) -> deadline) - (((data *)b) -> deadline);
}

int main()
{
    int test_cases;
    while(scanf("%d", &test_cases) != EOF) {
        while(test_cases--) {
            int jobs;
            scanf("%d", &jobs);

            data input[jobs];

            for(int i = 0; i < jobs; i++)
                scanf("%d", &input[i].time_needed);
            for(int i = 0; i < jobs; i++)
                scanf("%d", &input[i].deadline);

            qsort(input, jobs, sizeof(data), cmp);

            int total_time = 0;
            bool flag = false;
            for(int i = 0; i < jobs; i++) {
                total_time += input[i].time_needed;

                if(total_time > input[i].deadline) {
                    printf("No\n");
                    flag = true;
                    break;
                }
            }
            if(flag == false)
                printf("Yes\n");
        }
    }
    return 0;
}