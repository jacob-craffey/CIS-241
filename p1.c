#include <stdio.h>
#include "functions.h"
#include <limits.h>
#include <string.h>

int main()
{
    char encrypt[256] = {0},
         decrypt[256] = {0};
    char ALPHABET[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    char key[256] = {0};
    size_t length = sizeof(encrypt);

    while (1) 
    {
        printf("Please enter a word to encrypt\n");
        scanf("%s", encrypt);
        if (strlen(encrypt) < 26)
        {   
            strcopy(key, encrypt);
            removeDuplicates(encrypt);
            printf("Your key  word is: %s\n", encrypt);
            break;
        }
        else 
        {
            printf("Enter a word less than 26 characters.");
        }
    }

    initializeEncryptArray(encrypt, ALPHABET);
    printf("Here's yo shit: %s\n", key);
    return 0;
}
