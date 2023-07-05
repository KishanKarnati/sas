#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STUDENTS 50
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_PHONE_LENGTH 10
#define MAX_COURSE_LENGTH 50

// Define constants for maximum limits of various fields

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char course[MAX_COURSE_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Student;

// Define the structure for a student, including fields for ID, name, email, course, and phone number

int validateName(const char* name);
int validateEmail(const char* email);
int validateCourse(const char* course);
int validatePhoneNumber(const char* phoneNumber);

// Function prototypes for the validation functions

void addStudent(Student* students[], int* count);
void displayStudents(Student* students[], int count);
void searchStudent(Student* students[], int count, int searchId);
void deleteStudent(Student* students[], int* count, int deleteId);
void freeMemory(Student* students[], int count);
void saveStudentsToFile(Student* students[], int count);
void loadStudentsFromFile(Student* students[], int* count);

// Function prototypes for the various operations on student records

#endif  /* STUDENT_H */
