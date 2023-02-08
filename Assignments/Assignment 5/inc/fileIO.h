#include <stdbool.h>

#include "wordle.h"

#ifndef ASSIGN5_FILEIO_H
#define ASSIGN5_FILEIO_H

bool checkForFile(char* filePath, char* mode);

void readFromFile(char* filePath, char* fileContents);

void writeToFile(char* filePath, WordleGame wordleGame, bool wordGuessed);

#endif //ASSIGN5_FILEIO_H
