#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int test_cases;
    while(scanf("%d", &test_cases) != EOF) {
        getchar();
        while(test_cases--) {
            char input[1000];
            fgets(input, 1000, stdin);

            int book[26] = {0};
            for(int i = 0; input[i] != '\n'; i++) {
                if('a' <= input[i] && input[i] <= 'z')
                    book[input[i] - 'a']++;
                else if('A' <= input[i] && input[i] <= 'Z')
                    book[input[i] - 'A']++;
            }

            int max = 0;
            for(int i = 0; i < 26; i++)
                max = book[i] > max ? book[i] : max;

            for(int i = 0; i < 26; i++)
                if(max == book[i])
                        printf("%c", i + 'A');
            printf("\n");
        }
    }

    return 0;
}