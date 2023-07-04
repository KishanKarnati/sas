#include <stdio.h>        // Include the standard input/output library for input/output operations.
#include <stdlib.h>       // Include the standard library for memory allocation and other functions.
#include "student.h"      // Include a header file "student.h" that contains function declarations.

int main() {              // The entry point of the program.
    Student* students[MAX_STUDENTS];   // Array of pointers to Student structures.
    int count = 0;         // Variable to keep track of the number of students.
    int choice;            // Variable to store the user's menu choice.

    do {                   // Start a loop that will repeat until the user chooses to exit.
        printf("\nStudent Admission System\n");  // Display the menu options.
        printf("========================\n");
        printf("1. New Student Registration\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Delete Student by ID\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);  // Read the user's choice.

        switch (choice) {      // Use a switch statement to perform different actions based on the user's choice.
            case 1: {          // If the choice is 1, execute the code inside this block.
                addStudent(students, &count);  // Call the addStudent function to register a new student.
                break;           // Break out of the switch statement.
            }
            case 2: {          // If the choice is 2, execute the code inside this block.
                displayStudents(students, count);  // Call the displayStudents function to show all registered students.
                break;           // Break out of the switch statement.
            }
            case 3: {          // If the choice is 3, execute the code inside this block.
                int searchId;   // Variable to store the ID of the student to be searched.
                printf("Enter the ID of the student you want to search: ");
                scanf("%d", &searchId);  // Read the ID from the user.
                searchStudent(students, count, searchId);  // Call the searchStudent function to find the student by ID.
                break;           // Break out of the switch statement.
            }
            case 4: {          // If the choice is 4, execute the code inside this block.
                int deleteId;   // Variable to store the ID of the student to be deleted.
                printf("Enter the ID of the student you want to delete: ");
                scanf("%d", &deleteId);  // Read the ID from the user.
                deleteStudent(students, &count, deleteId);  // Call the deleteStudent function to remove the student by ID.
                break;           // Break out of the switch statement.
            }
            case 5: {          // If the choice is 5, execute the code inside this block.
                freeMemory(students, count);  // Call the freeMemory function to release memory allocated for students.
                printf("Exiting the program.\n");
                break;           // Break out of the switch statement.
            }
            default:            // If the choice is none of the above, execute the code inside this block.
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);   // Repeat the loop until the choice is 5 (exit).

    return 0;               // Return 0 to indicate successful program execution.
}

