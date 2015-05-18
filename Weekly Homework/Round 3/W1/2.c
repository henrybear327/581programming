#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    int elements;
    while (scanf("%d", &elements) != EOF) {
        int data[elements];
        for (int i = 0; i < elements; i++)
            scanf("%d", &data[i]);
    }

    return 0;
}