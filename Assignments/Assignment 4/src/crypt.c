#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "../inc/crypt.h"


// Function to perform substitution cipher
void substitutionCipher(char * alphaText, char * start, char * sub)
{

    // Holds the index of where the current character from alphaText is in start array
    int     currentCharIdx;
    // Pointer to the memory address of where the current character is in start array
    char*   currentCharPtr;


    // Looping through the alphaText string
    for (int i = 0; alphaText[i] != '\0'; i++) {

        // Only doing sub if current character is not a space
        if (alphaText[i] != ' ') {

            // Getting memory address of current char from alphaText in start array
            currentCharPtr = strchr(start, toupper(alphaText[i]));

            // Finding index in array by getting difference in memory address of current char vs
            // array start address
            currentCharIdx = currentCharPtr - start;

            // Setting the current char in alphaText to the value at the corresponding index in the sub
            alphaText[i] = sub[currentCharIdx];

        }

    }

}


// Function converting char array to int array
void charToInt(char * alphaText, unsigned int * numericText)
{

    // Looping through both arrays and converting char to ASCII int value and storing
    for (int i = 0; alphaText[i] != '\0'; i++) {
        numericText[i] = (int) alphaText[i];
    }

}


// Function converting int array to char array
void intToChar(char * alphaText, unsigned int * numericText, int length)
{

    // Looping through both arrays and converting int to ASCII character of same value
    for (int i = 0; i < length; i++) {
        alphaText[i] = (char) numericText[i];
    }

    // Appending null terminator onto end of alphaText
    alphaText[length] = '\0';

}


// Function to handle encryption routine
void encryption(char * alphaText,
               char * start,
               char * sub,
               unsigned int * encrypted,
               unsigned int mask)
{


    unsigned int    numericText[ARRAY_LENGTH]; // Array to hold message converted to numbers
    int             messageLength;  // Variable to hold length of message to be encrypted


    // Prompting user to enter input to be encrypted
    printf("Please enter your message:\n");
    scanf(" %[^\n]s", alphaText);

    // Getting length of alphaText to be encrypted
    messageLength = strlen(alphaText);

    // Performing Substitution Cipher encryption on alphaText
    substitutionCipher(alphaText, start, sub);

    // Converting char to int
    charToInt(alphaText, numericText);

    // Performing Bitwise XOR on each character
    for (int i = 0; i < messageLength; i++) {
        encrypted[i] = ENCRYPT_DECRYPT(numericText[i], mask);
    }

}


// Function to handle decryption routine
void decryption(char * alphaText,
                char * start,
                char * sub,
                unsigned int * encrypted,
                unsigned int mask)
{

    // Array to hold message converted to numbers
    unsigned int    numericText[ARRAY_LENGTH];
    int             messageLength;


    // Calling function to get encrypted message input and length
    messageLength = inputEncryptedMessage(encrypted);

    // Performing Bitwise XOR on each character
    for (int i = 0; i < messageLength; i++) {
        numericText[i] = ENCRYPT_DECRYPT(encrypted[i], mask);
    }

    // Converting from int to char
    intToChar(alphaText, numericText, messageLength);

    // Performing substitution cipher with reversed start and sub
    substitutionCipher(alphaText, sub, start);

}


// Function to take int the encrypted message as a string, parse out the spaces, and store in
// unsigned int array
int inputEncryptedMessage(unsigned int * encrypted)
{

    // temp array to hold input as String, token to hold token from strtok function
    char    inputString[ARRAY_LENGTH], * token;
    int     counter = 0; // Counter to track length of message


    // Prompting user to enter input to be decrypted, taking in as string first
    printf("Please enter your message:\n");
    scanf(" %[^\n]s", inputString);

    // Splitting inputString on whitespace to get each encrypted character
    token = strtok(inputString, " ");

    // Continue while token is not null
    while (token != NULL) {

        // converting current token to long then storing in encrypted array
        encrypted[counter] = strtol(token, NULL, 10);

        counter++;

        // Getting next token from inputString
        token = strtok(NULL, " ");

    }

    // Returning counter for tracking length of array
    return counter;

}

