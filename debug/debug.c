#include <stdio.h>
#include <stdlib.h>

int main()
{
    int times;

    scanf("%d", &times);
    getchar();

    while(times--) {
        int input_array[2000] = {0};
        int i, j, count_amount, sum[2000] = {0};
        int answer;

        scanf("%d", &count_amount);

        for(i = 0; i < count_amount; i++) {
            scanf("%d", &input_array[i]);
        }

        for(i = 0; i < count_amount; i++) {
            for(j = i; j <count_amount; j++) {
                sum[i] += input_array[j];

                if(answer < sum[i])
                    answer = sum[i];
            }
        }

        if(answer <= 0) {
            printf("0\n");
        } else {
            printf("%d\n", answer);
        }
    }

    return 0;
}
