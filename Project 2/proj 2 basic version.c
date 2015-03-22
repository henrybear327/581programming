#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    //Show all the numbers user inputted
    for(int i = 1; i < argc; i++) {
        if(i != argc - 1)
            printf("%s ", argv[i]);
        else
            printf("%s\n", argv[i]);
    }

    //Calculate the sum of 32-bit integers
    int sum = 0;
    for(int i = 1; i < argc; i++)
        sum += atoi(argv[i]);
    printf("%d\n", sum);

    return 0;
}