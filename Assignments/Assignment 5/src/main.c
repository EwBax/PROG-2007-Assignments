#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../inc/wordle.h"
#include "../inc/fileIO.h"

// Command arg processing constants
#define FIRST_FLAG_INDEX 1
#define SECOND_FLAG_INDEX 3
#define FIRST_FILE_INDEX 2
#define SECOND_FILE_INDEX 4

// word input file processing constants
#define FILE_CONTENTS_LENGTH 30


int main(int argc, char* argv[])
{

    WordleGame  wordleGame;

    bool        wordGuessed;
    char*       inputFilePath;
    char*       outputFilePath;
    char*       token;
    char        inputFileContents[FILE_CONTENTS_LENGTH];


    setbuf(stdout, 0);


    //==============================================================================================
    //===========================Processing Command Line Arguments==================================
    //==============================================================================================

    // Checking for proper number of arguments
    if (argc != 5) {

        // If invalid number of arguments, print error message and return 1
        fprintf(stderr, "Invalid number of command line arguments.");

        return 1;


    // Checking for -i and -o flags in proper positions
    // if not -i ... -0 ... AND not -o ... -i ...
    } else if ( !((strcmp(argv[FIRST_FLAG_INDEX], "-i") == 0) && (strcmp(argv[SECOND_FLAG_INDEX], "-o") == 0))
            && !((strcmp(argv[FIRST_FLAG_INDEX], "-o") == 0) && (strcmp(argv[SECOND_FLAG_INDEX], "-i") == 0)) ) {

        fprintf(stderr, "Invalid command line argument usage.");

        return 1;

    } else {

        // We know -i and -o are in correct spots so now we figure out which argv values are read
        // file and write file
        if (strcmp(argv[FIRST_FLAG_INDEX], "-i") == 0) {
            inputFilePath = argv[FIRST_FILE_INDEX];
            outputFilePath = argv[SECOND_FILE_INDEX];
        } else {
            inputFilePath = argv[SECOND_FILE_INDEX];
            outputFilePath = argv[FIRST_FILE_INDEX];
        }

        // Checking if in file and out file exist / are accessible, returning 1 if they don't/aren't
        if (!checkForFile(inputFilePath, "r")) {
            return 1;
        } else if (!checkForFile(outputFilePath, "w")) {
            return 1;
        }

    }

    // If the program reaches this point we know command args are valid and files are readable/writeable


    //==============================================================================================
    //===========================Processing Input File Contents=====================================
    //==============================================================================================

    // Reading from the input file
    readFromFile(inputFilePath, inputFileContents);

    // Input File format is as follows:
    // wordLength numGuesses\n
    // wordleWord\0


    // word length is first number in input file, so we take the first token splitting on " "
    token = strtok(inputFileContents, " ");

    // Then convert to int
    wordleGame.wordLength = strtol(token, NULL, 10);

    // Allocating memory for wordle word... word length + 1 for null terminator
    wordleGame.word = (char*) malloc(sizeof(char) * (wordleGame.wordLength + 1));

    // Number of guesses is the next token in the input file, which is followed by \n
    token = strtok(NULL, "\n");

    // Then convert to int
    wordleGame.numGuesses = strtol(token, NULL, 10);

    // Final token in input file is the wordle word, which is followed by the null terminator
    token = strtok(NULL, "\0");

    // copying token into wordleWord
    strcpy(wordleGame.word, token);


    //==============================================================================================
    //===========================Setting up Game Board==============================================
    //==============================================================================================


    // Creating game board array. First allocating array to hold each guess array
    wordleGame.gameBoard = (char**) malloc(sizeof(char*) * wordleGame.numGuesses);

    // For loop to loop through gameBoard and allocate each guess array
    for (int i = 0; i < wordleGame.numGuesses; i++) {

        wordleGame.gameBoard[i] = (char*) malloc(sizeof(char) * (wordleGame.wordLength + 1));

        // Also formatting each guess array to contain underscores
        for (int j = 0; j <= wordleGame.wordLength; j++) {

            // Making sure we leave the last spot for null terminator
            if (j < wordleGame.wordLength) {

                wordleGame.gameBoard[i][j] = '_';

            } else {

                // last character is null terminator
                wordleGame.gameBoard[i][j] = '\0';

            }

        }

    }

    //==============================================================================================
    //===========================Running the Game===================================================
    //==============================================================================================

    wordGuessed = playWordle(wordleGame);

    writeToFile(outputFilePath, wordleGame, wordGuessed);


    // Freeing dynamically allocated memory in wordleGame now that we are done with it
    for(int i = 0; i < wordleGame.numGuesses; i++) {
        free(wordleGame.gameBoard[i]);
    }

    free(wordleGame.gameBoard);

    free(wordleGame.word);

    return 0;

}


