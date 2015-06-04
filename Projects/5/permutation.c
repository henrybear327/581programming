#include <stdio.h>

/*clang-format-3.5 -i -style=LLVM  permutation.c && astyle --style=linux
 * permutation.c && clang -Wall -Wextra permutation.c -o permutation
 * Formatted
 * /home/ubuntu/workspace/C/Homework/581programming/Projects/5/permutation.c*/

/* Function to swap values at two pointers */
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(char *a, int i, int n)
{
    int j;
    if (i == n) {
        for (int i = 0; i <= n; i++) {
            if (i != n)
                printf("%c ", a[i]);
            else
                printf("%c\n", a[i]);
        }
    } else {
        for (j = i; j <= n; j++) {
            swap((a + i), (a + j));
            permute(a, i + 1, n);
            swap((a + i), (a + j)); // backtrack
        }
    }
}

/* Driver program to test above functions */
int main()
{
    char a[] = "0123456789";
    permute(a, 0, 9);
    getchar();
    return 0;
}