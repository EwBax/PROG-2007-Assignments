//
// Created by Ewan Baxter on 2022-11-04.
//

#include <stdio.h>
#include "../inc/studentRecord.h"

#define NUM_STUDENTS 3

int main()
{

    //Creating array of StudentRecords
    struct StudentRecord studentList[NUM_STUDENTS];

    //Looping through studentList and calling method to populate it
    for(int i = 0; i < NUM_STUDENTS; i++) {
        getStudentDetails(&studentList[i]);
    }

    //separator for report card output
    printf("\n********************REPORT CARDS********************\n\n");

    //Looping through studentList and printing report cards
    for(int i = 0; i < NUM_STUDENTS; i++) {
        printReportCard(&studentList[i]);
    }

    return 0;
}
