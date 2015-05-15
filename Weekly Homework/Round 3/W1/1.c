#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    int test_cases;
    scanf("%d", &test_cases);
    while (test_cases--) {
        int total;
        scanf("%d", &total);

        int max[3], weight[3];
        scanf("%d %d %d %d %d %d", &max[0], &max[1], &max[2], &weight[0],
              &weight[1], &weight[2]);

        bool flag = false;
        for (int i = 0; i <= max[0] && flag == false; i++) {
            for (int j = 0; j <= max[1] && flag == false; j++) {
                for (int k = 0; k <= max[2] && flag == false; k++) {
                    if (total == (i * weight[0] + j * weight[1] + k * weight[2])) {
                        printf("yes\n");
                        flag = true;
                        break;
                    }
                }
            }
        }

        if (flag == false)
            printf("no\n");
    }

    return 0;
}