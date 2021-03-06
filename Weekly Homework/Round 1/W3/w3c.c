#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quicksort(int, int, int []);

int main()
{
    int n;
    while(scanf("%d", &n) != EOF && n) {
        int i, enemies[n], my_soldiers[n];
        for(i = 0; i < n; i++)
            scanf("%d", &enemies[i]);
        for(i = 0; i < n; i++)
            scanf("%d", &my_soldiers[i]);

        quicksort(0, n - 1, enemies);
        quicksort(0, n - 1, my_soldiers);

        int index_enemies = 0, index_my_soldiers = 0, win = 0;
        while(index_enemies < n && index_my_soldiers < n) {
            if(my_soldiers[index_my_soldiers] > enemies[index_enemies]) {
                win++;
                index_enemies++;
                index_my_soldiers++;
                continue;
            } else if(my_soldiers[index_my_soldiers] <= enemies[index_enemies]) {
                index_my_soldiers++;
                continue;
            }
        }

        printf("%d\n", win);
    }

    return 0;
}

void quicksort(int low, int high, int data[])
{
    if(low >= high)
        return;

    int pivot = low, target = high;
    while(pivot != target) {
        if(pivot < target && data[pivot] > data[target]) {
            int temp = data[pivot];
            data[pivot] = data[target];
            data[target] = temp;

            temp = pivot;
            pivot = target;
            target = temp;
        } else if(pivot > target && data[target] > data[pivot]) {
            int temp = data[pivot];
            data[pivot] = data[target];
            data[target] = temp;

            temp = pivot;
            pivot = target;
            target = temp;
        }

        if(pivot < target)
            pivot++;
        else
            pivot--;
    }

    quicksort(pivot + 1, high, data);
    quicksort(low, pivot - 1, data);

    return;
}