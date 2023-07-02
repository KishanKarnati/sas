#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sas.h"



void addStudent(Student* students[], int* count) {
    if (*count >= MAX_STUDENTS) {
        printf("Maximum limit of students reached.\n");
        return;
    }

    Student* newStudent = (Student*)malloc(sizeof(Student));

    printf("Enter name: ");
    scanf(" %[^\n]s", newStudent->name);

    printf("Enter surname: ");
    scanf(" %[^\n]s", newStudent->surname);

    printf("Enter father's name: ");
    scanf(" %[^\n]s", newStudent->fathersName);

    printf("Enter mother's name: ");
    scanf(" %[^\n]s", newStudent->mothersName);

    printf("Enter email: ");
    scanf(" %[^\n]s", newStudent->email);

    printf("Enter phone number: ");
    scanf(" %[^\n]s", newStudent->phone);

    printf("Enter address: ");
    scanf(" %[^\n]s", newStudent->address);

    printf("Enter course: ");
    scanf(" %[^\n]s", newStudent->course);

    newStudent->id = *count + 1;

    students[*count] = newStudent;
    (*count)++;

    printf("Student added successfully. ID assigned: %d\n", newStudent->id);
}

void displayStudents(Student* students[], int count) {
    printf("ID\tName\t\tSurname\t\tFather's Name\tMother's Name\tEmail\t\t\tPhone Number\tAddress\t\t\t\tCourse\n");
    printf("=====================================================================================================================\n");

    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%s\t%s\t\t%s\t\t%s\t\t%s\t%s\t\t%s\n",
            students[i]->id, students[i]->name, students[i]->surname, students[i]->fathersName,
            students[i]->mothersName, students[i]->email, students[i]->phone,
            students[i]->address, students[i]->course);
    }
}

void searchStudent(Student* students[], int count) {
    int searchId;
    printf("Enter the ID of the student you want to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < count; i++) {
        if (students[i]->id == searchId) {
            printf("ID\tName\t\tSurname\t\tFather's Name\tMother's Name\tEmail\t\t\tPhone Number\tAddress\t\t\t\tCourse\n");
            printf("=====================================================================================================================\n");
            printf("%d\t%s\t%s\t%s\t\t%s\t\t%s\t\t%s\t%s\t\t%s\n",
                students[i]->id, students[i]->name, students[i]->surname, students[i]->fathersName,
                students[i]->mothersName, students[i]->email, students[i]->phone,
                students[i]->address, students[i]->course);
            return;
        }
    }

    printf("Student with ID %d not found.\n", searchId);
}

void freeMemory(Student* students[], int count) {
    for (int i = 0; i < count; i++) {
        free(students[i]);
    }
}

int main() {
    Student* students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        printf("\nStudent Admission System\n");
        printf("========================\n");
        printf("1. New Student Registration\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                freeMemory(students, count);
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}