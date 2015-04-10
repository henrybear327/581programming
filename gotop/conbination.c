#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dfs(int, int, int [], int [], int [], int);

int main()
{
    int step = 0;
    int input[10] = {1, 1, 0};
    int total = 3;

    int record[total], list[total];
    memset(record, 0, sizeof(record));
    int last = -1;

    dfs(step, total, record, list, input, last);

    return 0;
}

void dfs(int step, int total, int record[], int list[], int input[], int last)
{
    if(step == total) {
        for(int i = 0; i < total; i++)
            printf("%d ", list[i]);
        printf("\n");

        return;
    }

    for(int i = 0; i < total; i++) {
        if(record[i] == 0 && last != input[i]) {
            last = input[i];
            record[i] = 1;
            list[step] = input[i];
            dfs(step + 1, total, record, list, input, last);
            record[i] = 0;
        }
    }

}
