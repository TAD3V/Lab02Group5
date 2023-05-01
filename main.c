/*Lab 2  Group 5*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "main.h"

int main (void) {
    FILE fps, fpt; /*I think this should be pointers*/

    int decision = mainMenu();
    switch (decision) {
        case 1:
            fps = readFile();
            fpt = encryptFile(fps);
            writeFile(fpt);
            break;
        case 2:

            break;
        case 3:
            fps = readFile();
            fpt = *compressFile(&fps);
            writeFile(fpt);
            break;
        case 4:
            fps = readFile();
            fpt = *decompressFile(&fps);
            writeFile(fpt);
            break;
        case 5:

            break;
    }
    return 0;
}

/* Main Menu Function to allow the user to choose what they want to do */
int mainMenu() {
    int i = 0;

    printf("Welcome! \nChoose an option:\n");
    printf("1) Encrypt a File\n");
    printf("2) Decrypt a File\n");
    printf("3) Compress a File\n");
    printf("4) Decompress a File\n");
    printf("\n");
    printf("5) Exit\n");
    printf("Choice: ");

    scanf("%i", &i);

    return i;
}

FILE encryptFile (FILE file) {
    char character; /* a rolling character to get the value of each character in the file as we go through */

    character = fgetc(*file);
}

FILE *compressFile(FILE *file)
{
  FILE *compressed;
  int curr_char;

  compressed = tmpfile();

  while ((curr_char = fgetc(file)) != EOF)
  {
    int next_char;
    int count = 1;
    char count_str[32];
    while ((next_char = fgetc(file)) == curr_char)
    {
      count++;
    }
    sprintf(count_str, "%d", count);
    fputs(count_str, compressed);
    fputc(curr_char, compressed);
    curr_char = next_char;
  }

  rewind(file);
  rewind(compressed);
  return compressed;
}

FILE *decompressFile(FILE *file)
{
  FILE *decompressed;
  int count;
  char count_str[32];

  decompressed = tmpfile();

  while (fgets(count_str, sizeof(count_str), file) != NULL)
  {
    count = atoi(count_str);
    int curr_char = fgetc(file);
    while (count-- > 0)
    {
      fputc(curr_char, decompressed);
    }
  }

  rewind(file);
  rewind(decompressed);
  return decompressed;
}


FILE* readFile (char filename [])
{
  FILE* filep = NULL;
  filep = fopen(filename,"r");
  if(filep == NULL)
	{
    printf("Read Error.\n");
		return NULL;
	}
  return filep;
}

void writeFile(char filename[], char destinationName[]) {
    char line[500]; /*might make this with malloc instead*/
    FILE* file = fopen(filename, "r");
    if (file == NULL) 
    {
        printf("Read Error.\n");
        return;
    }

    FILE* doneFile = fopen(destinationName, "w");
    if (newfile == NULL) 
    {
        printf("Write Error.\n");
		    return;
    }

    while (fgets(line, sizeof(line), file)) {
      fprintf(doneFile, "%s\n", line);
    }

    fputs(contents, file);
    fclose(newFile);
    fclose(copyFile);
}
