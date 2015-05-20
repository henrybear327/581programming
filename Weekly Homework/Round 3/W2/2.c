#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char input[2000];
    while (fgets(input, 2000, stdin) != NULL) {
        input[strlen(input) - 1] = '\0';
        for (int i = 0; i < (int)strlen(input);) {
            int num = -1, index = 0;
            char token[2000];
            if ('1' <= input[i] && input[i] <= '9') {
                num = input[i] - '0';
                i++;
                while (isalpha(input[i])) {
                    token[index++] = input[i];
                    i++;
                }
                token[index] = '\0';
            }
            for (int j = 0; j < num; j++)
                printf("%s", token);
        }
        printf("\n");
    }

    return 0;
}