#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int prime_list[25] = {2, 3 , 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79,83, 89, 97};

    char input[8];
    fgets(input, 8, stdin);

    int data[6], len = (int)strlen(input) - 1;
    /*printf("len %d\n", len);*/
    for(int i = 0; i < len; i++)
        data[i] = input[i] - '0';

    int number = 0, prime_candidate = 0;
    for(int i = 0; i < len; i++) {
        for(int j = i; j < len; j++) {
            number = number * 10 + data[j];

            int k = 0;
            while(prime_list[k] * prime_list[k] <= number && k < 25) {
                if(number % prime_list[k] == 0)
                    break;
                k++;
            }
            if(prime_list[k] * prime_list[k] > number || k >= 25)
                prime_candidate = number > prime_candidate ? number : prime_candidate;
        }
        number = 0;
    }

    if(prime_candidate == 0)
        printf("No prime found\n");
    else
        printf("%d\n", prime_candidate);

    return 0;
}
