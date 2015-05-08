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
        printf("\n");
    }
}

void floodfill_map(int map[][column], int map_processed[][column], int x,
                   int y)
{
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i > 0 && i < row && j > 0 && j < column) {
                if (map_processed[i][j] == 0) {
                    if (map[i][j] != OPEN_FLOODFILL) {
                        map[i][j] = OPEN_FLOODFILL;
                        floodfill_map(map, map_processed, i, j);
                    }
                } else if (map_processed[i][j] > 0)
                    map[i][j] = OPEN;
                else
                    printf("This should never happen!(floodfill_map())\n");
            }
        }
    }
}

int is_bomb(int map[][column], int map_processed[][column], int input_row,
            int input_column)
{
    if (map[input_row][input_column] == BOMB_WITHOUT_FLAG) {
        printf("Game over! You lose!\n");

        // print map
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
                    printf(" ⊕");
                else if (map[i][j] == BOMB_WITH_FLAG)
                    printf(" ⊕");
                else
                    printf("This should never be executed.(print_map())\n");
            }
            printf("\n");
        }

        return true;
    }

    // process the input
    if (map_processed[input_row][input_column] == 0) {
        floodfill_map(map, map_processed, input_row, input_column);
    } else {
        map[input_row][input_column] = OPEN;
    }

    return false;
}

int is_win(int map[][column])
{
    for (int i = 1; i < row; i++) {
        for (int j = 1; j < column; j++) {
            if (!((map[i][j] == OPEN) || (map[i][j] == OPEN_FLOODFILL) ||
                  (map[i][j] == BOMB_WITH_FLAG)))
                return false;
        }
    }

    return true;
}

int place_flag(int map[][column], int x, int y)
{

    if ((map[x][y] == NO_BOMB_WITH_FLAG) || (map[x][y] == BOMB_WITH_FLAG)) {
        // remove flag
        if (map[x][y] == NO_BOMB_WITH_FLAG)
            map[x][y] = NO_BOMB_WITHOUT_FLAG;
        if (map[x][y] == BOMB_WITH_FLAG)
            map[x][y] = BOMB_WITHOUT_FLAG;

        return true;
    } else if ((map[x][y] == NO_BOMB_WITHOUT_FLAG) ||
               (map[x][y] == BOMB_WITHOUT_FLAG)) {
        // place flag
        if (map[x][y] == NO_BOMB_WITHOUT_FLAG)
            map[x][y] = NO_BOMB_WITH_FLAG;
        if (map[x][y] == BOMB_WITHOUT_FLAG)
            map[x][y] = BOMB_WITH_FLAG;

        return true;
    } else {
        return false;
    }
}

int main()
{
    // game init

    srand(time(NULL));

#if DEBUG
    printf("Debug mode on!\n\n");
#else
    printf("Debug mode off!\n\n");
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
    print_map(map, map_processed);

    while (1) {
        int choice, input_row, input_column;
        printf("What do you want to do now? 1 -> place/remove flag 2 -> pick a "
               "location to flip over: ");
        scanf("%d", &choice);
        // pick location

        if (choice == 1 && choice == 2) {
            printf("Please enter your location of choice: ");
            scanf("%d %d", &input_row, &input_column);
            if(!((1 <= input_row && input_row < row) && (1 <= input_column && input_column < column))) {
            	printf("The input is out of bound.\n");
            	continue;
            }
        }

        switch (choice) {
        case 1:
            // place/remove flag
            clear_screen();

            if (place_flag(map, input_row, input_column) == true) {
                printf("Flag placed/removed.\n");
            } else {
                printf("Flag can't be added.\n");
            }
            break;
        case 2:
            clear_screen();

            if (is_bomb(map, map_processed, input_row, input_column) == true) {
                return 0;
            }
            break;
        default:
            clear_screen();
            printf("Invalid input\n");
        }

#if DEBUG
        // print generated map
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (i == 0 || j == 0)
                    printf("%2d", map[i][j]);
                else if (map[i][j] == NO_BOMB_WITHOUT_FLAG ||
                         map[i][j] == NO_BOMB_WITH_FLAG ||
                         map[i][j] == OPEN_FLOODFILL || map[i][j] == OPEN)
                    printf(" ■");
                else if (map[i][j] == BOMB_WITHOUT_FLAG || map[i][j] == BOMB_WITH_FLAG)
                    printf(" ⊕");
            }
            printf("\n");
        }
#endif
        print_map(map, map_processed);
        if (is_win(map) == true) {
            printf("You win!!!\n");
            return 0;
        }
    }

    return 0;
}