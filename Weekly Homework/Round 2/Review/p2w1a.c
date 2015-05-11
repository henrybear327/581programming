#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int test_cases;
    scanf("%d", &test_cases);
    while (test_cases--) {
        int data_count;
        scanf("%d", &data_count);

        int max_so_far = 0, temp = 0, max = 0;
        for (int i = 0; i < data_count; i++) {
            scanf("%d", &temp);
            max = (max + temp > 0 ? max + temp : 0);
            max_so_far = max_so_far > max ? max_so_far : max;
        }

        printf("%d\n", max_so_far);
    }

    return 0;
}