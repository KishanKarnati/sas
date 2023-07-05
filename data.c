/*The function "saveStudentsToFile" saves the student data from an array of students to a file named "students.txt".

The function "loadStudentsFromFile" reads student data from a file named "students.txt" */


#include "student.h"

// Function to save the student data to a file
void saveStudentsToFile(Student* students[], int count) {
    // Open the file in write mode
    FILE* file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    // Iterate over each student and write their data to the file
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d;%s;%s;%s;%s\n",
            students[i]->id,
            students[i]->name,
            students[i]->email,
            students[i]->course,
            students[i]->phone);
    }
    // Close the file
    fclose(file);
}

// Function to load student data from a file
void loadStudentsFromFile(Student* students[], int* count) {
    // Open the file in read mode
    FILE* file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    char line[100];
    // Read each line from the file
    while (fgets(line, sizeof(line), file)) {
        // Allocate memory for a new Student
        Student* newStudent = (Student*)malloc(sizeof(Student));
        // Parse the line and extract student data using sscanf
        sscanf(line, "%d;%[^;];%[^;];%[^;];%[^\n]",
            &(newStudent->id),
            newStudent->name,
            newStudent->email,
            newStudent->course,
            newStudent->phone);
        // Add the new student to the array of students
        students[*count] = newStudent;
        // Increment the count of students
        (*count)++;
    }
    // Close the file
    fclose(file);
}
