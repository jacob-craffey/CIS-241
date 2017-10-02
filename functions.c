#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "functions.h"
#include <ctype.h>

// remove duplicate characters in array word and return the result string
char * removeDuplicates(char word[])
{
    char temp[256] = {0};
    int i = 0;
    int j = 0;

    // Iterates through the word and removes duplicate letters
    for(i = 0; word[i] != '\0'; i++)
    {
        if(0 == temp[word[i]])
        {
            temp[word[i]] = 1;
            word[j] = word[i];
            j++;
        }
    }
    word[j-1] = '\0';
    return word;
}

// Converts the string to uppercase chars
void toUpper(char word[])
{
    int i;
    for(i = 0; word[i] != '\0'; i++)
    {
        word[i] = toupper(word[i]);
    }
}

// search the first num characters in array charArray for character target
// return a non-zero integer if found, otherwise, return 0
// int targetFound(char charArray[], int num, char target)
// {

// }

// initialize the encrypt array with appropriate cipher letters according to the given key
void initializeEncryptArray(char key[], char encrypt[])
{
    int i, j;
    int keyLength = strlen(key);

    for(i = 25; i >= 0; i--)
    {
        for(j = 0; key[j] != '\0'; j++)
        {
            if(encrypt[i] == key[j])
            {
                break;
            }
            if(j == keyLength - 1 && encrypt[i] != key[j])
            {
                key[keyLength] = encrypt[i];
                key[keyLength+1] = '\0';
                keyLength++;
            }
        }
    }
}

// computes the encryption given the alphabet and the cipher
void encryptWord(char ALPHABET[], char cipher[], char key[])
{
    int i, j;
    
    for(i = 0; key[i] != '\0'; i++)
    {
        for(j = 0; ALPHABET[j]; j++)
        {
            if(key[i] == ALPHABET[j])
            {
                key[i] = cipher[j];
                break;
            }
        }
    }
}

// initialize the decrypt array with appropriate substitute letters based on the ecrypt array
void initializeDecryptArray(char ALPHABET[], char cipher[], char key[])
{
    int i, j;
    
    for(i = 0; key[i] != '\0'; i++)
    {
        for(j = 0; cipher[j] != '\0'; j++)
        {
            if(key[i] == cipher[j])
            {
                key[i] = ALPHABET[j];
                break;
            }
        }
    }
}

// process data from the input file and write the result to the output file
// pass the encrypt array to parameter substitute if encryption is intended
// pass the decrypt array to parameter substitute if decryption is intended
void processInput(FILE * inf, FILE * outf, char substitute[])
{
    char key[256];
    char ALPHABET[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

    if(inf)
    {
        while(fgets(substitute, 256, inf) != NULL)
        fclose(inf);
    }   
    strcpy(key, substitute);
    toUpper(substitute);
    toUpper(key);
    substitute = removeDuplicates(substitute);
    initializeEncryptArray(substitute, ALPHABET);
    encryptWord(ALPHABET, substitute, key);

    printf("KEY: %s\n", substitute);
    printf("ENCRYPT: %s\n", key);

    if(outf == NULL)
    {
        printf("Error opening file!\n");
    }
    fprintf(outf, "%s\n", key);

}
