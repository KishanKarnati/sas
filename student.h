#ifndef STUDENT_H
#define STUDENT_H

// Definition of constants for maximum values
#define MAX_STUDENTS 50
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_PHONE_LENGTH 10
#define MAX_COURSE_LENGTH 50

// Definition of the structure to represent a student
typedef struct {
    int id;                                 // Student ID
    char name[MAX_NAME_LENGTH];             // Student name
    char email[MAX_EMAIL_LENGTH];           // Student email
    char phone[MAX_PHONE_LENGTH];           // Student phone number
    char course[MAX_COURSE_LENGTH];         // Student course
} Student;

// Function prototypes for validating student information
int validateName(const char* name);                     // Validates the student name
int validateEmail(const char* email);                   // Validates the student email
int validatePhoneNumber(const char* phoneNumber);       // Validates the student phone number
int validateCourse(const char* course);                 // Validates the student course

// Function prototypes for managing student records
void addStudent(Student* students[], int* count);        // Adds a new student record
void displayStudents(Student* students[], int count);    // Displays all student records
void searchStudent(Student* students[], int count, int searchId);  // Searches for a student by ID
void deleteStudent(Student* students[], int* count, int deleteId);  // Deletes a student record by ID

// Function for freeing memory allocated for student records
void freeMemory(Student* students[], int count);

#endif
