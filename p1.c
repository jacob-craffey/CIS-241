#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <limits.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char encrypt[256] = {0},
         decrypt[256] = {0};
    
    char key[256];
    char const EXTENSION[] = ".txt";
    size_t length = sizeof(encrypt);
    FILE * inFile;
    FILE * outFile;
    int c;

    if(*argv[1] == 'e')
    {
        char inFileName[256];
        strcpy(inFileName, argv[2]);
        strcat(inFileName, EXTENSION);
        inFile = fopen(inFileName, "r");

        char outFileName[256];
        strcpy(outFileName, argv[3]);
        strcat(outFileName, EXTENSION);
        outFile = fopen(outFileName, "w");

        processInput(inFile, outFile, encrypt);


    }
    else if(*argv[1] == 'd')
    {
        
    }
    else
    {
        printf("you fucked up\n");
        exit(0);
    }

    // strcpy(key, encrypt);
    // toUpper(encrypt);
    // toUpper(key);
    // removeDuplicates(encrypt);
    // initializeEncryptArray(encrypt, ALPHABET);
    // encryptWord(ALPHABET, encrypt, key);

    // initializeEncryptArray(encrypt, ALPHABET);
    // encryptWord(ALPHABET, encrypt, key);
    // printf("ENCRYPT: %s\n", key);
    // initializeDecryptArray(ALPHABET, encrypt, key);
    // printf("DECRYPT: %s\n", key);
    return 0;
}
