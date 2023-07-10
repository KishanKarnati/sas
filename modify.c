/*The modifyStudent function allows the user to enter new information (name, email, course, and phone number) and
updates the corresponding fields in the student structure.
The sortStudentsByName function sorts an array of student pointers based on their names in alphabetical order.
The filterStudentsByCourse function displays the information of students who are enrolled in a specific course, matching the provided course name. 
If no students are found, it displays a message indicating the absence of students with that course.*/

#include "student.h"

void modifyStudent(Student* student) {
    printf("Enter new name: ");
    scanf(" %[^\n]s", student->name);  // Read a new name from the user and store it in the student struct.

    printf("Enter new email: ");
    scanf(" %[^\n]s", student->email);  // Read a new email from the user and store it in the student struct.

    printf("Enter new course: ");
    scanf(" %[^\n]s", student->course);  // Read a new course from the user and store it in the student struct.

    printf("Enter new phone number: ");
    scanf(" %[^\n]s", student->phone);  // Read a new phone number from the user and store it in the student struct.

    printf("Student information modified successfully.\n");
}

void sortStudentsByName(Student* students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(students[j]->name, students[j + 1]->name) > 0) {
                Student* temp = students[j];  // Swap the positions of two students if their names are in the wrong order.
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("Students sorted by name successfully.\n");
}

void filterStudentsByCourse(Student* students[], int count, const char* course) {
    printf("Students with course '%s':\n", course);
    printf("ID\tName\t\tEmail\t\tCourse\t\tPhone\n");
    printf("---------------------------------------------------------\n");

    int found = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(students[i]->course, course) == 0) {  // Check if the course of the current student matches the provided course.
            printf("%d\t%s\t\t%s\t\t%s\t\t%s\n", students[i]->id, students[i]->name, students[i]->email, students[i]->course, students[i]->phone);
            found = 1;  // Set found to 1 if at least one student with the provided course is found.
        }
    }

    if (!found) {
        printf("No students found with course '%s'.\n", course);  // Display a message if no students with the provided course are found.
    }
}
