//
// Created by Ewan Baxter on 2022-11-04.
//

#include "../inc/studentRecord.h"

//Function to get user input for student records
void getStudentDetails(struct StudentRecord *student)
{

    //Prompting user for input with student records
    printf("Please enter the Student ID:\n");
    scanf(" %i", &student->studentID);

    //Prompting user for last name input
    printf("Please enter the last name for student #%i:\n", student->studentID);
    scanf("%s", &student->lastName);

    //Prompting user for first name input
    printf("Please enter the first name for student #%i:\n", student->studentID);
    scanf("%s", &student->firstName);

    //Loop for user to input courses
    for(int i = 0; i < NUM_COURSES; i++) {

        //Getting input for course name
        printf("Please enter the course name:\n");
        scanf("%s", &student->courseRecords[i].courseName);

        //Getting input for mark
        printf("Please enter the mark for %s:\n", student->courseRecords[i].courseName);
        scanf("%f", &student->courseRecords[i].mark);

    }

    //Calling function to calculate average mark after all marks are entered
    calculateAverageMark(student);

}


//Function to calculate average mark for given student
void calculateAverageMark(struct StudentRecord *student)
{

    //Variable to hold current mark
    float totalMark = 0;

    //looping through every class and adding mark
    for(int i = 0; i < NUM_COURSES; i++) {
        totalMark += student->courseRecords[i].mark;
    }

    //Dividing total by number of courses and storing result in *student struct
    student->averageMark = totalMark / NUM_COURSES;

}


//Function to print formatted report card for given student
void printReportCard(struct StudentRecord *student)
{

    //Header with student information
    printf("Student: ID:%i\t\tName: %s, %s\n",
           student->studentID,
           student->lastName,
           student->firstName
    );

    //header line for separation
    printf("--------------------------------------------------\n\n");

    //Looping through each course and printing name and mark
    for(int i = 0; i < NUM_COURSES; i++) {

        printf("Course name: %8s\tCourse mark: %.0f\n",
               student->courseRecords[i].courseName,
               student->courseRecords[i].mark
        );

    }

    //Printing average mark
    printf("\nGrade Average: %.2f\n\n", student->averageMark);

}