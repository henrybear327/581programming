/*
寫一個quick sort的副程式

貧民版: 只能運作整數陣列(70%)
一般型:只能自己定義的structure(80%)
豪華型: 運用pointer to function達到qsort一樣功能(110%, 若random pivot再加10%)
*/

//astyle --style=linux main.c && clang -Wall -Wextra main.c -o main

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
#if DEBUG
    //zd for printing size_t
    printf("arguments : %p, %zd, %zd, %p\n", mem_start, total_member, member_size, cmp);
#endif

    if(total_member > 1) {
        void *left = mem_start, *right = mem_start + (total_member - 1) * member_size;
        void *pivot = mem_start;

        while(left <= right) {
            while(left <= pivot && cmp(left, pivot) < 0)
                left += member_size;
            while(right >= pivot && cmp(right, pivot) > 0)
                right -= member_size;

            //printf("%p %p\n",left, right);

            if(left <= right) {
                void *temp = malloc(member_size);
                memcpy(temp, left, member_size);
                memcpy(left, right, member_size);
                memcpy(right, temp, member_size);

                left += member_size;
                right -= member_size;
            }
        }

        q_sort(mem_start, (right - mem_start) / member_size + 1, member_size, cmp);
        q_sort(left, total_member - ((left - mem_start) / member_size + 1), member_size, cmp);
    } else {
        //printf("member_size <= 1\n");
        //only one or less element, no need to sort
        return;
    }
}