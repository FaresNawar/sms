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

#define CLASSID 10
#define CLASSTOTAL 10

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

typedef struct SLinkedList  {
    SNode * Head;
    SNode * Tail;
    unsigned int Size;
} SLinked;

typedef struct Class {
    char ID[CLASSID];
    SLinked Students;
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

void createStudentList(SLinked * listPointer);
void createClassList(CLinked * listPointer);
void appendStudent(SLinked * listPointer, Student data);
void appendClass(CLinked * listPointer, Class c);
void insertStudent(SLinked * listPointer, Student data);
void insertClass(CLinked * listPointer, Class data);
Class * findClass(CLinked * listPointer, char search[]);
CLinked findClasses(CLinked * listPointer, char* search);
SNode * findStudent(SLinked * listPointer, int search);
SLinked findStudents(Class * listPointer, int search);
Student inputStudentData(SLinked *studentList);
Class inputClassData(CLinked * listPointer);
void rankStudents(SLinked * listPointer);
void swapNodes(SNode * a, SNode * b, SLinked * listPointer);
void deleteStudent(SLinked * listPointer, SNode * student);
void deleteClass(CLinked * listPointer, CNode * class);
void destroyStudents(SLinked * listPointer);
void destroyClasses(CLinked * listPointer);
int recountStudents(SLinked * listPointer);
int recountClasses(CLinked * listPointer);
void program();

#endif // FUNCTIONS_H_INCLUDED
