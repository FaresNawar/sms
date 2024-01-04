#ifndef TABLE_H_INCLUDED
#define TABLE_H_INCLUDED

#include "functions.h"
#include "design.h"

#include "table.h"

// Student tables
void TabulizeStudent(Student data);
void TabulizeStudentList(Class * listPointer);
void STabulizeStudentList(SLinked * listPointer, Class * studentClass);

// Class tables
void TabulizeClass(Class data);
void TabulizeClassList(CLinked * listPointer);

// Employee tables
void TabulizeEmployee(Employee data);
void TabulizeEmployeeList(Class * listPointer);
void STabulizeEmployeeList(ELinked *listPointer, Class * employeeClass);

#endif // TABLE_H_INCLUDED
