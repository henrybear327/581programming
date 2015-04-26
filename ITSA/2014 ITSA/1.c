#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int test_cases;
    while(scanf("%d", &test_cases) != EOF) {
        while(test_cases--) {
            int input[4] = {0};
            int i;
            for(i = 0; i < 4; i++)
                scanf("%d", &input[i]);

            int a_d = input[0] + input[3];
            int ad_c2 = input[0] * input[3] - input[2] * input[2];

            double x = (double)(a_d + sqrt(a_d * a_d - 4 * ad_c2)) / 2;
            double y = (double)(a_d - sqrt(a_d * a_d - 4 * ad_c2)) / 2;

            if(x < y) {
                double temp = y;
                y = x;
                x = temp;
            }

            printf("%.2f %.2f\n", x, y);
        }
    }
    return 0;
}