#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//clang -lm w4a.c -o w4a      

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int test_cases;
    while(scanf("%d", &test_cases) != EOF) {
        getchar();
        while(test_cases--) {
            int i = 0, j = 0, x_data[1000] = {0}, y_data[1000] = {0};
            char temp[15];
            while(1) {
                char input = getchar();
                if(input == '-' || ('0' <= input && input <= '9')) {
                    temp[j++] = input;
                } else if(input == ' ') {
                    temp[j] = '\0';
                    x_data[i++] = atoi(temp);
                    j = 0;
                } else if(input == '\n') {
                    temp[j] = '\0';
                    x_data[i++] = atoi(temp);
                    break;
                }
            }

            i = 0, j = 0;
            while(1) {
                char input = getchar();
                if(input == '-' || ('0' <= input && input <= '9')) {
                    temp[j++] = input;
                } else if(input == ' ') {
                    temp[j] = '\0';
                    y_data[i++] = atoi(temp);
                    j = 0;
                } else if(input == '\n') {
                    temp[j] = '\0';
                    y_data[i++] = atoi(temp);
                    break;
                }
            }

            int len = i;
            
            for(int index = 0; index < len; index++) { //This is a very crucial step
                x_data[index] = x_data[index] > 0 ? x_data[index] : -x_data[index];
                y_data[index] = y_data[index] > 0 ? y_data[index] : -y_data[index];
            }
            
            qsort(x_data, len, sizeof(int), compare);
            qsort(y_data, len, sizeof(int), compare);

            /*for(int k = 0; k < len; k++) {
                printf("%d ", x_data[k]);
            }
            printf("\n");
            for(int k = 0; k < len; k++) {
                printf("%d ", y_data[k]);
            }
            printf("\n");
            */

            double total = 0;
            //printf("%d\n", len);
            for(int index = 0; index < len; index++) {
                double x_square = x_data[index] * x_data[index];
                double y_square = y_data[len - 1 - index] * y_data[len - 1 - index];
                //printf("%f %f %f\n", x_square, y_square, x_square + y_square);
                total += sqrt(x_square + y_square);
                //printf("%f\n", total);
            }

            printf("%lld\n", (long long int)total);
        }
    }
    return 0;
}