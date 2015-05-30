#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int test_case;
    while (scanf("%d", &test_case) != EOF) {
        while (test_case--) {
            int total_weight, total_item;
            scanf("%d %d", &total_weight, &total_item);

            int total = 0;
            int DP[200000 + 1] = { 0 };
            // The previously given set of weight can generate certain set of numbers.
            // Given a new weight, add it to all of the previously set of numbers.
            for (int i = 0; i < total_weight; i++) {
                int temp;
                scanf("%d", &temp);
                // printf("DP %d\n", temp);

                for (int j = total; j > 0; j--) {
                    if (DP[j] == 1) {
                        DP[j + temp] = 1;
                    }
                }
                DP[temp] = 1;
                total += temp;
            }

            total = 0;
            for (int i = 0; i < total_item; i++) {
                int temp;
                scanf("%d", &temp);
                if (DP[temp] == 1) {
                    // printf("temp = %d\n", temp);
                    total++;
                }
            }

            printf("%d\n", total);
        }
    }
    return 0;
}
/*
3
2 5
3 5
1 5 2 7 8 
3 5
2 5 2
20 1 2 4 9
4 20
1 2 3 4
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
3
2 5
3 5
1 5 2 7 8
3 5
2 5 2
20 1 2 4 9
10 30
20 1 10 18 13 20 9 11 14 6
13 94 45 89 45 9 100 68 22 2 63 32 58 95 20 88 13 22 88 67 94 5 11 99 12 31 27 78 70 64

*/