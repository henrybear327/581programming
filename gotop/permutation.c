#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dfs(int, int, int [], int []);

int main()
{
    int step = 0;
    int total = 4;
    int record[total], list[total];
    memset(record, 0, sizeof(record));

    dfs(step, total, record, list);

    return 0;
}

void dfs(int step, int total, int record[], int list[])
{
    if(step == total) {
        for(int i = 0; i < total; i++)
            printf("%d ", list[i]);
        printf("\n");

        return;
    }

    for(int i = 0; i < total; i++) {
        if(record[i] == 0) {
            //printf("Step %d, i %d\n", step, i);
            record[i] = 1;
            list[step] = i;
            dfs(step + 1, total, record, list);
            record[i] = 0;
        }
    }

}
