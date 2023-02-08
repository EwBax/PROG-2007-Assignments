/*
 * PROG 2007: Assignment 1
 * Author: Ewan Baxter, W0465255
 * Date: September 20, 2022
*/

#include <stdio.h>
#define TABLE_MIN 1
#define TABLE_MAX 10


int main(void)
{
    //index variables for row and column in reverse grid while loop
    int row = TABLE_MAX, column;

    //print header line
    printf("TABLE OF PRODUCTS\n\n");
    printf("   N");
    //loop for header line
    for(int i = TABLE_MIN; i <= TABLE_MAX; i++) {
        printf("   %4i", i);
    }
    printf("\n");

    //loop for i (row) from 1 to 10
    for(int i = TABLE_MIN; i <= TABLE_MAX; i++) {
        //print i (row #)
        printf("%4i", i);
        //loop for j (column) from 1 to 10
        for(int j = TABLE_MIN; j <= TABLE_MAX; j++) {
            //print i * j
            printf("   %4i", j * i);
        }
        //print new line
        printf("\n");
    }

    //REVERSE
    //print header line
    printf("\n\nREVERSE TABLE OF PRODUCTS\n\n");
    printf("   N");
    //loop for header line
    for(int i = TABLE_MAX; i >= TABLE_MIN; i--) {
        printf("   %4i", i);
    }
    printf("\n");

    //loop row from 10 to 1
    while(row >= TABLE_MIN) {
        //print row #
        printf("%4i", row);
        //column resets to 10 every new row
        column = TABLE_MAX;
        //loop column from 10 to 1
        while(column >= TABLE_MIN) {
            //print row * column
            printf("   %4i", row * column);
            column--;
        }
        //print new line
        printf("\n");
        //decrement row #
        row--;
    }

    return 0;
}