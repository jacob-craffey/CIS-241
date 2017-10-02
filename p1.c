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
    FILE * keyFile;

    char inFileName[256];
    strcpy(inFileName, argv[3]);
    strcat(inFileName, EXTENSION);
    inFile = fopen(inFileName, "r");

    char outFileName[256];
    strcpy(outFileName, argv[4]);
    strcat(outFileName, EXTENSION);
    outFile = fopen(outFileName, "w+");



    if(*argv[1] == 'e')
    {
        processInput(inFile, outFile, encrypt);
        
        keyFile = fopen("Key.txt", "w");
        fprintf(keyFile, "%s\n", encrypt);
    }
    else if(*argv[1] == 'd')
    {
        char keyFileName[256];
        strcpy(keyFileName, argv[2]);
        strcat(inFileName, EXTENSION);
        keyFile = fopen(keyFileName, "r");

        decryptInput(outFile, keyFile);
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
