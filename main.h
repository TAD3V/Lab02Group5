#include <stdlib.h>
#include <stdio.h>
#define SECRET_KEY "jiggles"

/* Main Menu Function - Jaylen */
int mainMenu();
/* Read Data from a File - Hong */
FILE readFile();
/* Write Data to a File - Hong */
void writeFile(FILE file);

/* Encrypts Data - Jaylen*/
FILE encryptFile(FILE file);
/* Decrypts Encrypted Data - Elie */
FILE decryptFile(FILE file);
/* Compresses File - Quoc */
FILE *compressFile(FILE *file);
/* Decompresses File - Quoc */
FILE *decompressFile(FILE *file);
