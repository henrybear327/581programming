#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int count;
    scanf("%d", &count);
    int i, data[count * 2];
    for(i = 0; i < count * 2; i++)
        scanf("%d", &data[i]);
    
    count *= 2;
    int record[60] = {0}, max = 0;
    for(i = 0; i < count; i += 2) {
        int j;
        for(j = data[i]; j < data[i + 1]; j++) {
            record[j]++;
            max = record[j] > max ? record[j] : max;
        }
    }
    
    printf("%d\n", max);
    return 0;
}