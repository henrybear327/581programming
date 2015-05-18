#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int pay;
    int selected;
    int unselected;
} INFO;

int main()
{
    int elements;
    while (scanf("%d", &elements) != EOF && elements) {
        INFO input[elements];
        memset(input, 0, sizeof(input));
        for (int i = 0; i < elements; i++)
            scanf("%d", &input[i].pay);

        input[0].selected = input[0].pay;
        input[0].unselected = 0;
        for (int i = 1; i < elements; i++) {
            input[i].selected = input[i].pay + input[i - 1].unselected;
            input[i].unselected = (input[i - 1].selected > input[i - 1].unselected
                                   ? input[i - 1].selected
                                   : input[i - 1].unselected);
        }
        printf("%d\n", input[elements - 1].selected > input[elements - 1].unselected
               ? input[elements - 1].selected
               : input[elements - 1].unselected);
    }

    return 0;
}