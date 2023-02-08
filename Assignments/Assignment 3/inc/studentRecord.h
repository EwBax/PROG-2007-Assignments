//
// Created by Ewan Baxter on 2022-11-04.
//

#ifndef ASSIGN3_STUDENTRECORD_H
#define ASSIGN3_STUDENTRECORD_H

#include <stdio.h>

#define STRING_LENGTH 21
#define NUM_COURSES 5

struct CourseRecord
{
    char courseName[STRING_LENGTH];
    float mark;
};

struct StudentRecord
{
    int studentID;
    char lastName[STRING_LENGTH];
    char firstName[STRING_LENGTH];
    struct CourseRecord courseRecords[NUM_COURSES];
    float averageMark;
};

//Function to get input for student records
void getStudentDetails(struct StudentRecord *student);

//Function to calculate average mark for given student
void calculateAverageMark(struct StudentRecord *student);

//Function prototype declaration
void printReportCard(struct StudentRecord *student);

#endif //ASSIGN3_STUDENTRECORD_H
