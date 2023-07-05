#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "student.h"

// Function to delete a student with a specific ID
void deleteStudent(Student* students[], int* count, int deleteId) {
    int found = 0;
    // Iterate over each student
    for (int i = 0; i < *count; i++) {
        // Check if the student ID matches the ID to be deleted
        if (students[i]->id == deleteId) {
            found = 1;
            // Free the memory allocated for the student
            free(students[i]);
            // Shift the elements in the array to remove the deleted student
            for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }
            // Decrease the count of students
            (*count)--;
            printf("Student with ID %d deleted.\n", deleteId);
            break;
        }
    }
    // If the student ID was not found, display an error message
    if (!found) {
        printf("Student with ID %d not found.\n", deleteId);
    }
}

// Function to free the memory allocated for students
void freeMemory(Student* students[], int count) {
    // Iterate over each student and free their memory
    for (int i = 0; i < count; i++) {
        free(students[i]);
    }
}
