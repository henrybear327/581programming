#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DEFAULT        0
#define RESTRICTED_NUM 1
#define RESTRICTED_ALP 2
#define CONFLICT       3

#define UNDETERMINED 4
#define IS_ILLEGAL   5
#define IS_INTEGER   6
#define IS_FLOAT     7
#define IS_ALPHBET   8

char *flag_code[4] = {"DEFAULT", "RESTRICTED_NUM", "RESTRICTED_ALP", "CONFLICT"};
char *input_type_str[5] = {"UNDETERMINED", "IS_ILLEGAL", "IS_INTEGER", "IS_FLOAT", "IS_ALPHBET "};

void check_type(int, char **, int *, int *);

/*
Write a program myadd such that user in command line type myadd n1 [n2] [n3]….
The program compute the sum of these number.

Basic requirement: the numbers are 32-bit integer
bonus: the numbers may have different types
*/

int main(int argc, char *argv[])
{

    /*
    //This is how the argc and argv[] are passed as arguments
    printf("argc = %d\n", argc);
    for(int i = 0; i < argc; i++) {
        printf("%d --> %s\n", i, argv[i]);
    }
    printf("\n");
    */

    //determine which kind of input is it and check you illegal input
    //intended types : integer, float, character
    //on error --> flag = CONFLICT

    printf("This program can only perform addition on intergers, floating points, and alphbet/strings.\n\n");

    if(argc == 1) {
        printf("There is no input. Please enter some numbers.\n");
        return 0;
    }

    int input_type = UNDETERMINED, flag = DEFAULT; //default
    check_type(argc, argv, &input_type, &flag);
    printf("\n");

    if(flag == CONFLICT || input_type == IS_ILLEGAL) {
        printf("Sorry, this program can't perform this kind of calculation.\n");
        return 0;
    }

    printf("-----------------------------------------------------------\n\n");

    //Calculate the sum of 32-bit integers
    if(input_type == IS_INTEGER) {
        long long int sum = 0;
        for(int i = 1; i < argc; i++)
            sum += atoi(argv[i]);
        printf("integer sum = %lld\n", sum);
    } else if(input_type == IS_FLOAT) {
        float sum = 0;
        for(int i = 1; i < argc; i++)
            sum += atof(argv[i]);
        printf("float sum = %.3f\n", sum);
    } else if(input_type == IS_ALPHBET) {
        long long int sum = 0;
        for(int i = 1; i < argc; i++)
            for(int j = 0; j < (int) strlen(argv[i]); j++)
                sum += argv[i][j];
        printf("alphbet ascii code sum = %lld\n", sum);
    }
    return 0;
}

void check_type(int argc, char **argv, int *input_type, int *flag)
{
    /*
    1. if any interger/float or character is detected --> flag -> restricted, input_type -> according to type detected
    2. if the flag is changed to restricted, then check for conflicting type only
    */

    for(int i = 1; i < argc; i++) {
        //printf("Input %d\n", i - 1);
        for(int j = 0; j < (int)strlen(argv[i]); j++) {
            //printf("Input %d, position %d. ", i, j);
            if(isalnum(argv[i][j]) == 0 && argv[i][j] != '.' && argv[i][j] != '-') {
                *input_type = IS_ILLEGAL;
                printf("Illigal input detected in input %d\n", i - 1);
                return;
            } else {
                if(i == 1) {
                    //printf("argc = 1\n");
                    //only possibilities --> number, character
                    if(isdigit(argv[i][j])) {
                        *flag = RESTRICTED_NUM;
                        if(*input_type != IS_FLOAT)
                            *input_type = IS_INTEGER;
                    } else if(argv[i][j]== '.') {
                        if(strlen(argv[i]) != 1) {
                            *flag = RESTRICTED_NUM;
                            *input_type = IS_FLOAT;
                        } else {
                            *input_type = IS_ILLEGAL;
                            printf("Only . in input %d\n", i - 1);
                            return;
                        }
                    } else {
                        if(argv[i][j] == '-' && strlen(argv[i]) != 1) {
                            *flag = RESTRICTED_NUM;
                            *input_type = IS_INTEGER;
                        } else if(argv[i][j] == '-' && strlen(argv[i]) == 1) {
                            *input_type = IS_ILLEGAL;
                            printf("Only - in input %d\n", i - 1);
                            return;
                        } else {
                            *flag = RESTRICTED_ALP;
                            *input_type = IS_ALPHBET;
                        }
                    }
                } else {
                    //starting from second number
                    if(isdigit(argv[i][j]) && *flag == RESTRICTED_ALP) {
                        printf("Mixed number with characters.\n");
                        *flag = CONFLICT;
                        *input_type = IS_ILLEGAL;
                        return;
                    } else if(argv[i][j] == '.' && *input_type == IS_INTEGER) {
                        *input_type = IS_FLOAT;
                    } else if(isalpha(argv[i][j]) && *flag == RESTRICTED_NUM) {
                        printf("Mixed number with characters.\n");
                        *flag = CONFLICT;
                        *input_type = IS_ILLEGAL;
                        return;
                    } else if(argv[i][j] == '-' && *flag == RESTRICTED_ALP) {
                        printf("Illigal input\n");
                        *flag = CONFLICT;
                        *input_type = IS_ILLEGAL;
                        return;
                    } else {
                        if((argv[i][j] == '-' || argv[i][j] == '.') && strlen(argv[i]) == 1) {
                            printf("Dangling - or .\n");
                        *flag = CONFLICT;
                        *input_type = IS_ILLEGAL;
                        return;
                        }
                    }
                }
            }
        }
    }
    printf("input_type = %s, flag = %s\n", input_type_str[*input_type - 4], flag_code[*flag]);

    return;
}