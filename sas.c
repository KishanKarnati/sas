#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void addStudent(Student* students[], int* count) {
    if (*count >= MAX_STUDENTS) {           // Check if maximum limit of students has been reached
        printf("Maximum limit of students reached.\n");
        return;
    }

    Student* newStudent = (Student*)malloc(sizeof(Student));   // Allocate memory for a new student

    printf("Enter name: ");
    scanf(" %[^\n]s", newStudent->name);    // Read name of the student
    

    printf("Enter surname: ");
    scanf(" %[^\n]s", newStudent->surname); // Read surname of the student

    printf("Enter father's name: ");
    scanf(" %[^\n]s", newStudent->fathersName); // Read father's name of the student

    printf("Enter mother's name: ");
    scanf(" %[^\n]s", newStudent->mothersName); // Read mother's name of the student

    printf("Enter email: ");
    scanf(" %[^\n]s", newStudent->email);   // Read email of the student

    printf("Enter phone number: ");
    scanf(" %[^\n]s", newStudent->phone);   // Read phone number of the student

    printf("Enter address: ");
    scanf(" %[^\n]s", newStudent->address); // Read address of the student

    printf("Enter course: ");
    scanf(" %[^\n]s", newStudent->course);  // Read course of the student

    newStudent->id = *count + 1;            // Assign a unique ID to the new student

    students[*count] = newStudent;          // Add the new student to the students array
    (*count)++;                             // Increment the count of students

    printf("Student added successfully. ID assigned: %d\n", newStudent->id);  // Print the assigned ID
}

void displayStudents(Student* students[], int count) {
    printf("ID\tName\t\tSurname\t\tFather's Name\tMother's Name\tEmail\t\t\tPhone Number\tAddress\t\t\t\tCourse\n");
    printf("=====================================================================================================================\n");

    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%s\t%s\t\t%s\t\t%s\t\t%s\t%s\t\t%s\n",
            students[i]->id, students[i]->name, students[i]->surname, students[i]->fathersName,
            students[i]->mothersName, students[i]->email, students[i]->phone,
            students[i]->address, students[i]->course);  // Print the details of each student
    }
}
void searchStudent(Student* students[], int count) {
    int searchId;
    printf("Enter the ID of the student you want to search: ");
    scanf("%d", &searchId);         // Read the ID of the student to search

    for (int i = 0; i < count; i++) {
        if (students[i]->id == searchId) {     // Check if the current student's ID matches the search ID
            printf("ID\tName\t\tSurname\t\tFather's Name\tMother's Name\tEmail\t\t\tPhone Number\tAddress\t\t\t\tCourse\n");
            printf("=====================================================================================================================\n");
            printf("%d\t%s\t%s\t%s\t\t%s\t\t%s\t\t%s\t%s\t\t%s\n",
                students[i]->id, students[i]->name, students[i]->surname, students[i]->fathersName,
                students[i]->mothersName, students[i]->email, students[i]->phone,
                students[i]->address, students[i]->course);   // Print the details of the found student
            return;
        }
    }

    printf("Student with ID %d not found.\n", searchId);   // Print a message if the student is not found
}

void freeMemory(Student* students[], int count) {
    for (int i = 0; i < count; i++) {
        free(students[i]);     // Free the memory allocated for each student structure
    }
}
int main() {
    Student* students[MAX_STUDENTS];    // Array to store pointers to Student structures
    int count = 0;                      // Number of students currently stored
    int choice;                         // User's choice

    do {
        printf("\nStudent Admission System\n");
        printf("========================\n");
        printf("1. New Student Registration\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);            // Read user's choice

        switch (choice) {
            case 1:
                addStudent(students, &count);    // Call the function to add a new student
                break;
            case 2:
                displayStudents(students, count);    // Call the function to display all students
                break;
            case 3:
                searchStudent(students, count);      // Call the function to search for a student by ID
                break;
            case 4:
                freeMemory(students, count);         // Call the function to free memory and exit the program
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");    // Print an error message for an invalid choice
        }
    } while (choice != 4);    // Repeat the loop until the user chooses to exit

    return 0;    // Return 0 to indicate successful program execution
}


