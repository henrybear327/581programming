#include <stdio.h>

int main()
{
    int test_cases;
    while (scanf("%d", &test_cases) != EOF) {
        while (test_cases--) {
            int elements;
            scanf("%d", &elements);

            int max = 0, total = 0;
            for (int i = 0; i < elements; i++) {
                int temp;
                scanf("%d", &temp);

                total += temp;
                total = total > 0 ? total : 0;
                max = total > max ? total : max;
            }

            printf("%d\n", max);
        }
    }

    return 0;
}