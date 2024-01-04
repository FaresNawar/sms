#ifndef TABLE_H_INCLUDED
#define TABLE_H_INCLUDED

#include "functions.h"
#include "design.h"

void TabulizeStudent(Student data);
void TabulizeStudentList(Class * listPointer);
void STabulizeStudentList(SLinked * listPointer, Class * studentClass);
void TabulizeClass(Class data);
void TabulizeClassList(CLinked * listPointer);

#endif // TABLE_H_INCLUDED
