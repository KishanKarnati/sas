#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "student.h"

// Function to display the information of all students
void displayStudents(Student* students[], int count) {
    // Check if there are no students to display
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }

    // Print the header for the student list
    printf("Student List:\n");

    // Iterate over each student and display their information
    for (int i = 0; i < count; i++) {
        // Print the student ID
        printf("\nStudent ID: %d\n", students[i]->id);
        // Print the student's name
        printf("Name: %s\n", students[i]->name);
        // Print the student's email
        printf("Email: %s\n", students[i]->email);
        // Print the student's course
        printf("Course: %s\n", students[i]->course);
        // Print the student's phone number
        printf("Phone Number: %s\n", students[i]->phone);
    }
}
