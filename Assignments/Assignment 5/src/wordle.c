#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "../inc/wordle.h"

#define MAX_GUESS_LENGTH 256


// Main function to control flow of wordle game
bool playWordle(WordleGame wordleGame)
{

    // Tracking how many guesses have been made, and if the word was guessed
    int     numGuesses = 0;
    bool    wordGuessed = false;

    // Welcome message
    printf("Welcome to C-Wordle!!\n\n");

    displayGameBoard(wordleGame);

    do {

        // Getting the user's guess
        getGuess(wordleGame, numGuesses);

        // Checking if the guess was correct and assigning result to wordGuessed boolean
        wordGuessed = (strcmp(wordleGame.gameBoard[numGuesses], wordleGame.word) == 0);

        numGuesses++;

        // displaying the current game state
        displayGameBoard(wordleGame);

    // Keeps looping until word has been guessed, or the number of guesses was reached
    } while (!wordGuessed && numGuesses < wordleGame.numGuesses);

    // Printing result and returning wordGuessed for use writing results to file
    printf("You %s!!!\n", (wordGuessed? "WIN" : "LOSE"));

    return wordGuessed;

}


// Method to display the current game state / game board
void displayGameBoard(WordleGame wordleGame)
{

    // Declaring temp string to hold letters that have already been printed from current
    // guess on game board
    char    temp[wordleGame.wordLength + 1];
    char    currentLetter;
    // Using these variables to minimize repeat method calls and make code more clear
    int     wordleLetterCount,
            tempLetterCount,
            guessCorrectLetterCount,
            tempCorrectLetterCount;


    printf("Current game state:\n");

    // Looping through game board guess arrays
    for (int i = 0; i < wordleGame.numGuesses; i++) {

        // Setting the first index of temp string to null terminator to "reset" it
        temp[0] = '\0';

        // Printing each character in guess with space between
        for (int j = 0; j < wordleGame.wordLength; j++) {

            currentLetter = wordleGame.gameBoard[i][j];

            if (currentLetter != '_') {

                wordleLetterCount = letterCount(currentLetter, wordleGame.word);
                tempLetterCount = letterCount(currentLetter, temp);
                guessCorrectLetterCount = letterCountCorrect(currentLetter, wordleGame.word,
                                                             wordleGame.gameBoard[i]);
                tempCorrectLetterCount = letterCountCorrect(currentLetter, wordleGame.word,
                                                            temp);


                // Checking if the letter exists in the wordleWord
                if (wordleLetterCount > 0) {

                    // If the wordle word has the letter in the same position, it is green
                    if (wordleGame.word[j] == currentLetter) {

                        green();

                    // if the number of correct current letters in the guess that still need to be
                    // printed is less than the number of the current letter total in the wordle that still
                    // need to be printed
                    } else if ((guessCorrectLetterCount - tempCorrectLetterCount) <
                               (wordleLetterCount - tempLetterCount)) {

                        yellow();

                    } else {
                        red();
                    }

                } else {
                    red();
                }

            }

            // Printing the letter and a space
            printf("%c ", currentLetter);

            // appending currentLetter to temp and moving null terminator
            temp[j] = currentLetter;
            temp[j+1] = '\0';

        }

        printf("\n");

        // Resetting color for next row/guess in case it is underscores
        reset();

    }

    printf("\n");

}


// Method to get user input for guess and validate it
void getGuess(WordleGame wordleGame, int guessIndex)
{

    // temporary string to hold guess, and boolean control for while loop
    char guess[MAX_GUESS_LENGTH];
    bool validGuess = false;

    while (!validGuess) {

        printf("Please enter a %i-letter word:", wordleGame.wordLength);
        scanf("%s", guess);

        // Checking for proper length first
        if (strlen(guess) == wordleGame.wordLength) {

            // Loop below will set this back to false if it finds a non-alphabetic character
            validGuess = true;

            // Looping through guess and making sure each character is alphabetical
            for (int i = 0; i < wordleGame.wordLength; i++) {

                if (isalpha(guess[i]) == 0) {
                    // As soon as we find a single character that is not alphabetic, break the loop
                    validGuess = false;
                    break;
                }

                // Making each character uppercase
                guess[i] = (char) toupper(guess[i]);

            }

        }

        // Error message for invalid guess
        if (!validGuess) {
            printf("\nSorry, but you can only enter %i-letter words.\n\n", wordleGame.wordLength);
        }

    }

    // Once we have a valid guess, add it to the game board
    strcpy(wordleGame.gameBoard[guessIndex], guess);

}


// counts how many times the given letter is in the word
int letterCount(char letter, char* word)
{

    int count = 0;

    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] == letter) {
            count++;
        }
    }

    return count;

}


// Counts how many times wordle word and guess have the given letter in the same index
int letterCountCorrect(char letter, char* wordleWord, char* guess)
{

    int numCorrect = 0;

    for (int i = 0; guess[i] != '\0'; i++) {

        if (guess[i] == letter && wordleWord[i] == letter) {
            numCorrect++;
        }

    }

    return numCorrect;

}


// Functions to change stdout text color
// From: https://www.theurbanpenguin.com/4184-2/
void red()
{
    printf("\033[0;31m");
}

void green()
{
    printf("\033[0;32m");
}

void yellow()
{
    printf("\033[0;33m");
}

void reset()
{
    printf("\033[0m");
}