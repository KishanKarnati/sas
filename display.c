/*The function "displayStudents" prints the information of all students in an array. 
It checks if there are any students to display and then iterates over each student.
prints their ID, name, email, course, and phone number. */


#include "student.h"

#define PAGE_SIZE 5 // Number of students to display per page

void displayStudents(Student* students[], int count) {
    // Check if there are no students to display
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }

    // Calculate the number of pages
    int numPages = (count + PAGE_SIZE - 1) / PAGE_SIZE;

    int currentPage = 1; // Current page being displayed
    int startIdx = (currentPage - 1) * PAGE_SIZE; // Index of the first student on the current page
    int endIdx = startIdx + PAGE_SIZE - 1; // Index of the last student on the current page
    endIdx = (endIdx < count) ? endIdx : count - 1; // Adjust the end index if it exceeds the number of students

    // Print the header for the student list
    printf("Student List (Page %d/%d, Total Students: %d):\n", currentPage, numPages, count);

    // Iterate over each student and display their information for the current page
    for (int i = startIdx; i <= endIdx; i++) {
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

    // Prompt for page navigation
    printf("\n");
    printf("Page Navigation: (P)revious Page, (N)ext Page, (Q)uit\n");

    // Handle page navigation input
    char input;
    while (1) {
        printf("Enter your choice: ");
        scanf(" %c", &input);
        switch (toupper(input)) {
            case 'P':
                if (currentPage > 1) {
                    currentPage--;
                    startIdx = (currentPage - 1) * PAGE_SIZE;
                    endIdx = startIdx + PAGE_SIZE - 1;
                    endIdx = (endIdx < count) ? endIdx : count - 1;
                    printf("\nStudent List (Page %d/%d, Total Students: %d):\n", currentPage, numPages, count);
                    for (int i = startIdx; i <= endIdx; i++) {
                        printf("\nStudent ID: %d\n", students[i]->id);
                        printf("Name: %s\n", students[i]->name);
                        printf("Email: %s\n", students[i]->email);
                        printf("Course: %s\n", students[i]->course);
                        printf("Phone Number: %s\n", students[i]->phone);
                    }
                } else {
                    printf("You are already on the first page.\n");
                }
                break;
            case 'N':
                if (currentPage < numPages) {
                    currentPage++;
                    startIdx = (currentPage - 1) * PAGE_SIZE;
                    endIdx = startIdx + PAGE_SIZE - 1;
                    endIdx = (endIdx < count) ? endIdx : count - 1;
                    printf("\nStudent List (Page %d/%d, Total Students: %d):\n", currentPage, numPages, count);
                    for (int i = startIdx; i <= endIdx; i++) {
                        printf("\nStudent ID: %d\n", students[i]->id);
                        printf("Name: %s\n", students[i]->name);
                        printf("Email: %s\n", students[i]->email);
                        printf("Course: %s\n", students[i]->course);
                        printf("Phone Number: %s\n", students[i]->phone);
                    }
                } else {
                    printf("You are already on the last page.\n");
                }
                break;
            case 'Q':
                return; // Exit the function
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

