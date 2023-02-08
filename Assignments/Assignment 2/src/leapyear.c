/*
 * PROG 2007 Assignmemt 2
 * Author: Ewan Baxter W0465255
 * Date: 2022-10-16
 * Description: function definitions for leapyear.h
 */

#include <stdbool.h>
#include <stdio.h>

//magic numbers
#define NUM_CENTURIES 21
#define YEARS_IN_CENTURY 100
#define FINAL_YEAR 2022

//function to determine if given year is a leap year
bool leap(int year)
{
    //Leap year must be evenly divisible by 4 AND NOT evenly divisible by 100, OR it must be evenly divisible by 400
    int rem_4, rem_100, rem_400;

    rem_4 = year % 4;
    rem_100 = year % 100;
    rem_400 = year % 400;

    if ((rem_4 == 0 && rem_100 != 0) || rem_400 == 0) {
        return true;
    } else {
        return false;
    }
}

//function to generate table of leap years from 1 - 2022
void leapTable()
{
    //2D array to hold every year from 1-2022
    bool years[NUM_CENTURIES][YEARS_IN_CENTURY];
    int currentYear;

    //Loop to populate array and check if each year is a leap year
    //outer loop does centuries
    for(int i = 0; i < NUM_CENTURIES; i++) {
        printf("\nCentury #%d: ", i + 1);
        //inner loop does years
        for(int j = 0; j < YEARS_IN_CENTURY; j++) {
            //getting current year... i * 100 to account for centuries past, j + 1 to account for index starting at 0
            currentYear = (i * 100) + (j + 1);
            //check if we have reached final year and terminate loop if so.
            if(currentYear > FINAL_YEAR) {
                break;
            }
            //checking if it is a leap year and storing result in 2D array
            years[i][j] = leap(currentYear);
            //printing year if it is a leap year
            if(years[i][j]) {
                printf("%4d ", currentYear);
            }
        }
    }

}
