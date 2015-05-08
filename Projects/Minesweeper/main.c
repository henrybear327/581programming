#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

/*
clang-format-3.5 -i -style=LLVM main.c && astyle --style=linux main.c && clang
-Wall -Wextra main.c -o main
*/

// special characters □⊕■

int row, column;

/*
#define NO_BOMB 0
#define BOMB   -1
*/

#define OPEN 10
#define OPEN_FLOODFILL 11

#define NO_BOMB_WITH_FLAG 1
#define NO_BOMB_WITHOUT_FLAG 0

#define BOMB_WITH_FLAG -2
#define BOMB_WITHOUT_FLAG -1

#define DEBUG 1

void clear_screen()
{
#if DEBUG
    printf("clear_screen()\n");
#endif

    printf("%c[2J", 27);
}

int bomb_around(int map[][column], int x, int y)
{
    int bomb_count = 0;
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i > 0 && i < row && j > 0 && j < column &&
                map[i][j] == BOMB_WITHOUT_FLAG)
                bomb_count++;
        }
    }

    return bomb_count;
}

void generate_maps(int map[][column], int map_processed[][column],
                   int bomb_to_plant)
{
    // generate row numbering
    for (int i = 0; i < column; i++) {
        map[0][i] = i;
    }

    // generate column numbering
    for (int i = 0; i < row; i++) {
        map[i][0] = i;
    }

    // generate bomb map
    while (bomb_to_plant) {
        int rand_row = rand() % (row - 1) + 1,
            rand_column = rand() % (column - 1) + 1;
        if (map[rand_row][rand_column] == NO_BOMB_WITHOUT_FLAG) {
            map[rand_row][rand_column] = BOMB_WITHOUT_FLAG;
            bomb_to_plant--;
        }
    }

#if DEBUG
    // print generated map
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (i == 0 || j == 0)
                printf("%2d", map[i][j]);
            else if (map[i][j] == NO_BOMB_WITHOUT_FLAG)
                printf(" ■");
            else if (map[i][j] == BOMB_WITHOUT_FLAG)
                printf(" ⊕");
        }
        printf("\n");
    }
#endif

    // generate map_processed
    for (int i = 1; i < row; i++) {
        for (int j = 1; j < column; j++) {
            if (map[i][j] == BOMB_WITHOUT_FLAG)
                map_processed[i][j] = BOMB_WITHOUT_FLAG;
            else
                map_processed[i][j] = bomb_around(map, i, j);
        }
    }
#if DEBUG
    // print generated map
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (i == 0 || j == 0)
                printf("%2d", map[i][j]);
            else if (map_processed[i][j] == BOMB_WITHOUT_FLAG)
                printf(" ⊕");
            else
                printf("%2d", map_processed[i][j]);
        }
        printf("\n");
    }
#endif
}

void print_map(int map[][column], int map_processed[][column])
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (i == 0 || j == 0)
                printf("%2d", map[i][j]);
            else if (map[i][j] == OPEN)
                printf("%2d", map_processed[i][j]);
            else if (map[i][j] == OPEN_FLOODFILL)
                printf(" □");
            else if (map[i][j] == NO_BOMB_WITHOUT_FLAG)
                printf(" ■");
            else if (map[i][j] == NO_BOMB_WITH_FLAG)
                printf(" P");
            else if (map[i][j] == BOMB_WITHOUT_FLAG)
                printf(" ■");
            else if (map[i][j] == BOMB_WITH_FLAG)
                printf(" P");
            else
                printf("This should never be executed.(print_map())\n");
        }
    }
}

void is_bomb() {}

int main()
{
    // game init

    srand(time(NULL));

#if DEBUG
    printf("Debug mode on!\n\n");
#endif

    // game start
    int bomb_to_plant;
    printf("What size do you want to play? (row, column, bomb) --> ");
    scanf("%d %d %d", &row, &column, &bomb_to_plant);
    row++;
    column++;

    int map[row][column], map_processed[row][column];
    memset(map, 0, sizeof(map));
    memset(map_processed, 0, sizeof(map_processed));

    generate_maps(map, map_processed, bomb_to_plant);

    return 0;
}