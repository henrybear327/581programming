#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DEFAULT     0
#define CHANGED     1
#define CONFLICT    2

#define IS_ILLEGAL  5
#define IS_INTEGER  6
#define IS_FLOAT    7
#define IS_ALPHBET  8

char *flag_code[3] = {"DEFAULT", "CHANGED", "CONFLICT"};
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

    printf("This is a simple adding tool. This program can only perform \
addition on intergers, floating points, and alphbet/strings.\n\n");

    if(argc == 1) {
        printf("There is no input. Please enter some numbers.\n");
        return 0;
    }

    int input_type = IS_INTEGER, flag = DEFAULT; //default
    check_type(argc, argv, &input_type, &flag);
    printf("\n");

    if(flag == CONFLICT || input_type == IS_ILLEGAL) {
        printf("Sorry, this prgram can't perform this kind of calculation.\n");
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
            for(int j = 0; j < strlen(argv[i]); j++)
                sum += argv[i][j];
        printf("alphbet ascii code sum = %lld\n", sum);
    }
    return 0;
}

void check_type(int argc, char **argv, int *input_type, int *flag)
{
    for(int i = 1; i < argc; i++) {
        for(int j = 0; j < strlen(argv[i]); j++) {
            if(isdigit(argv[i][j])) {
                if(*input_type != IS_ALPHBET)
                    continue;
                else {
                    *flag = CONFLICT;
                    printf("(Exit from integer)\n");
                    printf("Mixed input.\n");
                    printf("(i,j) = (%d, %d), input_type = %s\n", i, j, input_type_str[*input_type - 5], flag_code[*flag]);
                    return;
                }

            } else if(argv[i][j] == '.') {
                if(*input_type == IS_FLOAT || *flag == DEFAULT) {
                    *input_type = IS_FLOAT;
                    *flag = CHANGED;
                } else {
                    *flag = CONFLICT;
                    printf("(Exit from float)\n");
                    printf("Mixed input.\n");
                    printf("(i,j) = (%d, %d), input_type = %s, flag = %s\n", i, j, input_type_str[*input_type - 5], flag_code[*flag]);
                    return;
                }
            } else if(('a' <= argv[i][j] && argv[i][j] <= 'z') || ('A' <= argv[i][j] && argv[i][j] <= 'Z')) {
                if(*input_type == IS_ALPHBET || *flag == DEFAULT) {
                    *input_type = IS_ALPHBET;
                    *flag = CHANGED;
                } else {
                    *flag = CONFLICT;
                    printf("(Exit from alphbet)\n");
                    printf("Mixed input.\n");
                    printf("(i,j) = (%d, %d), input_type = %s, flag = %s\n", i, j, input_type_str[*input_type - 5], flag_code[*flag]);
                    return;
                }
            } else {
                *input_type = IS_ILLEGAL;
                printf("Illegal input.\n");
                printf("(i,j) = (%d, %d), input_type = %s, flag = %s\n", i, j, input_type_str[*input_type - 5], flag_code[*flag]);
            }
        }
    }
    printf("input_type = %s, flag = %s\n", input_type_str[*input_type - 5], flag_code[*flag]);

    return;
}