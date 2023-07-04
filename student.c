#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "student.h"

// Function to validate if the name contains only alphabetic characters
int validateName(const char* name) {
    for (int i = 0; i < strlen(name); i++) {
        if (isdigit(name[i])) {
            return 0; // Invalid input: Name contains numbers
        }
    }
    return 1; // Valid input: Name contains only alphabetic characters
}

// Function to validate if the email contains the '@' symbol
int validateEmail(const char* email) {
    int foundAtSymbol = 0;
    for (int i = 0; i < strlen(email); i++) {
        if (email[i] == '@') {
            foundAtSymbol = 1;
            break;
        }
    }
    return foundAtSymbol; // 1 if '@' symbol is present, 0 otherwise
}

// Function to validate if the phone number contains exactly 10 digits
int validatePhoneNumber(const char* phoneNumber) {
    if (strlen(phoneNumber) != 10) {
        return 0; // Invalid input: Phone number should have exactly 10 digits
    }
    for (int i = 0; i < strlen(phoneNumber); i++) {
        if (!isdigit(phoneNumber[i])) {
            return 0; // Invalid input: Phone number contains non-digit characters
        }
    }
    return 1; // Valid input: Phone number contains exactly 10 digits
}

// Function to validate if the course name contains only alphabetic characters
int validateCourse(const char* course) {
    for (int i = 0; i < strlen(course); i++) {
        if (isdigit(course[i])) {
            return 0; // Invalid input: Course name contains numbers
        }
    }
    return 1; // Valid input: Course name contains only alphabetic characters
}

// Function to add a new student to the students array
void addStudent(Student* students[], int* count) {
    if (*count >= MAX_STUDENTS) {
        printf("Maximum limit of students reached.\n");
        return;
    }

    Student* newStudent = (Student*)malloc(sizeof(Student)); // Allocate memory for a new student

    int isValidInput = 0; // Flag to check input validity
    while (!isValidInput) {
        printf("Enter name: ");
        scanf(" %[^\n]s", newStudent->name); // Read the name from the user
        isValidInput = validateName(newStudent->name); // Validate the name
        if (!isValidInput) {
            printf("Invalid input. Name should not contain numbers.\n");
        }
    }

    isValidInput = 0;
    while (!isValidInput) {
        printf("Enter email: ");
        scanf(" %[^\n]s", newStudent->email); // Read the email from the user
        isValidInput = validateEmail(newStudent->email); // Validate the email
        if (!isValidInput) {
            printf("Invalid input. Email should contain the '@' symbol.\n");
        }
    }

    isValidInput = 0;
    while (!isValidInput) {
        printf("Enter phone number: ");
        scanf(" %[^\n]s", newStudent->phone); // Read the phone number from the user
        isValidInput = validatePhoneNumber(newStudent->phone); // Validate the phone number
        if (!isValidInput) {
            printf("Invalid input. Phone number should contain exactly 10 digits.\n");
        }
    }

    isValidInput = 0;
    while (!isValidInput) {
        printf("Enter course: ");
        scanf(" %[^\n]s", newStudent->course); // Read the course name from the user
        isValidInput = validateCourse(newStudent->course); // Validate the course name
        if (!isValidInput) {
            printf("Invalid input. Course should not contain numbers.\n");
        }
    }

    newStudent->id = *count + 1; // Assign a unique ID to the new student

    students[*count] = newStudent; // Add the new student to the students array
    (*count)++; // Increment the count of students

    printf("Student added successfully. ID assigned: %d\n", newStudent->id);
}

// Function to display all the student records
void displayStudents(Student* students[], int count) {
    printf("ID\tName\t\tEmail\t\t\tPhone Number\t\tCourse\n");
    printf("===========================================================\n");

    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%s\t\t%s\t\t\t%s\n",
               students[i]->id,
               students[i]->name,
               students[i]->email,
               students[i]->phone,
               students[i]->course);
    }
}

// Function to search for a student by ID and display their record
void searchStudent(Student* students[], int count, int searchId) {
    for (int i = 0; i < count; i++) {
        if (students[i]->id == searchId) {
            printf("Student found:\n");
            printf("ID: %d\n", students[i]->id);
            printf("Name: %s\n", students[i]->name);
            printf("Email: %s\n", students[i]->email);
            printf("Phone Number: %s\n", students[i]->phone);
            printf("Course: %s\n", students[i]->course);
            return;
        }
    }

    printf("Student with ID %d not found.\n", searchId);
}

// Function to delete a student by ID
void deleteStudent(Student* students[], int* count, int deleteId) {
    int found = 0; // Flag to check if the student with the given ID is found
    int deleteIndex; // Index of the student to be deleted

    for (int i = 0; i < *count; i++) {
        if (students[i]->id == deleteId) {
            found = 1;
            deleteIndex = i;
            break;
        }
    }

    if (found) {
        free(students[deleteIndex]); // Free the memory allocated for the student

        for (int i = deleteIndex; i < *count - 1; i++) {
            students[i] = students[i + 1]; // Shift the remaining students to fill the gap
        }

        (*count)--; // Decrement the count of students
        printf("Student with ID %d deleted successfully.\n", deleteId);
    } else {
        printf("Student with ID %d not found.\n", deleteId);
    }
}

// Function to free the memory allocated for students
void freeMemory(Student* students[], int count) {
    for (int i = 0; i < count; i++) {
        free(students[i]); // Free the memory for each student
    }
}
