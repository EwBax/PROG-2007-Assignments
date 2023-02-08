

#ifndef ASSIGN5_WORDLE_H
#define ASSIGN5_WORDLE_H

// Struct to store game information
typedef struct {

    int wordLength;
    int numGuesses;
    char* word;
    char** gameBoard;

} WordleGame;

void red();

void green();

void yellow();

void reset();

int letterCountCorrect(char letter, char* wordleWord, char* guess);

int letterCount(char letter, char* word);

void getGuess(WordleGame wordleGame, int guessIndex);

bool playWordle(WordleGame wordleGame);

void displayGameBoard(WordleGame wordleGame);

#endif //ASSIGN5_WORDLE_H
