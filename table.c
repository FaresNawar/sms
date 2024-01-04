#include "table.h"

// Student tables
void TabulizeStudent(Student data)
{
    printf("%c", TOP_LEFT);
    for(int i = 0; i < STUDENTID; i++) {printf("%c", HORIZONTAL);} //printf("%c", BOTTOM_DASH);
    for(int i = 0; i < STUDENTNAME; i++) {printf("%c", HORIZONTAL);} //printf("%c", BOTTOM_DASH);
    for(int i = 0; i < AGE; i++) {printf("%c", HORIZONTAL);} //printf("%c", BOTTOM_DASH);
    for(int i = 0; i < ENGLISH; i++) {printf("%c", HORIZONTAL);} //printf("%c", BOTTOM_DASH);
    for(int i = 0; i < COMPUTER; i++) {printf("%c", HORIZONTAL);} //printf("%c", BOTTOM_DASH);
    for(int i = 0; i < TOTAL; i++) {printf("%c", HORIZONTAL);} printf("%c\n", TOP_RIGHT);

    printf("%c", VERTICAL);
    printf(BMAG);
    printf("%-*s", STUDENTID, "ID");
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BCYN);
    printf("%-*s", STUDENTNAME, "Name");
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BGRN);
    printf("%-*s", AGE, "Age");
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BYEL);
    printf("%-*s", ENGLISH, "English");
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BYEL);
    printf("%-*s", COMPUTER, "Computer");
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BYEL);
    printf("%-*s", TOTAL, "Total");
    printf(RESET);

    printf("%c\n", VERTICAL);

    printf("%c", RIGHT_DASH);
    for(int i = 0; i < STUDENTID; i++) {printf("%c", HORIZONTAL);} //printf("%c", CROSS);
    for(int i = 0; i < STUDENTNAME; i++) {printf("%c", HORIZONTAL);} //printf("%c", CROSS);
    for(int i = 0; i < AGE; i++) {printf("%c", HORIZONTAL);} //printf("%c", CROSS);
    for(int i = 0; i < ENGLISH; i++) {printf("%c", HORIZONTAL);} //printf("%c", CROSS);
    for(int i = 0; i < COMPUTER; i++) {printf("%c", HORIZONTAL);} //printf("%c", CROSS);
    for(int i = 0; i < TOTAL; i++) {printf("%c", HORIZONTAL);} printf("%c\n", LEFT_DASH);

    printf("%c", VERTICAL);
    printf(BMAG);
    printf("%-*d", STUDENTID, data.ID);
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BCYN);
    printf("%-*s", STUDENTNAME, data.Name);
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BGRN);
    printf("%-*d", AGE, data.Age);
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BYEL);
    printf("%-*.2f", ENGLISH, data.Grades.English);
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BYEL);
    printf("%-*.2f", COMPUTER, data.Grades.Computer);
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BYEL);
    printf("%-*.2f", TOTAL, data.Grades.Total);
    printf(RESET);

    printf("%c\n", VERTICAL);


    printf("%c", BOTTOM_LEFT);
    for(int i = 0; i < STUDENTID; i++) {printf("%c", HORIZONTAL);} //printf("%c", TOP_DASH);
    for(int i = 0; i < STUDENTNAME; i++) {printf("%c", HORIZONTAL);} //printf("%c", TOP_DASH);
    for(int i = 0; i < AGE; i++) {printf("%c", HORIZONTAL);} //printf("%c", TOP_DASH);
    for(int i = 0; i < ENGLISH; i++) {printf("%c", HORIZONTAL);} //printf("%c", TOP_DASH);
    for(int i = 0; i < COMPUTER; i++) {printf("%c", HORIZONTAL);} //printf("%c", TOP_DASH);
    for(int i = 0; i < TOTAL; i++) {printf("%c", HORIZONTAL);} printf("%c\n", BOTTOM_RIGHT);
}

void TabulizeStudentList(Class * listPointer) {
    printf("%c", TOP_LEFT);
    for(int i = 0; i < STUDENTID; i++) {printf("%c", HORIZONTAL);} //printf("%c", BOTTOM_DASH);
    for(int i = 0; i < STUDENTNAME; i++) {printf("%c", HORIZONTAL);} //printf("%c", BOTTOM_DASH);
    for(int i = 0; i < AGE; i++) {printf("%c", HORIZONTAL);} //printf("%c", BOTTOM_DASH);
    for(int i = 0; i < CLASSID; i++) {printf("%c", HORIZONTAL);} //printf("%c", BOTTOM_DASH);
    for(int i = 0; i < ENGLISH; i++) {printf("%c", HORIZONTAL);} //printf("%c", BOTTOM_DASH);
    for(int i = 0; i < COMPUTER; i++) {printf("%c", HORIZONTAL);} //printf("%c", BOTTOM_DASH);
    for(int i = 0; i < TOTAL; i++) {printf("%c", HORIZONTAL);} printf("%c\n", TOP_RIGHT);

    printf("%c", VERTICAL);
    printf(BMAG);
    printf("%-*s", STUDENTID, "ID");
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BCYN);
    printf("%-*s", STUDENTNAME, "Name");
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BGRN);
    printf("%-*s", AGE, "Age");
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BBLU);
    printf("%-*s", CLASSID, "Class");
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BYEL);
    printf("%-*s", ENGLISH, "English");
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BYEL);
    printf("%-*s", COMPUTER, "Computer");
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BYEL);
    printf("%-*s", TOTAL, "Total");
    printf(RESET);

    printf("%c\n", VERTICAL);

    for (SNode * temp = listPointer->Students.Head; temp != NULL; temp = temp->Next)
    {
        printf("%c", RIGHT_DASH);
        for(int i = 0; i < STUDENTID; i++) {printf("%c", HORIZONTAL);} //printf("%c", CROSS);
        for(int i = 0; i < STUDENTNAME; i++) {printf("%c", HORIZONTAL);} //printf("%c", CROSS);
        for(int i = 0; i < AGE; i++) {printf("%c", HORIZONTAL);} //printf("%c", CROSS);
        for(int i = 0; i < CLASSID; i++) {printf("%c", HORIZONTAL);} //printf("%c", CROSS);
        for(int i = 0; i < ENGLISH; i++) {printf("%c", HORIZONTAL);} //printf("%c", CROSS);
        for(int i = 0; i < COMPUTER; i++) {printf("%c", HORIZONTAL);} //printf("%c", CROSS);
        for(int i = 0; i < TOTAL; i++) {printf("%c", HORIZONTAL);} printf("%c\n", LEFT_DASH);

        printf("%c", VERTICAL);
        printf(BMAG);
        printf("%-*d", STUDENTID, temp->Data.ID);
        printf(RESET);

        //printf("%c", VERTICAL);
        printf(BCYN);
        printf("%-*s", STUDENTNAME, temp->Data.Name);
        printf(RESET);

        //printf("%c", VERTICAL);
        printf(BGRN);
        printf("%-*d", AGE, temp->Data.Age);
        printf(RESET);

        printf(BBLU);
        printf("%-*s", CLASSID, listPointer->ID);
        printf(RESET);

        //printf("%c", VERTICAL);
        printf(BYEL);
        printf("%-*.2f", ENGLISH, temp->Data.Grades.English);
        printf(RESET);

        //printf("%c", VERTICAL);
        printf(BYEL);
        printf("%-*.2f", COMPUTER, temp->Data.Grades.Computer);
        printf(RESET);

        //printf("%c", VERTICAL);
        printf(BYEL);
        printf("%-*.2f", TOTAL, temp->Data.Grades.Total);
        printf(RESET);

        printf("%c\n", VERTICAL);
    }

    printf("%c", BOTTOM_LEFT);
    for(int i = 0; i < STUDENTID; i++) {printf("%c", HORIZONTAL);} //printf("%c", TOP_DASH);
    for(int i = 0; i < STUDENTNAME; i++) {printf("%c", HORIZONTAL);} //printf("%c", TOP_DASH);
    for(int i = 0; i < AGE; i++) {printf("%c", HORIZONTAL);} //printf("%c", TOP_DASH);
    for(int i = 0; i < CLASSID; i++) {printf("%c", HORIZONTAL);} //printf("%c", TOP_DASH);
    for(int i = 0; i < ENGLISH; i++) {printf("%c", HORIZONTAL);} //printf("%c", TOP_DASH);
    for(int i = 0; i < COMPUTER; i++) {printf("%c", HORIZONTAL);} //printf("%c", TOP_DASH);
    for(int i = 0; i < TOTAL; i++) {printf("%c", HORIZONTAL);} printf("%c\n", BOTTOM_RIGHT);
}

void STabulizeStudentList(SLinked * listPointer, Class * studentClass) {
    printf("%c", TOP_LEFT);
    for(int i = 0; i < STUDENTID; i++) {printf("%c", HORIZONTAL);} //printf("%c", BOTTOM_DASH);
    for(int i = 0; i < STUDENTNAME; i++) {printf("%c", HORIZONTAL);} //printf("%c", BOTTOM_DASH);
    for(int i = 0; i < AGE; i++) {printf("%c", HORIZONTAL);} //printf("%c", BOTTOM_DASH);
    for(int i = 0; i < CLASSID; i++) {printf("%c", HORIZONTAL);} //printf("%c", BOTTOM_DASH);
    for(int i = 0; i < ENGLISH; i++) {printf("%c", HORIZONTAL);} //printf("%c", BOTTOM_DASH);
    for(int i = 0; i < COMPUTER; i++) {printf("%c", HORIZONTAL);} //printf("%c", BOTTOM_DASH);
    for(int i = 0; i < TOTAL; i++) {printf("%c", HORIZONTAL);} printf("%c\n", TOP_RIGHT);

    printf("%c", VERTICAL);
    printf(BMAG);
    printf("%-*s", STUDENTID, "ID");
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BCYN);
    printf("%-*s", STUDENTNAME, "Name");
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BGRN);
    printf("%-*s", AGE, "Age");
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BBLU);
    printf("%-*s", CLASSID, "Class");
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BYEL);
    printf("%-*s", ENGLISH, "English");
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BYEL);
    printf("%-*s", COMPUTER, "Computer");
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BYEL);
    printf("%-*s", TOTAL, "Total");
    printf(RESET);

    printf("%c\n", VERTICAL);

    for (SNode * temp = listPointer->Head; temp != NULL; temp = temp->Next)
    {
        printf("%c", RIGHT_DASH);
        for(int i = 0; i < STUDENTID; i++) {printf("%c", HORIZONTAL);} //printf("%c", CROSS);
        for(int i = 0; i < STUDENTNAME; i++) {printf("%c", HORIZONTAL);} //printf("%c", CROSS);
        for(int i = 0; i < AGE; i++) {printf("%c", HORIZONTAL);} //printf("%c", CROSS);
        for(int i = 0; i < CLASSID; i++) {printf("%c", HORIZONTAL);} //printf("%c", CROSS);
        for(int i = 0; i < ENGLISH; i++) {printf("%c", HORIZONTAL);} //printf("%c", CROSS);
        for(int i = 0; i < COMPUTER; i++) {printf("%c", HORIZONTAL);} //printf("%c", CROSS);
        for(int i = 0; i < TOTAL; i++) {printf("%c", HORIZONTAL);} printf("%c\n", LEFT_DASH);

        printf("%c", VERTICAL);
        printf(BMAG);
        printf("%-*d", STUDENTID, temp->Data.ID);
        printf(RESET);

        //printf("%c", VERTICAL);
        printf(BCYN);
        printf("%-*s", STUDENTNAME, temp->Data.Name);
        printf(RESET);

        //printf("%c", VERTICAL);
        printf(BGRN);
        printf("%-*d", AGE, temp->Data.Age);
        printf(RESET);

        printf(BBLU);
        printf("%-*s", CLASSID, studentClass->ID);
        printf(RESET);

        //printf("%c", VERTICAL);
        printf(BYEL);
        printf("%-*.2f", ENGLISH, temp->Data.Grades.English);
        printf(RESET);

        //printf("%c", VERTICAL);
        printf(BYEL);
        printf("%-*.2f", COMPUTER, temp->Data.Grades.Computer);
        printf(RESET);

        //printf("%c", VERTICAL);
        printf(BYEL);
        printf("%-*.2f", TOTAL, temp->Data.Grades.Total);
        printf(RESET);

        printf("%c\n", VERTICAL);
    }

    printf("%c", BOTTOM_LEFT);
    for(int i = 0; i < STUDENTID; i++) {printf("%c", HORIZONTAL);} //printf("%c", TOP_DASH);
    for(int i = 0; i < STUDENTNAME; i++) {printf("%c", HORIZONTAL);} //printf("%c", TOP_DASH);
    for(int i = 0; i < AGE; i++) {printf("%c", HORIZONTAL);} //printf("%c", TOP_DASH);
    for(int i = 0; i < CLASSID; i++) {printf("%c", HORIZONTAL);} //printf("%c", TOP_DASH);
    for(int i = 0; i < ENGLISH; i++) {printf("%c", HORIZONTAL);} //printf("%c", TOP_DASH);
    for(int i = 0; i < COMPUTER; i++) {printf("%c", HORIZONTAL);} //printf("%c", TOP_DASH);
    for(int i = 0; i < TOTAL; i++) {printf("%c", HORIZONTAL);} printf("%c\n", BOTTOM_RIGHT);
}

// Class tables
void TabulizeClass(Class data) {
    printf("%c", TOP_LEFT);
    for(int i = 0; i < CLASSID; i++) {printf("%c", HORIZONTAL);} //printf("%c", BOTTOM_DASH);
    for(int i = 0; i < CLASSTOTAL; i++) {printf("%c", HORIZONTAL);} //printf("%c", BOTTOM_DASH);
    for(int i = 0; i < CLASSTOTALEMPLOYEES; i++) {printf("%c", HORIZONTAL);} printf("%c\n", TOP_RIGHT);

    printf("%c", VERTICAL);
    printf(BMAG);
    printf("%-*s", CLASSID, "Class");
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BCYN);
    printf("%-*s", CLASSTOTAL, "Students");
    printf(RESET);

    printf("%c", VERTICAL);
    printf(BCYN);
    printf("%-*s", CLASSTOTAL, "Employees");
    printf(RESET);

    printf("%c\n", VERTICAL);

    printf("%c", RIGHT_DASH);
    for(int i = 0; i < CLASSID; i++) {printf("%c", HORIZONTAL);} //printf("%c", CROSS);
    for(int i = 0; i < CLASSTOTAL; i++) {printf("%c", HORIZONTAL);} //printf("%c", CROSS);
    for(int i = 0; i < CLASSTOTALEMPLOYEES; i++) {printf("%c", HORIZONTAL);} printf("%c\n", LEFT_DASH);

    printf("%c", VERTICAL);
    printf(BMAG);
    printf("%-*s", CLASSID, data.ID);
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BCYN);
    printf("%-*d", CLASSTOTAL, data.Students.Size);
    printf(RESET);

     //printf("%c", VERTICAL);
    printf(BCYN);
    printf("%-*d", CLASSTOTALEMPLOYEES, data.Employees.Size);
    printf(RESET);

    printf("%c\n", VERTICAL);

    printf("%c", BOTTOM_LEFT);
    for(int i = 0; i < CLASSID; i++) {printf("%c", HORIZONTAL);} //printf("%c", TOP_DASH);
    for(int i = 0; i < CLASSTOTAL; i++) {printf("%c", HORIZONTAL);} //printf("%c", TOP_DASH);
    for(int i = 0; i < CLASSTOTALEMPLOYEES; i++) {printf("%c", HORIZONTAL);} printf("%c\n", BOTTOM_RIGHT);
}

void TabulizeClassList(CLinked * listPointer) {
    printf("%c", TOP_LEFT);
    for(int i = 0; i < CLASSID; i++) {printf("%c", HORIZONTAL);} //printf("%c", BOTTOM_DASH);
    for(int i = 0; i < CLASSTOTAL; i++) {printf("%c", HORIZONTAL);} //printf("%c", BOTTOM_DASH);
    for(int i = 0; i < CLASSTOTALEMPLOYEES; i++) {printf("%c", HORIZONTAL);} printf("%c\n", TOP_RIGHT);

    printf("%c", VERTICAL);
    printf(BMAG);
    printf("%-*s", CLASSID, "Class");
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BCYN);
    printf("%-*s", CLASSTOTAL, "Students");
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BCYN);
    printf("%-*s", CLASSTOTALEMPLOYEES, "Employees");
    printf(RESET);

    printf("%c\n", VERTICAL);

    for (CNode * temp = listPointer->Head; temp != NULL; temp = temp->Next)
    {
        printf("%c", RIGHT_DASH);
        for(int i = 0; i < CLASSID; i++) {printf("%c", HORIZONTAL);} //printf("%c", CROSS);
        for(int i = 0; i < CLASSTOTAL; i++) {printf("%c", HORIZONTAL);} //printf("%c", CROSS);
        for(int i = 0; i < CLASSTOTALEMPLOYEES; i++) {printf("%c", HORIZONTAL);} printf("%c\n", LEFT_DASH);

        printf("%c", VERTICAL);
        printf(BMAG);
        printf("%-*s", CLASSID, temp->Data.ID);
        printf(RESET);

        //printf("%c", VERTICAL);
        printf(BCYN);
        printf("%-*d", CLASSTOTAL, temp->Data.Students.Size);
        printf(RESET);

        //printf("%c", VERTICAL);
        printf(BCYN);
        printf("%-*d", CLASSTOTAL, temp->Data.Employees.Size);
        printf(RESET);

        printf("%c\n", VERTICAL);
    }

    printf("%c", BOTTOM_LEFT);
    for(int i = 0; i < CLASSID; i++) {printf("%c", HORIZONTAL);} //printf("%c", TOP_DASH);
    for(int i = 0; i < CLASSTOTAL; i++) {printf("%c", HORIZONTAL);} //printf("%c", TOP_DASH);
    for(int i = 0; i < CLASSTOTALEMPLOYEES; i++) {printf("%c", HORIZONTAL);} printf("%c\n", BOTTOM_RIGHT);
}

// Employee tables
void TabulizeEmployee(Employee data)
{
    printf("%c", TOP_LEFT);
    for(int i = 0; i < STUDENTID; i++) {printf("%c", HORIZONTAL);} //printf("%c", BOTTOM_DASH);
    for(int i = 0; i < EMPLOYEENAME; i++) {printf("%c", HORIZONTAL);} //printf("%c", BOTTOM_DASH);
    for(int i = 0; i < AGE; i++) {printf("%c", HORIZONTAL);} //printf("%c", BOTTOM_DASH);
    for(int i = 0; i < PROFESSION; i++) {printf("%c", HORIZONTAL);} //printf("%c", BOTTOM_DASH);
    for(int i = 0; i < PHONE; i++) {printf("%c", HORIZONTAL);} printf("%c\n", TOP_RIGHT);

    printf("%c", VERTICAL);
    printf(BMAG);
    printf("%-*s", STUDENTID, "ID");
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BCYN);
    printf("%-*s", EMPLOYEENAME, "Name");
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BGRN);
    printf("%-*s", AGE, "Age");
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BYEL);
    printf("%-*s", PROFESSION, "Profession");
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BYEL);
    printf("%-*s", PHONE, "Contact");
    printf(RESET);

    printf("%c\n", VERTICAL);

    printf("%c", RIGHT_DASH);
    for(int i = 0; i < STUDENTID; i++) {printf("%c", HORIZONTAL);} //printf("%c", CROSS);
    for(int i = 0; i < EMPLOYEENAME; i++) {printf("%c", HORIZONTAL);} //printf("%c", CROSS);
    for(int i = 0; i < AGE; i++) {printf("%c", HORIZONTAL);} //printf("%c", CROSS);
    for(int i = 0; i < PROFESSION; i++) {printf("%c", HORIZONTAL);} //printf("%c", CROSS);
    for(int i = 0; i < PHONE; i++) {printf("%c", HORIZONTAL);} printf("%c\n", LEFT_DASH);

    printf("%c", VERTICAL);
    printf(BMAG);
    printf("%-*d", STUDENTID, data.ID);
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BCYN);
    printf("%-*s", EMPLOYEENAME, data.Name);
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BGRN);
    printf("%-*d", AGE, data.Age);
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BYEL);
    printf("%-*s", PROFESSION, data.Profession);
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BYEL);
    printf("%-*lu", PHONE, data.Phone);
    printf(RESET);

    printf("%c\n", VERTICAL);

    printf("%c", BOTTOM_LEFT);
    for(int i = 0; i < STUDENTID; i++) {printf("%c", HORIZONTAL);} //printf("%c", TOP_DASH);
    for(int i = 0; i < EMPLOYEENAME; i++) {printf("%c", HORIZONTAL);} //printf("%c", TOP_DASH);
    for(int i = 0; i < AGE; i++) {printf("%c", HORIZONTAL);} //printf("%c", TOP_DASH);
    for(int i = 0; i < PROFESSION; i++) {printf("%c", HORIZONTAL);} //printf("%c", TOP_DASH);
    for(int i = 0; i < PHONE; i++) {printf("%c", HORIZONTAL);} printf("%c\n", BOTTOM_RIGHT);
}

void TabulizeEmployeeList(Class * listPointer) {
    printf("%c", TOP_LEFT);
    for(int i = 0; i < STUDENTID; i++) {printf("%c", HORIZONTAL);} //printf("%c", BOTTOM_DASH);
    for(int i = 0; i < EMPLOYEENAME; i++) {printf("%c", HORIZONTAL);} //printf("%c", BOTTOM_DASH);
    for(int i = 0; i < AGE; i++) {printf("%c", HORIZONTAL);} //printf("%c", BOTTOM_DASH);
    for(int i = 0; i < CLASSID; i++) {printf("%c", HORIZONTAL);} //printf("%c", BOTTOM_DASH);
    for(int i = 0; i < PROFESSION; i++) {printf("%c", HORIZONTAL);} //printf("%c", BOTTOM_DASH);
    for(int i = 0; i < PHONE; i++) {printf("%c", HORIZONTAL);} printf("%c\n", TOP_RIGHT);

    printf("%c", VERTICAL);
    printf(BMAG);
    printf("%-*s", STUDENTID, "ID");
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BCYN);
    printf("%-*s", STUDENTNAME, "Name");
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BGRN);
    printf("%-*s", AGE, "Age");
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BBLU);
    printf("%-*s", CLASSID, "Class");
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BBLU);
    printf("%-*s", PROFESSION, "Profession");
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BYEL);
    printf("%-*s", PHONE, "Contact");
    printf(RESET);

    printf("%c\n", VERTICAL);

    for (ENode * temp = listPointer->Employees.Head; temp != NULL; temp = temp->Next)
    {
        printf("%c", RIGHT_DASH);
        for(int i = 0; i < STUDENTID; i++) {printf("%c", HORIZONTAL);} //printf("%c", CROSS);
        for(int i = 0; i < EMPLOYEENAME; i++) {printf("%c", HORIZONTAL);} //printf("%c", CROSS);
        for(int i = 0; i < AGE; i++) {printf("%c", HORIZONTAL);} //printf("%c", CROSS);
        for(int i = 0; i < CLASSID; i++) {printf("%c", HORIZONTAL);} //printf("%c", CROSS);
        for(int i = 0; i < PROFESSION; i++) {printf("%c", HORIZONTAL);} //printf("%c", CROSS);
        for(int i = 0; i < PHONE; i++) {printf("%c", HORIZONTAL);} printf("%c\n", LEFT_DASH);

        printf("%c", VERTICAL);
        printf(BMAG);
        printf("%-*d", STUDENTID, temp->Data.ID);
        printf(RESET);

        //printf("%c", VERTICAL);
        printf(BCYN);
        printf("%-*s", STUDENTNAME, temp->Data.Name);
        printf(RESET);

        //printf("%c", VERTICAL);
        printf(BGRN);
        printf("%-*d", AGE, temp->Data.Age);
        printf(RESET);

        printf(BBLU);
        printf("%-*s", CLASSID, listPointer->ID);
        printf(RESET);

        //printf("%c", VERTICAL);
        printf(BYEL);
        printf("%-*s", PROFESSION, temp->Data.Profession);
        printf(RESET);

        //printf("%c", VERTICAL);
        printf(BYEL);
        printf("%-*lu", PHONE, temp->Data.Phone);
        printf(RESET);

        printf("%c\n", VERTICAL);
    }

    printf("%c", BOTTOM_LEFT);
    for(int i = 0; i < STUDENTID; i++) {printf("%c", HORIZONTAL);} //printf("%c", TOP_DASH);
    for(int i = 0; i < EMPLOYEENAME; i++) {printf("%c", HORIZONTAL);} //printf("%c", TOP_DASH);
    for(int i = 0; i < AGE; i++) {printf("%c", HORIZONTAL);} //printf("%c", TOP_DASH);
    for(int i = 0; i < CLASSID; i++) {printf("%c", HORIZONTAL);} //printf("%c", TOP_DASH);
    for(int i = 0; i < PROFESSION; i++) {printf("%c", HORIZONTAL);} //printf("%c", TOP_DASH);
    for(int i = 0; i < PHONE; i++) {printf("%c", HORIZONTAL);} printf("%c\n", BOTTOM_RIGHT);
}

void STabulizeEmployeeList(ELinked *listPointer, Class * employeeClass) {
    printf("%c", TOP_LEFT);
    for(int i = 0; i < STUDENTID; i++) {printf("%c", HORIZONTAL);} //printf("%c", BOTTOM_DASH);
    for(int i = 0; i < EMPLOYEENAME; i++) {printf("%c", HORIZONTAL);} //printf("%c", BOTTOM_DASH);
    for(int i = 0; i < AGE; i++) {printf("%c", HORIZONTAL);} //printf("%c", BOTTOM_DASH);
    for(int i = 0; i < CLASSID; i++) {printf("%c", HORIZONTAL);} //printf("%c", BOTTOM_DASH);
    for(int i = 0; i < PROFESSION; i++) {printf("%c", HORIZONTAL);} //printf("%c", BOTTOM_DASH);
    for(int i = 0; i < PHONE; i++) {printf("%c", HORIZONTAL);} printf("%c\n", TOP_RIGHT);

    printf("%c", VERTICAL);
    printf(BMAG);
    printf("%-*s", STUDENTID, "ID");
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BCYN);
    printf("%-*s", STUDENTNAME, "Name");
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BGRN);
    printf("%-*s", AGE, "Age");
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BBLU);
    printf("%-*s", CLASSID, "Class");
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BBLU);
    printf("%-*s", PROFESSION, "Profession");
    printf(RESET);

    //printf("%c", VERTICAL);
    printf(BYEL);
    printf("%-*s", PHONE, "Contact");
    printf(RESET);

    printf("%c\n", VERTICAL);

    for (ENode * temp = listPointer->Head; temp != NULL; temp = temp->Next)
    {
        printf("%c", RIGHT_DASH);
        for(int i = 0; i < STUDENTID; i++) {printf("%c", HORIZONTAL);} //printf("%c", CROSS);
        for(int i = 0; i < EMPLOYEENAME; i++) {printf("%c", HORIZONTAL);} //printf("%c", CROSS);
        for(int i = 0; i < AGE; i++) {printf("%c", HORIZONTAL);} //printf("%c", CROSS);
        for(int i = 0; i < CLASSID; i++) {printf("%c", HORIZONTAL);} //printf("%c", CROSS);
        for(int i = 0; i < PROFESSION; i++) {printf("%c", HORIZONTAL);} //printf("%c", CROSS);
        for(int i = 0; i < PHONE; i++) {printf("%c", HORIZONTAL);} printf("%c\n", LEFT_DASH);

        printf("%c", VERTICAL);
        printf(BMAG);
        printf("%-*d", STUDENTID, temp->Data.ID);
        printf(RESET);

        //printf("%c", VERTICAL);
        printf(BCYN);
        printf("%-*s", STUDENTNAME, temp->Data.Name);
        printf(RESET);

        //printf("%c", VERTICAL);
        printf(BGRN);
        printf("%-*d", AGE, temp->Data.Age);
        printf(RESET);

        printf(BBLU);
        printf("%-*s", CLASSID, employeeClass->ID);
        printf(RESET);

        //printf("%c", VERTICAL);
        printf(BYEL);
        printf("%-*s", PROFESSION, temp->Data.Profession);
        printf(RESET);

        //printf("%c", VERTICAL);
        printf(BYEL);
        printf("%-*lu", PHONE, temp->Data.Phone);
        printf(RESET);

        printf("%c\n", VERTICAL);
    }

    printf("%c", BOTTOM_LEFT);
    for(int i = 0; i < STUDENTID; i++) {printf("%c", HORIZONTAL);} //printf("%c", TOP_DASH);
    for(int i = 0; i < EMPLOYEENAME; i++) {printf("%c", HORIZONTAL);} //printf("%c", TOP_DASH);
    for(int i = 0; i < AGE; i++) {printf("%c", HORIZONTAL);} //printf("%c", TOP_DASH);
    for(int i = 0; i < CLASSID; i++) {printf("%c", HORIZONTAL);} //printf("%c", TOP_DASH);
    for(int i = 0; i < PROFESSION; i++) {printf("%c", HORIZONTAL);} //printf("%c", TOP_DASH);
    for(int i = 0; i < PHONE; i++) {printf("%c", HORIZONTAL);} printf("%c\n", BOTTOM_RIGHT);
}
