#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <locale.h>

#define ENGLISH 10
#define COMPUTER 15
#define TOTAL 10

#define STUDENTID 5
#define STUDENTNAME 20
#define AGE 6

#define EMPLOYEENAME 20
#define PROFESSION 30
#define PHONE 15

#define CLASSID 10
#define CLASSTOTAL 10
#define CLASSTOTALEMPLOYEES 10

typedef struct Grades {
    float English;
    float Computer;
    float Total;
} Grades;

typedef struct Student {
    unsigned int ID;
    char Name[STUDENTNAME];
    unsigned short Age;
    Grades Grades;
} Student;

typedef struct SNode {
    Student Data;
    struct SNode * Next;
    struct SNode * Previous;
} SNode;

typedef struct SLinkedList {
    SNode * Head;
    SNode * Tail;
    unsigned int Size;
} SLinked;

typedef struct Employee {
    unsigned int ID;
    char Name[EMPLOYEENAME];
    unsigned short Age;
    char Profession[PROFESSION];
    unsigned long int Phone;
} Employee;

typedef struct ENode {
    Employee Data;
    struct ENode * Next;
    struct ENode * Previous;
} ENode;

typedef struct ELinked {
    ENode * Head;
    ENode * Tail;
    unsigned int Size;
} ELinked;

typedef struct Class {
    char ID[CLASSID];
    SLinked Students;
    ELinked Employees;
} Class;

typedef struct CNode {
    Class Data;
    struct CNode * Next;
    struct CNode * Previous;
} CNode;

typedef struct CLinkedList  {
    CNode * Head;
    CNode * Tail;
    unsigned int Size;
} CLinked;

void program();
void createStudentList(SLinked * listPointer);
void createEmployeeList(ELinked * listPointer);
void createClassList(CLinked * listPointer);
void appendStudent(SLinked * listPointer, Student data);
void appendEmployee(ELinked * listPointer, Employee data);
void appendClass(CLinked * listPointer, Class c);
void insertStudent(SLinked * listPointer, Student data);
void insertEmployee(ELinked * listPointer, Employee data);
void insertClass(CLinked * listPointer, Class data);
SNode * findStudent(SLinked * listPointer, int search);
SLinked findStudents(Class * listPointer, int search);
ENode * findEmployee(ELinked * listPointer, int search);
ELinked findEmployees(Class * listPointer, int search);
Class * findClass(CLinked * listPointer, char search[]);
CLinked findClasses(CLinked * listPointer, char* search);
Student inputStudentData(SLinked *studentList);
Employee inputEmployeeData(ELinked *employeeList);
Class inputClassData(CLinked * listPointer);
void rankStudents(SLinked * listPointer);
void deleteStudent(SLinked * listPointer, SNode * student);
void deleteEmployee(ELinked * listPointer, ENode * employee);
void deleteClass(CLinked * listPointer, CNode * class);
void destroyStudents(SLinked * listPointer);
void destroyEmployees(ELinked * listPointer);
void destroyClasses(CLinked * listPointer);
void sortStudents(SLinked * listPointer, int sortType);
void sortClasses(CLinked * listPointer, int sortType);
int recountStudents(SLinked * listPointer);
int recountEmployees(ELinked * listPointer);
int recountClasses(CLinked * listPointer);
void swapNodes(SNode * a, SNode * b, SLinked * listPointer);

#endif // FUNCTIONS_H_INCLUDED
