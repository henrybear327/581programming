#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

/*
clang-format-3.5 -i -style=LLVM main.c && astyle --style=linux main.c && clang
-Wall -Wextra main.c -o main
*/

#define BOMB 1
#define EMPTY 0
#define CHOSEN 2

#define DEBUG 1

int row, column, bomb_count;

int bomb_around_count(int map[][column], int x, int y)
{
    int count = 0;
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i >= 0 && i < row && j >= 0 && j < column && map[i][j] == BOMB)
                count++;
        }
    }
    return count;
}

void print_row_number()
{
    for (int i = 0; i <= row; i++) {
        if (i == 0)
            printf("  ");
        else
            printf("%2d", i);
    }
    printf("\n");
}

void generate_map(int map[][column])
{
    while (bomb_count--) {
        int x = rand() % column;
        int y = rand() % row;
        if (map[x][y] == EMPTY) {
            map[x][y] = BOMB;
        } else {
            bomb_count++;
            continue;
        }
    }
    printf("Map generated\n");

#if DEBUG
    print_row_number();
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (j == 0)
                printf("%2d ", i + 1);
            if (map[i][j] == EMPTY)
                printf("■ ");
            else if (map[i][j] == BOMB)
                printf("⊕ ");
        }
        printf("\n");
    }
#endif

#if DEBUG
    // show map with bomb around
    print_row_number();
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (j == 0)
                printf("%2d ", i + 1);
            if (map[i][j] == EMPTY)
                printf("%d ", bomb_around_count(map, i, j)); // can use lazy DP
            else
                printf("⊕ ");
        }
        printf("\n");
    }
#endif
}

void clear_screen()
{
#if DEBUG
    printf("clear_screen()\n");
#endif

    printf("%c[2J", 27);
}

int is_bomb(int map[][column], int x, int y)
{
    clear_screen();
    printf("x = %d y = %d\n", x + 1, y + 1);

    if (map[x][y] == BOMB) {
        printf("You lose\n");

        print_row_number();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (j == 0)
                    printf("%2d ", i + 1);
                if (map[i][j] == EMPTY)
                    printf("■ ");
                else if (map[i][j] == BOMB)
                    printf("⊕ ");
                else if (map[i][j] == CHOSEN)
                    printf("%d ", bomb_around_count(map, i, j)); // can use lazy DP
            }
            printf("\n");
        }
        return true;
    } else {
        map[x][y] = CHOSEN;

        // print current map

        print_row_number();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (j == 0)
                    printf("%2d ", i + 1);
                if (map[i][j] == CHOSEN)
                    printf("%d ", bomb_around_count(map, i, j)); // can use lazy DP
                else
                    printf("■ ");
            }
            printf("\n");
        }

        return false; // no bomb
    }
}

int main()
{
    srand(time(NULL));

    printf("Please enter row , column, and bombs:\n");
    scanf("%d %d %d", &row, &column, &bomb_count);

    int map[row][column];
    memset(map, EMPTY, sizeof(map));
    generate_map(map);

    int x, y;
    do {
        printf("Please enter the location x, y to flip over:\n");
        scanf("%d %d", &x, &y);
        x--;
        y--;
    } while (is_bomb(map, x, y) == false);

    return 0;
}