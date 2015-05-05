/*
寫個程式練習macro and define
Req:
1. 陣列大小配合迴圈必須使用define
2. 定義至少三個macro, define若干指令
*/

#include <stdio.h>

#define SIZE 10
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

#define SUM1(total, src, max_size)                                             \
  do {                                                                         \
    total = 0;                                                                 \
    for (int i = 0; i < (max_size); i++) {                                     \
      total += src[i];                                                         \
    }                                                                          \
  } while (0)

#define SUM2(total, src, max_size)                                             \
  ({                                                                           \
    total = 0;                                                                 \
    for (int i = 0; i < (max_size); i++) {                                     \
      total += src[i];                                                         \
    }                                                                          \
    total;                                                                     \
  })

int main()
{
    int array[SIZE] = { 0 };
    printf("Enter 10 numbers : ");
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &array[i]);
    }

    printf("Max of the first and second element : %d\n", MAX(array[0], array[1]));
    printf("Min of the first and second element : %d\n", MIN(array[0], array[1]));

    int sum = 0;

    SUM1(sum, array, SIZE);
    printf("The sum of the input : %d\n", sum);

    printf("The sum of the input : %d\n", SUM2(sum, array, SIZE));

    return 0;
}