#include <stdio.h>
#include <string.h>

#include "../inc/fileIO.h"

bool checkForFile(char* filePath, char* mode)
{

    // Defining file
    FILE*    file;
    char*   modeFull;

    // Getting mode as full word for error message output
    if (strcmp(mode, "r") == 0) {
        modeFull = "reading";
    } else {
        modeFull = "writing";
    }

    // Opening file
    file = fopen(filePath, mode);

    // Checking if file is NULL, and printing error message if so
    if(file == NULL) {

        fclose(file);

        fprintf(stderr, "Cannot open %s for %s.", filePath, modeFull);

        return false;

    } else {

        fclose(file);

        return true;

    }

}


void readFromFile(char* filePath, char* fileContents)
{

    // Defining file and current char
    FILE    *file;
    int     currentChar;

    file = fopen(filePath, "r");

    // Looping through each character of file until EOF
    while ((currentChar = fgetc(file)) != EOF) {

        //putting currentChar in fileContents
        *fileContents = (char) currentChar;
        // Incrementing fileContents so we don't overwrite
        fileContents++;

    }

    // appending null terminator onto fileContents once EOF reached
    *fileContents = '\0';

    // Closing file
    fclose(file);

}


void writeToFile(char* filePath, WordleGame wordleGame, bool wordGuessed)
{

    // Defining pointer to file
    FILE *file;

    file = fopen(filePath, "w");

    if (wordGuessed) {
        fputs("The solution was found.\n", file);
    } else {
        fputs("The solution was not found.\n", file);
    }

    // Looping through game board and outputting with spaces between letters
    for (int i = 0; i < wordleGame.numGuesses; i++) {

        for (int j = 0; j < wordleGame.wordLength; j++) {

            fputc(wordleGame.gameBoard[i][j], file);
            fputc(' ', file);

        }

        fputc('\n', file);

    }

    // Printing message saying file was successfully written, then closing file
    printf("The game result was written to the %s file.", filePath);

    fclose(file);

}