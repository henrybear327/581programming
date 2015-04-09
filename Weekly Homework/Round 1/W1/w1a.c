#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*astyle --style=linux w1a.c && clang -std=gnu89 -Weverything w1a.c -o w1a*/

int main()
{
    int test_cases, flag = 0;
    while(scanf("%d",&test_cases) != EOF && test_cases > 0) {
        while(test_cases--) {
            int input[3], d, leading_power = 2;
            scanf("%d%d%d%d", &input[2], &input[1], &input[0], &d); /*input[0~2] corresponds to c, b, a*/
            int data[21];
            memset(data, 0, sizeof(data));
            int i;
            for(i = 0; i <= 2; i++)
                data[i] = input[i];

            while(d-- != 1) {
                int j, temp[21];
                memset(temp, 0, sizeof(temp));
                for(i = 0; i <= leading_power; i++) { /*drives data*/
                    for(j = 0; j <= 2; j++) { /*drives input*/
                        temp[i + j] += (input[j] * data[i]);
                    }
                }
                leading_power += 2;
                for(i = 0; i <= leading_power; i++)
                    data[i] = temp[i];
            }

            for(i = leading_power; i >= 0; i--) {
                if(i != 0)
                    printf("%d ", data[i]);
                else
                    printf("%d\n", data[i]);
            }
        }
        if(flag == 1)
            break;
    }

    return 0;
}