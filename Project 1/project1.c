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
#include <stdbool.h>

int valid_input(char *);

struct email {
    char *username;
    char *domain_name;
};

int main()
{
    //Prompt the user to input some email addresses
    printf("Please enter the quantity of email addresses the input will consist: ");
    int cases;
    scanf("%d", &cases);
    getchar();

    struct email data[cases];

    printf("Please enter %d email addresses. The program will check validity and sort them.\n", cases);
    int count = 1;
    while(count <= cases) {
        char input[200] = {'\0'};
        fgets(input, 200, stdin);

        if(valid_input(input) == true) {
            //breakdown the input into username and domain name
            printf("Input accepted\n");
        }

        count++;
    }


    //check validity, use clang color mark if possible

    //print out the result sorted by username

    //print out the result sorted by domain name

    return 0;
}

int valid_input(char *input)
{
    

    return true;
}