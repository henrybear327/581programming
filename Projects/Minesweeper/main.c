#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

/*
clang-format-3.5 -i -style=LLVM main.c && astyle --style=linux main.c && clang
-Wall -Wextra main.c -o main
*/

#define EMPTY 0
#define BOMB -1

#define CHOSEN -2
#define FLAG_ON_BOMB -3
#define FLAG_ON_EMPTY -4

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

void generate_map(int map[][column], int bomb_around_count_map[][column])
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

    // print map
    print_row_number();
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (j == 0)
                printf("%2d ", i + 1);
            printf("■ ");
        }
        printf("\n");
    }

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

    // calculate map with bomb around
    print_row_number();
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (map[i][j] == EMPTY)
                bomb_around_count_map[i][j] = bomb_around_count(map, i, j);
            else
                bomb_around_count_map[i][j] = BOMB;
        }
        printf("\n");
    }

#if DEBUG
    // show map with bomb around
    print_row_number();
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (j == 0)
                printf("%2d ", i + 1);
            printf("%d ", bomb_around_count_map[i][j]); // can use lazy DP
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

void place_flag(int map[][column], int x, int y) {}

int main()
{
    srand(time(NULL));

    printf("Please enter row , column, and bombs to plant:\n");
    scanf("%d %d %d", &row, &column, &bomb_count);

    int map[row][column], bomb_around_count_map[row][column];
    memset(map, EMPTY, sizeof(map));
    generate_map(map, bomb_around_count_map);

    int x, y;
    do {
        int choice;
        printf("Do you want to 1. place/remove flag 2.flip ?\n");
        scanf("%d", &choice);
        if (choice == 1) {
            place_flag(map, x, y);
        }

        if (choice == 2) {
            printf("Please enter the location x, y to flip over:\n");
            scanf("%d %d", &x, &y);
            x--;
            y--;
        }
    } while (is_bomb(map, x, y) == false);

    return 0;
}