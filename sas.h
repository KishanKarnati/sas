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
    int id;
    char name[MAX_NAME_LENGTH];
    char surname[MAX_SURNAME_LENGTH];
    char fathersName[MAX_FATHERS_NAME_LENGTH];
    char mothersName[MAX_MOTHERS_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char course[MAX_COURSE_LENGTH];
} Student;

void addStudent(Student* students[], int* count);
void displayStudents(Student* students[], int count);
void searchStudent(Student* students[], int count);
void freeMemory(Student* students[], int count);

#endif
