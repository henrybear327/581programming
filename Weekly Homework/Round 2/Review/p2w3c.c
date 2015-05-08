#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int test_cases;
    scanf("%d", &test_cases);
    while (test_cases--) {
        int total_spies;
        scanf("%d", &total_spies);
        int spy[total_spies];
        for (int i = 1; i < total_spies; i++)
            scanf("%d", &spy[i]);

        int selected[total_spies];
        memset(selected, 0, sizeof(selected));
        for (int i = total_spies - 1; i > 0; i--) {
            if (selected[spy[i]] == 0 && selected[i] != 1) {
                selected[spy[i]] = 1;
                // printf("i = %d\n", i);
            }
        }

        int count = 0;
        for (int i = 0; i < total_spies; i++)
            if (selected[i] == 1)
                count++;

        printf("%d\n", count);
    }

    return 0;
}
