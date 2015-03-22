/*
Input: a set of strings
Goal:
    - recognize the strings which are valid email address
    - sort them by (upper and lower cases are regarded as the same.)
        (i) username
        (ii) domain name + username

Input format:
3
bangye.wu@gmail.com
bang@tt@tt
bangye@abc.edf.edg

Basic requirement: at least 5 string functions, correct recognition
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //Prompt the user to input some email addresses
    printf("Please enter the quantity of email addresses the input will consist: ");
    int cases;
    scanf("%d", &cases);
    getchar();

    printf("Please enter %d email addresses. The program will check validity and sort them.\n", cases);
    char input[cases][200];
    memset(input, '\0', sizeof(input));

    int i = 0;
    while(i < cases)
        fgets(input[i++], 100, stdin);

    //print out the input
    for(i = 0; i < cases; i++)
        printf("%d --> %s\n", i, input[i]);
    
    //check validity, use clang color mark if possible
    
    //print out the result sorted by username

    //print out the result sorted by domain name

    return 0;
}