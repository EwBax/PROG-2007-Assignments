/*
 * PROG 2007 Assignmemt 2
 * Author: Ewan Baxter W0465255
 * Date: 2022-10-16
 * Description: Main source file for program to determine leap years
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../inc/leapyear.h"

#define NUMERICAL_BASE 10
#define MAX_INPUT_LENGTH 10

int main()
{
    setbuf(stdout, 0);

    //variables
    char userInput[MAX_INPUT_LENGTH], *remaining;
    long year;
    bool isLeap;

    //welcome message
    printf("\nLeap Checker!\n");

    do {
        //Prompting user to enter year
        printf("\nPlease enter the year to check('N' to quit):");
        //scanning for string input and storing to userInput array
        scanf("%s", userInput);

        //checking if user entered 'N' to quit, strcmp() returns 0 if strings are equal
        if(strcmp(userInput, "N") != 0) {
            //if user did not quit, try to parse input for number
            year = strtol(userInput, &remaining, NUMERICAL_BASE);

            //if non-numerical value is entered, strtol returns 0, therefor if year < 1, it is not valid input because
            //0 is not a valid year anyway

            //also checking if there is any remaining string left over after conversion to long (i.e. input of 3.14,
            //remaining would = ".14").. we want remaining to be empty i.e. ""
            if(year < 1 || strcmp(remaining, "") != 0) {
                printf("Sorry that input is invalid..\n");
            } else {
                //if input is valid, check if leap year and print result
                isLeap = leap(year);
                if(isLeap) {
                    printf("%ld IS a leap year!\n", year);
                } else {
                    printf("%ld IS NOT a leap year!\n", year);
                }
            }
        }
    } while(strcmp(userInput, "N") != 0);

    //user must enter 'N' to get here
    printf("Quitting..\n");

    //calls function to print leap year per century table
    printf("\nTHE LEAP YEARS PER CENTURY REPORT:\n\n");
    leapTable();


    return 0;
}
