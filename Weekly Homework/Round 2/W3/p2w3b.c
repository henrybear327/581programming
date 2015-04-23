#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *lower_to_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char *upper_to_lower = "abcdefghijklmnopqrstuvwxyz";
char *digit_shift = "1234567890";

int main()
{
    char input[1000];
    while(fgets(input, 1000, stdin) != NULL) {
        int i = 0;
        while(input[i] != '\0') {
            if('a' <= input[i] && input[i] <= 'z') {
                printf("%c", lower_to_upper[25 - (input[i] - 'a')]);
            } else if('A' <= input[i] && input[i] <= 'Z') {
                printf("%c", upper_to_lower[25 - (input[i] - 'A')]);
            } else if('0' <= input[i] && input[i] <= '9') {
                printf("%c", digit_shift[input[i] - '0']);
            } else {
                printf("%c", input[i]);
            }
            i++;
        }

    }


    return 0;
}