/*
寫一個quick sort的副程式

貧民版: 只能運作整數陣列(70%)
一般型:只能自己定義的structure(80%)
豪華型: 運用pointer to function達到qsort一樣功能(110%, 若random pivot再加10%)
*/

// clang-format-3.5 -i -style=LLVM main.c && astyle --style=linux main.c &&
// clang -Wall -Wextra main.c -o main

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DEBUG 0

//用跟stdlib一樣的宣告形式
void q_sort(void *mem_start, size_t total_member, size_t member_size,
            int (*cmp)(const void *, const void *));

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

#define SIZE 10

int main()
{
    /*
    int array[SIZE] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    for (int i = 0; i < SIZE; i++)
        printf("%d ", array[i]);
    printf("\n");
    */
    // printf("array %p\n", array);

    //呼叫方式 --> q_sort(其他都一樣)
    /*
    char input[100] = { 0 };
    while (fgets(input, 100, stdin) != NULL) {
        int array[(int)strlen(input) - 1];

        for (int i = 0; i < (int)strlen(input) - 1; i++) {
            array[i] = input[i] - '0';
            // printf("%d ", array[i]);
        }
        // printf("\n");

        q_sort(array, (int)strlen(input) - 1, sizeof(int), cmp);

        for (int i = 0; i < (int)strlen(input) - 1; i++)
            printf("%d ", array[i]);
        printf("\n");
    }
    */
    int n = 10, count = 0;
    while (1) {
        int input[n];
        for (int i = 0; i < n; i++) {
            if (scanf("%d", &input[i]) == EOF)
                exit(0);
        }
        q_sort(input, n, sizeof(int), cmp);
        
        for (int i = 0; i < n; i++)
            printf("%d ", input[i]);
        printf(" %d\n", ++count);
        
    }

    return 0;
}

void q_sort(void *mem_start, size_t total_member, size_t member_size,
            int (*cmp)(const void *, const void *))
{
    // zd for printing size_t
    // printf("arguments : %p, %zd, %zd, %p\n", mem_start, total_member,
    // member_size, cmp);
    if (total_member > 1) {
        void *pivot = mem_start;
        void *to_compare = mem_start + (total_member - 1) * member_size;

#if DEBUG
        printf("Init pivot = %p, to_compare = %p\n\n", pivot, to_compare);
        getchar();
#endif

        while (pivot != to_compare) {
            if ((cmp(pivot, to_compare) > 0 && to_compare > pivot) ||
                (cmp(to_compare, pivot) > 0 &&
                 pivot > to_compare)) { // pivot > to_compare
                // pivot <-> to_compare
                void *temp = malloc(member_size);
                memcpy(temp, pivot, member_size);
                memcpy(pivot, to_compare, member_size);
                memcpy(to_compare, temp, member_size);
                free(temp);

                temp = pivot;
                pivot = to_compare;
                to_compare = temp;

                if (pivot < to_compare)
                    to_compare -= member_size;
                else
                    to_compare += member_size;
            } else {
                if (pivot < to_compare)
                    to_compare -= member_size;
                else
                    to_compare += member_size;
            }
        }

#if DEBUG
        printf("After : pivot = %p, to_compare = %p\n", pivot, to_compare);
#endif
        // printf("First Call\n");
        q_sort(mem_start, ((pivot - mem_start) / member_size), member_size, cmp);

        // printf("Second Call\n");
        // printf("%lu\n", (to_compare - mem_start) / member_size);
        q_sort(pivot + member_size,
               (total_member - ((to_compare - mem_start) / member_size + 1)),
               member_size, cmp);
    } else {
        // printf("member_size <= 1\n");
        // only one or less element, no need to sort
        return;
    }
}
