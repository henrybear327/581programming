#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#define WIN 1
#define LOSE 0

char *input_str[5] = {"rock", "paper", "scissors", "lizard", "Spock"};

int main()
{
    int test_cases;
    while(scanf("%d", &test_cases) != EOF) {
        getchar();
        while(test_cases--) {
            char input[100];
            fgets(input, 100, stdin);
            /*printf("%s", input);*/

            char *player_1 = strtok(input, " ");
            char *player_2 = strtok(NULL, "\n");

            /*printf("%s %s\n", player_1, player_2);*/

            int i;
            for(i = 0; i < 5; i++) {
                if(strcmp(player_1, input_str[i]) == 0)
                    break;
            }


            int j;
            for(j = 0; j < 5; j++) {
                if(strcmp(player_2, input_str[j]) == 0)
                    break;
            }

            if(i == j) {
                printf("0\n");
                continue;
            }

            int flag = -1;
            switch(i) {
            case 0:
                if(j == 2 || j == 3)
                    flag = WIN;
                else
                    flag = LOSE;
                break;
            case 1:
                if(j == 0 || j == 4)
                    flag = WIN;
                else
                    flag = LOSE;
                break;
            case 2:
                if(j == 1 || j == 3)
                    flag = WIN;
                else
                    flag = LOSE;
                break;
            case 3:
                if(j == 1 || j == 4)
                    flag = WIN;
                else
                    flag = LOSE;
                break;
            case 4:
                if(j == 0 || j == 2)
                    flag = WIN;
                else
                    flag = LOSE;
                break;

            default:
                break;
            }

            if(flag == WIN)
                printf("1\n");
            else
                printf("2\n");
        }
    }
    return 0;
}