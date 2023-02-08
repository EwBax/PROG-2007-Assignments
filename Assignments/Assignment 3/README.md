<img width="150px" src="https://www.nscc.ca/img/aboutnscc/visual-identity-guidelines/artwork/nscc-jpeg.jpg" >

# PROG 2007 - Assignment 3
Structs, Strings and Pointers  
PROG 2007: Programming II  
**Due as posted in Brightspace**

## Task
Write a C program that conforms to the requirements listed below. In this exercise, you will create an application to generate report cards from student records.

### Requirements:

#### Part 1:
Create a Student Record using a function. This record is comprised of multiple parts, so you will need a function to set up the record:

- The Student Record is represented by a **struct** containing these fields:
    - **StudentID**: type int
    - **LastName**: string of type char [21] – Field to be filled by a NULL terminated string of a maximum of 20 characters and the NULL
    - **FirstName**: string of type char[21] – Field to be filled by a NULL terminated string of a maximum of 20 characters and the NULL
    - Course records **array** containing 5 structs (**CourseRecords**) with these fields:
        - **CourseName**: string of type char [21] – Field to be filled by a NULL terminated string of a maximum of 20 characters and the NULL
        - **Mark**: type float
    - **AverageMark**: type float
- Your program must use a **function** to create three Student Records. This function should accept a **pointer to a StudentRecord** and any other appropriate parameters.
    - create the record by prompting the user for each field. Assume the user will enter reasonable data to keep validation to a minimum. **This is an exception to the “no input” in functions recommendation.**

#### Part 2:
Develop a function to calculate the AverageMark for each student and set the appropriate result in each StudentRecord.

#### Part 3:
Develop a function to print a report card for each StudentRecord. This function should accept a pointer to a StudentRecord. Format the report as shown in the sample screenshot and show:

- StudentID
- FirstName
- LastName
- Each CourseName and associated Mark
- AverageMark

#### General requirements:

- You will need to put your functions to operate on the student records structs in their **own source file called studentRecord.c**
- Have function prototype declarations for each of those functions mentioned above in a **header file called studentRecord.h**
- All your source files (i.e. main.c and studentRecord.c) should be in a **folder called “src**”
- Your header file (i.e. studentRecord.h) should be in a **folder called “inc**”
- Include clear comments
- Maintain a standard layout/format for the code. Be consistent with spacing or tabbing, use the layout to make nested operation visually clear.
- Provide clear visual feedback to the user

### Sample Outputs:
Entering the first student:  
    <img width="800px" src="https://prog2007.netlify.app/assign3-student-entry.png" alt="Assign 3 Student Entry">

Report cards (showing 2 Students only):  
    <img width="800px" src="https://prog2007.netlify.app/assign3-report-cards.png" alt="Assign 3 Report Cards">

## Submission Instructions
### Video Recording Submission:

You will demonstrate the completion of this project via a **video screen-capture recording** of you using CLion, GitBash, and viewing your code to show completion of the **Video Submission Checklist**, which is posted on Brightspace. You will post **either your video file or a link to it** (e.g. a Microsoft Stream recording, make sure to give the instructor permissions to watch it), to the Brightspace Assignment 3 Dropbox prior to the deadline. If you are not sure of how best to capture such a video, seek advice from the instructor prior to the deadline.

NOTE: MAKE SURE TO SHOW EVERYTHING IN THE VIDEO SUBMISSION CHECKLIST STEP-BY-STEP. YOU WILL NEED AUDIO IN THE VIDEO FOR AT LEAST THE CODE REVIEW PORTION OF THE CHECKLIST

> Written with [StackEdit](https://stackedit.io/).
