/*The main function serves as the entry point for the Student Record System program. 
It provides a  interface for the user to perform various operations, 
such as adding a student, displaying student's information, searching for a student, deleting a student, saving student data to a file, and exiting the program.
The program uses an array to store pointers to Student objects and keeps track of the number of students using the count variable. */

/* 01-07-2023 Created Student Admission System with Basic Features like registration, displaying students data and deleting student data
05-07-2023 Added File Handling Functions to store students data
10-07-2023 Extended functionalities like Modifying Student Data, Sorting Students Data by Name and Filtering Students by Course*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "student.h"

int main() {
    Student* students[MAX_STUDENTS];
    int count = 0;

    loadStudentsFromFile(students, &count);

    int choice;
    int searchId, deleteId;
    char filterCourse[MAX_COURSE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char applicationStatus[MAX_STATUS_LENGTH];

    do {
        printf("\n--- Student Admission System ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Modify Student Information\n");
        printf("6. Sort Students by Name\n");
        printf("7. Filter Students by Course\n");
        printf("8. Save Students data\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                printf("Enter student ID to search: ");
                scanf("%d", &searchId);
                searchStudent(students, count, searchId);
                break;
            case 4:
                printf("Enter student ID to delete: ");
                scanf("%d", &deleteId);
                deleteStudent(students, &count, deleteId);
                break;
            case 5:
                printf("Enter student ID to modify: ");
                scanf("%d", &searchId);
                searchStudent(students, count, searchId);
                if (searchId != -1) {
                    modifyStudent(students[searchId - 1]);
                }
                break;
            case 6:
                sortStudentsByName(students, count);
                break;
            case 7:
                printf("Enter course to filter: ");
                scanf(" %[^\n]s", filterCourse);
                filterStudentsByCourse(students, count, filterCourse);
                break;
            case 8:
                saveStudentsToFile(students, count);
                break;
            case 9:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 10);

    freeMemory(students, count);

    return 0;
}

