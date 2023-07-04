#ifndef STUDENT_H
#define STUDENT_H


#define MAX_STUDENTS 50
#define MAX_NAME_LENGTH 50
#define MAX_SURNAME_LENGTH 50
#define MAX_FATHERS_NAME_LENGTH 50
#define MAX_MOTHERS_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define MAX_ADDRESS_LENGTH 100
#define MAX_COURSE_LENGTH 50

typedef struct {
    int id;                                 // ID of the student
    char name[MAX_NAME_LENGTH];             // Name of the student
    char surname[MAX_SURNAME_LENGTH];       // Surname of the student
    char fathersName[MAX_FATHERS_NAME_LENGTH];   // Father's name of the student
    char mothersName[MAX_MOTHERS_NAME_LENGTH];   // Mother's name of the student
    char email[MAX_EMAIL_LENGTH];           // Email of the student
    char phone[MAX_PHONE_LENGTH];           // Phone number of the student
    char address[MAX_ADDRESS_LENGTH];       // Address of the student
    char course[MAX_COURSE_LENGTH];         // Course of the student
} Student;

void addStudent(Student* students[], int* count);
void displayStudents(Student* students[], int count);
void searchStudent(Student* students[], int count);
void freeMemory(Student* students[], int count);

#endif
