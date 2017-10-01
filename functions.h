#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

// remove duplicate characters in array word and return the result string 
char * removeDuplicates(char word[]);

// converts the string to uppercase chars
void toUpper(char word[]);

// search the first num characters in array charArray for character target
// return a non-zero integer found, otherwise, return 0
int targetFound(char charArray[], int num, char target);

// initialize the encrypt array with appropriate cipher letters according to the given key
void initializeEncryptArray(char key[], char encrypt[]);

// computes the encryption given the plaintext alphabet and the cypher
void encryptWord(char ALPHABET[], char cipher[], char key[]);

// initialize the decrypt array with appropriate cipher letters based on the encrypt array
void initializeDecryptArray(char ALPHABET[], char cipher[], char key[]);

// process data from the input file and write the result to the output file
// pass the encrypt array to the parameter substitute if the encryption is intended
// pass the decrypt array to the parameter substitute if the decryption is intended
void processInput(FILE * inf, FILE * outf, char substitute[]);

#endif
