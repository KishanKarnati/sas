/*The main function serves as the entry point for the Student Record System program. 
It provides a  interface for the user to perform various operations, 
such as adding a student, displaying student's information, searching for a student, deleting a student, saving student data to a file, and exiting the program.
The program uses an array to store pointers to Student objects and keeps track of the number of students using the count variable. */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "student.h"
#include "display.c" // Including additional source code files is not recommended, as it can cause duplicate symbols during compilation.
#include "student.c"
#include "delete.c"
#include "search.c"
#include "data.c"
#include "add.c"

int main() {
    Student* students[MAX_STUDENTS]; // Array to store pointers to Student objects
    int count = 0; // Counter variable to keep track of the number of students

    loadStudentsFromFile(students, &count); // Load student data from a file

    int choice;
    int searchId, deleteId;

    do {
        printf("\n--- Student Record System ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Save Students data\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // Get the user's choice

        switch (choice) {
            case 1:
                addStudent(students, &count); // Call the function to add a student
                break;
            case 2:
                displayStudents(students, count); // Call the function to display all students
                break;
            case 3:
                printf("Enter student ID to search: ");
                scanf("%d", &searchId); // Get the ID of the student to search
                searchStudent(students, count, searchId); // Call the function to search for a student
                break;
            case 4:
                printf("Enter student ID to delete: ");
                scanf("%d", &deleteId); // Get the ID of the student to delete
                deleteStudent(students, &count, deleteId); // Call the function to delete a student
                break;
            case 5:
                saveStudentsToFile(students, count); // Call the function to save student data to a file
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6); // Repeat the loop until the user chooses to exit

    freeMemory(students, count); // Free the memory allocated for students

    return 0;
}
