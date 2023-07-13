/*The main function serves as the entry point for the Student Record System program. 
It provides a  interface for the user to perform various operations, 
such as adding a student, displaying student's information, searching for a student, deleting a student, saving student data to a file, and exiting the program.
The program uses an array to store pointers to Student objects and keeps track of the number of students using the count variable. */

/* 01-07-2023 Created Student Admission System with Basic Features like registration, displaying students data and deleting student data
05-07-2023 Added File Handling Functions to store students data
10-07-2023 Extended functionalities like Modifying Student Data, Sorting Students Data by Name and Filtering Students by Course*/

#include <stdio.h> //This header file provides input and output functions, such as printf and scanf.
#include <stdlib.h> //This header file includes functions for memory allocation, conversion, and other general-purpose functions, such as malloc and free.
#include <string.h> //This header file contains functions for manipulating strings, such as strcpy and strlen.
#include <ctype.h> //This header file provides functions for testing and manipulating characters, such as isalpha and tolower.
#include "student.h" // Including the header file for student-related functions and structures

int main() { // Entry point of the program
    Student* students[MAX_STUDENTS]; // Array of student pointers
    int count = 0; // Variable to keep track of the number of students

    loadStudentsFromFile(students, &count); // Load student data from a file into the array

    int choice; // Variable to store user's choice
    int searchId, deleteId; // Variables for searching and deleting students
    char filterCourse[MAX_COURSE_LENGTH]; // Variable to store a course for filtering
    char email[MAX_EMAIL_LENGTH]; // Variable to store an email address
    char applicationStatus[MAX_STATUS_LENGTH]; // Variable to store an application status

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
        scanf("%d", &choice); // Read user's choice

        switch (choice) {
            case 1:
                addStudent(students, &count); // Add a new student to the array
                break;
            case 2:
                displayStudents(students, count); // Display all the students in the array
                break;
            case 3:
                printf("Enter student ID to search: ");
                scanf("%d", &searchId); // Read student ID to search
                searchStudent(students, count, searchId); // Search for a student with the given ID
                break;
            case 4:
                printf("Enter student ID to delete: ");
                scanf("%d", &deleteId); // Read student ID to delete
                deleteStudent(students, &count, deleteId); // Delete a student with the given ID
                break;
            case 5:
                printf("Enter student ID to modify: ");
                scanf("%d", &searchId); // Read student ID to modify
                searchStudent(students, count, searchId); // Search for a student with the given ID
                if (searchId != -1) {
                    modifyStudent(students[searchId - 1]); // Modify the information of the found student
                }
                break;
            case 6:
                sortStudentsByName(students, count); // Sort the students in the array by name
                break;
            case 7:
                printf("Enter course to filter: ");
                scanf(" %[^\n]s", filterCourse); // Read a course to filter
                filterStudentsByCourse(students, count, filterCourse); // Filter students by the given course
                break;
            case 8:
                saveStudentsToFile(students, count); // Save the student data from the array to a file
                break;
            case 9:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 9); // Continue the loop until the user chooses to exit

    freeMemory(students, count); // Free the memory allocated for student objects

    return 0;
}
