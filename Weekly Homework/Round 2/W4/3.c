#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct gateTemperature {
    int upper;
    int lower;
} Data;

int main()
{
    int gates;
    while(scanf("%d", &gates) != EOF && gates != 0) {
        Data input[gates];
        for(int i = 0; i < gates; i++)
            scanf("%d %d", &input[i].upper, &input[i].lower);

        int to_upper = abs(input[0].upper - 1000), to_lower = abs(input[0].lower - 1000);
        for(int i = 1; i < gates; i++) {
            int one = abs(input[i].upper - input[i - 1].upper);
            int two = abs(input[i].lower - input[i - 1].lower);
            int three = abs(input[i].upper - input[i - 1].lower);
            int four = abs(input[i].lower - input[i - 1].upper);
            //printf("%d %d %d %d\n", one, two, three, four);

            //printf("%d %d\n",(to_lower + two), (to_upper + four));
            int to_upper_init = to_upper, to_lower_init = to_lower;
            to_upper = (to_upper + one) < (to_lower + three) ? (to_upper + one) : (to_lower + three);
            to_lower = (to_lower_init + two) < (to_upper_init + four) ? (to_lower_init + two) : (to_upper_init + four);

            //printf("%d %d\n", to_upper, to_lower);
        }

        printf("%d\n", to_upper < to_lower ? to_upper : to_lower);
    }

    return 0;
}