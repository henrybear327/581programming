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

char *flag_code[3] = {"DEFAULT", "RESTRICTED", "CONFLICT"};
char *input_type_str[4] = {"ILLEGAL", "INTEGER", "FLOAT", "ALPHBET"};

void check_type(int, char **, int *, int *);

/*
Write a program myadd such that user in command line type myadd n1 [n2] [n3]….
The program compute the sum of these number.

Basic requirement: the numbers are 32-bit integer
bonus: the numbers may have different types
*/

int main(int argc, char *argv[])
{

    //This is how the argc and argv[] are passed as arguments
    printf("argc = %d\n", argc);
    for(int i = 0; i < argc; i++) {
        printf("%d --> %s\n", i, argv[i]);
    }
    printf("\n");


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

    printf("-----------------------------------------------------------\n");

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
        printf("float sum = %f\n", sum);
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
        for(int j = 0; j < (int)strlen(argv[i]); j++) {
            if(isalnum(argv[i][j]) == 0) {
                printf("Illigal input detected in input %d\n", i - 1);
            } else {
                if(argc == 1) {
                    //only possibilities --> number, character
                    if(isdigit(argv[i][j])) {
                        *flag = RESTRICTED_NUM;
                        *input_type = IS_INTEGER;
                    } else if(argv[i][j]== '.') {
                        *flag = RESTRICTED_NUM;
                        *input_type = IS_FLOAT;
                    } else {
                        *flag = RESTRICTED_ALP;
                        *input_type = IS_ALPHBET;
                    }
                } else {
                    //starting from second number
                    if(isdigit(argv[i][j]) && *flag == RESTRICTED_ALP) {
                        *flag = CONFLICT;
                        *input_type = IS_ILLEGAL;
                        return;
                    } else if(isalpha(argv[i][j]) && *flag == RESTRICTED_NUM) {
                        *flag = CONFLICT;
                        *input_type = IS_ILLEGAL;
                        return;
                    } else if(argv[i][j] == '.' && *input_type == IS_INTEGER) {
                        *input_type = IS_FLOAT;
                    } else {
                        continue; //normal
                    }
                }
            }
        }
    }
    printf("input_type = %s, flag = %s\n", input_type_str[*input_type - 5], flag_code[*flag]);

    return;
}