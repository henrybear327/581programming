/*
寫一個quick sort的副程式

貧民版: 只能運作整數陣列(70%)
一般型:只能自己定義的structure(80%)
豪華型: 運用pointer to function達到qsort一樣功能(110%, 若random pivot再加10%)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DEBUG 0

void q_sort(void *mem_start, size_t total_member, size_t member_size,
            int (*cmp)(const void *, const void *));

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

#define SIZE 10

int main()
{
    int array[SIZE] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    for(int i = 0; i < SIZE; i++)
        printf("%d ", array[i]);
    printf("\n");

    //printf("array %p\n", array);

    q_sort(array, SIZE, sizeof(int), cmp);

    for(int i = 0; i < SIZE; i++)
        printf("%d ", array[i]);
    printf("\n");

    return 0;
}

void q_sort(void *mem_start, size_t total_member, size_t member_size,
            int (*cmp)(const void *, const void *))
{
    srand (time(NULL));
    if(total_member > 1) {
        //todo : random pivot
        void *pivot = mem_start;
        //memory is displayed as hexidecimal, thus 60 + 16 = 70!!
        void *left = mem_start, *right = mem_start + (total_member - 1) * member_size;

#if DEBUG
        //zd for printing size_t
        printf("arguments : %p, %zd, %zd, %p\n", mem_start, total_member, member_size, cmp);
        printf("pivot = %p\n", pivot);
        printf("left  = %p, right = %p\n", left, right);

        for(void *ptr = left; ptr <= right; ptr += member_size) {
            printf("%p ", ptr);
        }
        printf("\n");
#endif

        while(left <= right) {
            //cmp >= 1 means lefthand side is bigger than righthand side
            while(cmp(left, pivot) < 1)
                left += member_size;
            while(cmp(right, pivot) >= 1)
                right -= member_size;

            if(left <= right) {
                //left <--> right
                void *temp = malloc(member_size);
                memcpy(temp, left, member_size);
                memcpy(left, right, member_size);
                memcpy(right, temp, member_size);

                left += member_size;
                right -= member_size;
            }

            size_t member_first_to_right = ((right - mem_start) / member_size) + 1;
            size_t member_left_to_last = total_member - member_first_to_right;

#if DEBUG
            printf("%p %p\n", left, right);
            printf("%lu %lu\n", (left - mem_start) / member_size, (right - mem_start) / member_size);
            printf("FR %zd, LL %zd\n",member_first_to_right, member_left_to_last);
            getchar();
#endif

            q_sort(mem_start, member_first_to_right, member_size, cmp);
            q_sort(left, member_left_to_last, member_size, cmp);
        }

    } else {
        //only one or less element, no need to sort
        return;
    }

}