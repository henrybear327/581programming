#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int input_1, input_2;
    while(scanf("%d %d", &input_1, &input_2) != EOF) {
        int i, input_1_array[2]= {0}, input_2_array[7] = {0};
        for(i = 1; i >= 0; i--) {
            input_1_array[i] = input_1 % 10;
            input_1 /= 10;
        }
        for(i = 6; i >= 0; i--) {
            input_2_array[i] = input_2 % 10;
            input_2 /= 10;
        }

        int count = 0;
        for(i = 0; i < (7 - 1); i++) {
            if(input_1_array[0] == input_2_array[i] && input_1_array[1] == input_2_array[i + 1])
                count++;
        }

        printf("%d\n", count);
    }

    return 0;
}