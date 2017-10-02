#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <limits.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char encrypt[256] = {0},
         decrypt[256] = {0};
    char ALPHABET[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    char key[256];
    char const EXTENSION[] = ".txt";
    size_t length = sizeof(encrypt);
    FILE * inFile;
    FILE * outFile;
    int c;

    if(*argv[1] == 'e')
    {
        char fileName[256];
        strcpy(fileName, argv[2]);
        strcat(fileName, EXTENSION);
        inFile = fopen(fileName, "r");

        if(inFile)
        {
            while(fgets(encrypt, sizeof(encrypt), inFile) != NULL)
            fclose(inFile);
        }   
        strcpy(key, encrypt);
        toUpper(encrypt);
        toUpper(key);
        removeDuplicates(encrypt);
        initializeEncryptArray(encrypt, ALPHABET);
        encryptWord(ALPHABET, encrypt, key);


        printf("ENCRYPT: %s\n", encrypt);
        printf("\n");
        printf("KEY: %s\n", key);
        printf("\n");


        fileName[0] = '\0';
        strcpy(fileName, argv[3]);
        strcat(fileName, EXTENSION);
        outFile = fopen(fileName, "ab");
        if(outFile != NULL)
        {
            fputs(key, outFile);
            fclose(outFile);
        }
    }
    else if(*argv[1] == 'd')
    {
        
    }
    else
    {
        printf("you fucked up\n");
        exit(0);
    }


    // initializeEncryptArray(encrypt, ALPHABET);
    // encryptWord(ALPHABET, encrypt, key);
    // printf("ENCRYPT: %s\n", key);
    // initializeDecryptArray(ALPHABET, encrypt, key);
    // printf("DECRYPT: %s\n", key);
    return 0;
}
