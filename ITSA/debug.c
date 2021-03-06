#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char input[1000];
    fgets(input, 1000, stdin);

    int i, count[26] = {0};
    for (i = 0; i < strlen(input) - 1; i++) {
        if ('a' <= input[i] && input[i] <= 'z')
            count[input[i] - 'a']++;
        if ('A' <= input[i] && input[i] <= 'Z')
            count[input[i] - 'A']++;
    }

    for (i = 0; i < 26; i++) {
        if (i != 25)
            printf("%d ", count[i]);
        else
            printf("%d\n", count[i]);
    }

    return 0;
}
