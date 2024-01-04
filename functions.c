#include "functions.h"
#include "design.h"

#define M_MENU_SIZE 5
#define STUDENT_MENU 1
#define CLASS_MENU 2
#define DESTROY_EVERYTHING 3
#define CREDITS 4
#define EXIT M_MENU_SIZE

#define S_MENU_SIZE 6
#define NEW_STUDENT 1
#define VIEW_STUDENTS_ALL 2
#define SEARCH_STUDENT 3
#define EDIT_STUDENT 4
#define DELETE_STUDENT 5
#define S_MENU_BACK S_MENU_SIZE

#define C_MENU_SIZE 11
#define NEW_CLASS 1
#define VIEW_CLASSES 2
#define SORT_CLASSES 3
#define VIEW_STUDENTS 4
#define SEARCH_CLASS 5
#define EDIT_CLASS 6
#define RANK_CLASS_STUDENTS 7
#define SORT_STUDENTS 8
#define DESTROY_STUDENTS 9
#define DELETE_CLASS 10
#define C_MENU_BACK C_MENU_SIZE

#define SORT_BY_ID 1
#define SORT_BY_NAME 2
#define SORT_BY_AGE 3
#define SORT_BY_STUDENT_COUNT 4

#define SIMPLIFY 1

char *message[12] = {
    "Thank you Eng. Hassan for being",
    "a wonderful instructor and for your",
    "commitment to teaching us about all",
    "the subjects we did not know before. ",
    " ",
    "Your influence extends far beyond the",
    "classroom, and I am inspired to carry",
    "the knowledge and skills I've gained ",
    "under your guidance into the future. ",
    " ",
    " ",
    "Regards, Fares Mostafa "
};

void program() {
    char tempText[100];
    char *mainMenuoptions[M_MENU_SIZE] = {
        "Student options",
        "Class options",
        "[DANGER] Clear school",
        "Credits",
        "Exit"
    };

    char *studentMenuOptions[S_MENU_SIZE] = {
        "New student",
        "View all students",
        "Find student",
        "Edit student",
        "Delete student",
        "Back",
    };

    char *classMenuOptions[C_MENU_SIZE] = {
        "Create class",
        "View class list",
        "Sort class list",
        "View class students",
        "Find class",
        "Edit class",
        "Rank class",
        "Sort class",
        "Clear class",
        "Delete class",
        "Back"
    };

    char *classSortOptions[3] = {
        "Sort by ID",
        "Sort by student count",
        "Cancel"
    };

    char *studentSortOptions[4] = {
        "Sort by ID",
        "Sort by name",
        "Sort by age",
        "Cancel"
    };

    char *confirmOptions[2] = {
        "Confirm",
        "Cancel"
    };

    int select;
    bool quit = false;
    bool back = false;

    CLinked school;
    CLinked searchResults;
    SLinked students;
    SLinked studentSearchResults;
    createClassList(&school);
    Class newClass;
    Student newStudent;
    SNode *foundStudent;
    Class *foundClass;
    char searchTerm[6];
    int IDSearch;

    displayLogo(50);
    delay(1500);

    while (!quit) {
        system("cls");
        back = false;
        select = selectMenu(mainMenuoptions, M_MENU_SIZE, &school);
        fflush(stdin);
        system("cls");

        if (school.Head == NULL && select != CLASS_MENU && select != EXIT && select != CREDITS) {
            Error("You must create a class first");
            system("cls");
            continue;
        }

        switch(select) {
        case STUDENT_MENU:
            while (!back) {
                select = selectMenu(studentMenuOptions, S_MENU_SIZE, &school);
                system("cls");

                switch (select) {
                case NEW_STUDENT:
                    printf("Input student's class name (id): ");
                    gets(searchTerm);

                    foundClass = findClass(&school, searchTerm);
                    if (foundClass == NULL) {
                        sprintf(tempText, "Could not find class \"%s\"", searchTerm);
                        Error(tempText);
                        system("cls");
                        break;
                    }

                    newStudent = inputStudentData(&foundClass->Students);
                    insertStudent(&foundClass->Students, newStudent);
                    recountStudents(&foundClass->Students);
                    sprintf(tempText, "Successfully added \"%s\" to \"%s\"", newStudent.Name, foundClass->ID);
                    Success(tempText);
                    system("cls");
                    break;

                case VIEW_STUDENTS_ALL:
                    for (CNode * temp = school.Head; temp != NULL; temp = temp->Next) {
                        if (temp->Data.Students.Head == NULL) {
                            sprintf(tempText, "No students in class \"%s\"", temp->Data.ID);
                            printf(BRED);
                            RectangulizeCenterAlign(tempText, 76);
                            printf(RESET);
                            continue;
                        }
                        TabulizeStudentList(&temp->Data);
                    }

                    getch();
                    system("cls");
                    break;

                case SEARCH_STUDENT:
                    printf("Input student ID: ");
                    scanf("%d", &IDSearch);
                    fflush(stdin);

                    for (CNode * temp = school.Head; temp != NULL; temp = temp->Next) {
                        studentSearchResults = findStudents(&temp->Data, IDSearch);
                        if (studentSearchResults.Head != NULL) {
                            STabulizeStudentList(&studentSearchResults, &temp->Data);
                        } else {
                            Error("No students found");
                        }
                    }

                    system("cls");
                    break;

                case EDIT_STUDENT:
                    printf("Input class name (id): ");
                    gets(searchTerm);

                    foundClass = findClass(&school, searchTerm);
                    if (foundClass == NULL) {
                        sprintf(tempText, "Could not find class \"%s\"", searchTerm);
                        Error(tempText);
                        system("cls");
                        break;
                    }

                    printf("Input student ID: ");
                    scanf("%d", &IDSearch);
                    fflush(stdin);

                    foundStudent = findStudent(&foundClass->Students, IDSearch);
                    if (foundStudent == NULL) {
                        sprintf(tempText, "Could not find student \"%d\"", IDSearch);
                        Error(tempText);
                        system("cls");
                        break;
                    }

                    TabulizeStudent(foundStudent->Data);

                    foundStudent->Data = inputStudentData(&foundClass->Students);

                    sprintf(tempText, "Successfully edited data for \"%s\"", foundStudent->Data.Name);
                    Success(tempText);
                    system("cls");
                    break;

                case DELETE_STUDENT:
                    printf("Input class name (id): ");
                    gets(searchTerm);

                    foundClass = findClass(&school, searchTerm);
                    if (foundClass == NULL) {
                        sprintf(tempText, "Could not find class \"%s\"", searchTerm);
                        Error(tempText);
                        system("cls");
                        break;
                    }

                    printf("Input student ID: ");
                    scanf("%d", &IDSearch);
                    fflush(stdin);

                    foundStudent = findStudent(&foundClass->Students, IDSearch);
                    if (foundStudent == NULL) {
                        sprintf(tempText, "Could not find student \"%d\"", IDSearch);
                        Error(tempText);
                        system("cls");
                        break;
                    }

                    sprintf(tempText, "Are you sure you would like to permanently delete \"%s\"?", foundStudent->Data.Name);
                    select = altSelectMenu(confirmOptions, 2, tempText);

                    if (select == 1) {
                        deleteStudent(&foundClass->Students, foundStudent);
                        Success("Student deleted successfully");
                    } else {
                        Success("Operation canceled");
                    }
                    system("cls");
                    break;

                case S_MENU_BACK:
                    back = true;
                    break;
                }
            }
            break;

        case CLASS_MENU:
            while (!back) {
                select = selectMenu(classMenuOptions, C_MENU_SIZE, &school);
                system("cls");

                switch (select) {
                    case NEW_CLASS:
                        newClass = inputClassData(&school);

                        createStudentList(&students);
                        newClass.Students = students;

                        insertClass(&school, newClass);
                        sprintf(tempText, "Successfully created class \"%s\"!", newClass.ID);
                        Success(tempText);
                        recountClasses(&school);
                    break;

                    case VIEW_CLASSES:
                        sprintf(tempText, "Displaying %d classes", school.Size);
                        printf(BBLU);
                        RectangulizeCenterAlign(tempText, 20);
                        printf(RESET);
                        TabulizeClassList(&school);
                        printf("Press any key to return");
                        getch();
                        system("cls");
                    break;

                    case VIEW_STUDENTS:
                        printf("Input class name (id): ");
                        gets(searchTerm);

                        foundClass = findClass(&school, searchTerm);
                        if (foundClass == NULL) {
                            sprintf(tempText, "Could not find class \"%s\"", searchTerm);
                            Error(tempText);
                            system("cls");
                            break;
                        }

                        if (foundClass->Students.Head == NULL) {
                            sprintf(tempText, "Class \"%s\" is empty", foundClass->ID);
                            Error(tempText);
                            system("cls");
                            break;
                        }

                        sprintf(tempText, "Displaying %d students", foundClass->Students.Size);
                        printf(BBLU);
                        RectangulizeCenterAlign(tempText, 76);
                        printf(RESET);
                        TabulizeStudentList(foundClass);
                        printf("Press any key to return");
                        getch();
                        system("cls");
                    break;

                    case SORT_CLASSES:
                        select = selectMenu(classSortOptions, 3, &school);
                        system("cls");

                        switch (select) {
                        case 1:
                            sortClasses(&school, 1);
                            Success("Sorted successfully");
                            TabulizeClassList(&school);
                            getch();
                            system("cls");
                            break;

                        case 2:
                            sortClasses(&school, 4);
                            Success("Sorted successfully");
                            TabulizeClassList(&school);
                            getch();
                            system("cls");
                            break;

                        case 3:
                            break;
                        }
                    break;

                    case SEARCH_CLASS:
                        printf("Input class name (id): ");
                        gets(searchTerm);
                        fflush(stdin);

                        searchResults = findClasses(&school, searchTerm);
                        if (searchResults.Head == NULL) {
                            Error("No classes found");
                            system("cls");
                            break;
                        }

                        TabulizeClassList(&searchResults);

                        getch();
                        system("cls");
                    break;

                    case EDIT_CLASS:
                        printf("Input class name (id): ");
                        gets(searchTerm);

                        foundClass = findClass(&school, searchTerm);
                        if (foundClass == NULL) {
                            sprintf(tempText, "Could not find class \"%s\"", searchTerm);
                            Error(tempText);
                            system("cls");
                            break;
                        }

                        newClass = inputClassData(&school);
                        strcpy(foundClass->ID, newClass.ID);
                        sprintf(tempText, "Successfully edited data for \"%s\"", foundClass->ID);
                        Success(tempText);
                        system("cls");
                    break;

                    case RANK_CLASS_STUDENTS:
                        printf("Input class name (id): ");
                        gets(searchTerm);

                        foundClass = findClass(&school, searchTerm);
                        if (foundClass == NULL) {
                            sprintf(tempText, "Could not find class \"%s\"", searchTerm);
                            Error(tempText);
                            system("cls");
                            break;
                        }

                        if (foundClass->Students.Head == NULL) {
                            sprintf(tempText, "Class \"%s\" is empty", foundClass->ID);
                            Error(tempText);
                            system("cls");
                            break;
                        }

                        rankStudents(&foundClass->Students);
                        printf(BGRN);
                        sprintf(tempText, "Successfully ranked class \"%s\"", foundClass->ID);
                        RectangulizeCenterAlign(tempText, 76);
                        printf(RESET);
                        TabulizeStudentList(foundClass);
                        printf("Press any key to return\n");
                        getch();
                        system("cls");
                    break;

                    case SORT_STUDENTS:
                        printf("Input class name (id): ");
                        gets(searchTerm);

                        foundClass = findClass(&school, searchTerm);
                        if (foundClass == NULL) {
                            sprintf(tempText, "Could not find class \"%s\"", searchTerm);
                            Error(tempText);
                            system("cls");
                            break;
                        }

                        select = selectMenu(studentSortOptions, 4, &school);
                        system("cls");

                        switch (select) {
                        case 1:
                            sortStudents(&foundClass->Students, SORT_BY_ID);
                            Success("Sorted successfully");
                            TabulizeStudentList(foundClass);
                            getch();
                            system("cls");
                            break;

                        case 2:
                            sortStudents(&foundClass->Students, SORT_BY_NAME);
                            Success("Sorted successfully");
                            TabulizeStudentList(foundClass);
                            getch();
                            system("cls");
                            break;

                        case 3:
                            sortStudents(&foundClass->Students, SORT_BY_AGE);
                            Success("Sorted successfully");
                            TabulizeStudentList(foundClass);
                            getch();
                            system("cls");
                            break;

                        case 4:
                            break;
                        }

                    break;

                    case DESTROY_STUDENTS:
                        printf("Input class name (id): ");
                        gets(searchTerm);

                        foundClass = findClass(&school, searchTerm);
                        if (foundClass == NULL) {
                            sprintf(tempText, "Could not find class \"%s\"", searchTerm);
                            Error(tempText);
                            system("cls");
                            break;
                        }

                        sprintf(tempText, "Are you sure you would like to permanently clear \"%s\"?", foundClass->ID);
                        select = altSelectMenu(confirmOptions, 2, tempText);

                        if (select == 1) {
                            destroyStudents(&foundClass->Students);
                            Success("All students cleared successfully");
                        } else {
                            Error("Operation canceled");
                        }
                        system("cls");
                    break;

                    case DELETE_CLASS:
                        printf("Input class name (id): ");
                        gets(searchTerm);

                        foundClass = findClass(&school, searchTerm);
                        if (foundClass == NULL) {
                            sprintf(tempText, "Could not find class \"%s\"", searchTerm);
                            Error(tempText);
                            system("cls");
                            break;
                        }

                        sprintf(tempText, "Are you sure you would like to permanently delete \"%s\"?", foundClass->ID);
                        select = altSelectMenu(confirmOptions, 2, tempText);

                        if (select == 1) {
                            deleteClass(&school, foundClass);
                            Success("Class deleted successfully");
                        } else {
                            Error("Operation canceled");
                        }
                        system("cls");
                    break;

                    case C_MENU_BACK:
                        back = true;
                    break;
                }
            }
            break;

        case DESTROY_EVERYTHING:
            select = dangerSelectMenu(confirmOptions, 2, "Are you sure you would like to permanently clear database?");

            if (select == 1) {
                destroyClasses(&school);
                Success("Database cleared successfully");
            } else {
                Error("Operation canceled");
            }

            system("cls");
            break;

        case CREDITS:
            printf(BBLU);
            displayLogo(50);
            delay(1000);
            printf(BCYN);
            RectangulizeCenterAlign("Made by", 50);
            RectangulizeCenterAlign("Fares Mostafa", 50);
            delay(1000);
            printf(BMAG);
            RectangulizeCenterAlign("Supervision", 50);
            RectangulizeCenterAlign("Eng. Hassan Talal", 50);
            delay(1000);
            printf(RESET);
            getch();
            system("cls");

            MessageBox(message, 12, 50);
            getch();
            break;

        case EXIT:
            select = altSelectMenu(confirmOptions, 2, "Are you sure you would like to exit?");
            if (select == 1) {
                quit = true;
            }

            system("cls");
            break;
        }

    }
}

void createStudentList(SLinked * listPointer) {
    listPointer->Head = NULL;
    listPointer->Tail = NULL;
    listPointer->Size = 0;
}

void createClassList(CLinked * listPointer) {
    listPointer->Head = NULL;
    listPointer->Tail = NULL;
    listPointer->Size = 0;
}

void appendStudent(SLinked * listPointer, Student data) {
    SNode * newStudent = malloc(sizeof(SNode));

    newStudent->Data = data;
    newStudent->Next = NULL;
    newStudent->Previous = NULL;

    if (listPointer->Head == NULL) {
        listPointer->Head = newStudent;
    } else {
        listPointer->Tail->Next = newStudent;
        newStudent->Previous = listPointer->Tail;
    }

    listPointer->Tail = newStudent;
    listPointer->Size++;
}

void appendClass(CLinked * listPointer, Class c) {
    CNode * newClass = malloc(sizeof(CNode));

    newClass->Data = c;
    newClass->Next = NULL;
    newClass->Previous = NULL;

    if (listPointer->Head == NULL) {
        listPointer->Head = newClass;
    } else {
        listPointer->Tail->Next = newClass;
        newClass->Previous = listPointer->Tail;
    }

    listPointer->Tail = newClass;
    listPointer->Size++;
}

void insertStudent(SLinked * listPointer, Student data) {
    SNode * newStudent = malloc(sizeof(SNode));

    if (newStudent == NULL) {
        printf("Could not allocate memory for new node");
        return;
    }

    newStudent->Data = data;
    newStudent->Next = NULL;
    newStudent->Previous = NULL;

    if (listPointer->Head == NULL) {
        appendStudent(listPointer, data);
        return;
    }

    SNode * temp = listPointer->Head;
    while (temp != NULL && temp->Data.ID < newStudent->Data.ID) {
        temp = temp->Next;
    }

    if (temp == listPointer->Head) {
        // Insert at head
        newStudent->Next = listPointer->Head;
        listPointer->Head->Previous = newStudent;
        listPointer->Head = newStudent;
    } else if (temp == NULL) {
        // Insert at tail
        newStudent->Previous = listPointer->Tail;
        listPointer->Tail->Next = newStudent;
        listPointer->Tail = newStudent;
    } else {
        // Insert in middle
        newStudent->Next = temp;
        newStudent->Previous = temp->Previous;
        temp->Previous->Next = newStudent;
        temp->Previous = newStudent;
    }

    listPointer->Size++;
}

void insertClass(CLinked * listPointer, Class data) {
    CNode * newClass = malloc(sizeof(CNode));

    if (newClass == NULL) {
        printf("Could not allocate memory for new node");
        return;
    }

    newClass->Data = data;
    newClass->Next = NULL;
    newClass->Previous = NULL;

    if (listPointer->Head == NULL) {
        appendClass(listPointer, data);
        return;
    }

    CNode * temp = listPointer->Head;
    while (temp != NULL && strcmp(temp->Data.ID, newClass->Data.ID) == -1) {
        temp = temp->Next;
    }

    if (temp == listPointer->Head) {
        // Insert at head
        newClass->Next = listPointer->Head;
        listPointer->Head->Previous = newClass;
        listPointer->Head = newClass;
    } else if (temp == NULL) {
        // Insert at tail
        newClass->Previous = listPointer->Tail;
        listPointer->Tail->Next = newClass;
        listPointer->Tail = newClass;
    } else {
        // Insert in middle
        newClass->Next = temp;
        newClass->Previous = temp->Previous;
        temp->Previous->Next = newClass;
        temp->Previous = newClass;
    }

    listPointer->Size++;
}

SNode * findStudent(SLinked * listPointer, int search) {
    for (SNode * temp = listPointer->Head; temp != NULL; temp = temp->Next) {
        if ( temp->Data.ID == search ) {
            return temp;
        }
    }

    return NULL;
}

SLinked findStudents(Class * listPointer, int search) {
    SLinked students;
    createStudentList(&students);

    for (SNode * temp = listPointer->Students.Head; temp != NULL; temp = temp->Next) {
        if ( temp->Data.ID == search ) {
            appendStudent(&students, temp->Data);
        }
    }

    return students;
}

Class * findClass(CLinked * listPointer, char search[]) {
    for (CNode * temp = listPointer->Head; temp != NULL; temp = temp->Next) {
        if ( strcmp(temp->Data.ID, search) == 0) {
            return &temp->Data;
        }
    }

    return NULL;
}

CLinked findClasses(CLinked * listPointer, char* search) {
    CLinked classes;
    createClassList(&classes);

    for (CNode * temp = listPointer->Head; temp != NULL; temp = temp->Next) {
        if ( strstr(temp->Data.ID, search) != NULL) {
            appendClass(&classes, temp->Data);
        }
    }

    return classes;
}

Student inputStudentData(SLinked *studentList) {
    Student returnStudent;
    char ERRMSG[70];
    bool restart = false;

    do {
        restart = false;
        printf("Input student ID: ");
        scanf("%d", &returnStudent.ID);
        fflush(stdin);

        for (SNode *temp = studentList->Head; temp != NULL; temp = temp->Next) {
            if ( temp->Data.ID == returnStudent.ID ) {
                restart = true;
                sprintf(ERRMSG, "\"%d\" is already registered as \"%s\"", returnStudent.ID, temp->Data.Name);
                Error(ERRMSG);
                system("cls");
            }

            if ( returnStudent.ID < 1 || returnStudent.ID > 9999 ) {
                restart = true;
                sprintf(ERRMSG, "%d is not a valid ID value", returnStudent.ID);
                Error(ERRMSG);
                system("cls");
            }
        }
    } while (restart);

    do {
        restart = false;
        printf("Input student name: ");
        gets(returnStudent.Name);
        fflush(stdin);

        for (SNode *temp = studentList->Head; temp != NULL; temp = temp->Next) {
            if ( strcmp(temp->Data.Name, returnStudent.Name) == 0 ) {
                restart = true;
                sprintf(ERRMSG, "\"%s\" is already registered", temp->Data.Name);
                Error(ERRMSG);
                system("cls");
            }
        }
    } while (restart);

    do {
        restart = false;
        printf("Input student age: ");
        scanf("%d", &returnStudent.Age);
        fflush(stdin);

        if (returnStudent.Age < 1 || returnStudent.Age > 99) {
            restart = true;
            Error("That is not a valid age value");
            system("cls");
        }
    } while (restart);

    do {
        restart = false;
        printf("Input student English grade: ");
        scanf("%f", &returnStudent.Grades.English);
        fflush(stdin);

        if (returnStudent.Grades.English < 0 || returnStudent.Grades.English > 100) {
            restart = true;
            Error("That is not a valid grade value");
            system("cls");
        }
    } while (restart);

    do {
        restart = false;
        printf("Input student Computer grade: ");
        scanf("%f", &returnStudent.Grades.Computer);
        fflush(stdin);

        if (returnStudent.Grades.Computer < 0 || returnStudent.Grades.Computer > 100) {
            restart = true;
            Error("That is not a valid grade value");
            system("cls");
        }
    } while (restart);

    returnStudent.Grades.Total = (returnStudent.Grades.English + returnStudent.Grades.Computer) * 100 / 200;

    return returnStudent;
}

Class inputClassData(CLinked * listPointer) {
    Class returnClass;
    bool restart = false;

    do {
        restart = false;
        printf("Input class name (id): ");
        gets(returnClass.ID);
        fflush(stdin);

        for (CNode * temp = listPointer->Head; temp != NULL; temp = temp->Next) {
            if ( strcmp(temp->Data.ID, returnClass.ID) == 0 ) {
                restart = true;
                Error("That ID is already registered");
                system("cls");
            }
        }

        if (strlen(returnClass.ID) > 5 || strlen(returnClass.ID) < 1) {
            restart = true;
            Error("Out of bound ID");
            system("cls");
        }
    } while (restart);

    return returnClass;
}

void rankStudents(SLinked * listPointer) {
    bool swapped = false;

    do {
        swapped = false;
        SNode * temp = listPointer->Head;

        while (temp != NULL && temp->Next != NULL) {
            if (temp->Data.Grades.Total < temp->Next->Data.Grades.Total) {
                swapped = true;
                swapNodes(temp, temp->Next, listPointer);
            }
            temp = temp->Next;
        }
    } while (swapped);
}

void deleteStudent(SLinked * listPointer, SNode * student) {
    if (listPointer->Head == student && listPointer->Tail == student) {
        // Deleting only element in list
        listPointer->Head = NULL;
        listPointer->Tail = NULL;
    } else if (listPointer->Head == student) {
        // Delete first element
        listPointer->Head = student->Next;
        listPointer->Head->Previous = NULL;
        student->Next = NULL;
    } else if (listPointer->Tail == student) {
        // Delete last element
        listPointer->Tail = student->Previous;
        listPointer->Tail->Next = NULL;
        student->Previous = NULL;
    } else {
        // Delete center element
        student->Next->Previous = student->Previous;
        student->Previous->Next = student->Next;
        student->Next = NULL;
        student->Previous = NULL;
    }
    free(student);
    listPointer->Size--;
}

void deleteClass(CLinked * listPointer, CNode * class) {
    if (listPointer->Head == class && listPointer->Tail == class) {
        // Deleting only element in list
        listPointer->Head = NULL;
        listPointer->Tail = NULL;
    } else if (listPointer->Head == class) {
        // Delete first element
        listPointer->Head = class->Next;
        listPointer->Head->Previous = NULL;
        class->Next = NULL;
    } else if (listPointer->Tail == class) {
        // Delete last element
        listPointer->Tail = class->Previous;
        listPointer->Tail->Next = NULL;
        class->Previous = NULL;
    } else {
        // Delete center element
        class->Next->Previous = class->Previous;
        class->Previous->Next = class->Next;
        class->Next = NULL;
        class->Previous = NULL;
    }
    free(class);
    listPointer->Size--;
}

void destroyStudents(SLinked * listPointer) {
    SNode * temp = listPointer->Head;
    while (temp != NULL) {
        temp = temp->Next;
        free(listPointer->Head);
        listPointer->Head = temp;
    }
    listPointer->Tail = NULL;
    listPointer->Size = 0;
}

void destroyClasses(CLinked * listPointer) {
    CNode * temp = listPointer->Head;
    while (temp != NULL) {
        temp = temp->Next;
        free(listPointer->Head);
        listPointer->Head = temp;
    }
    listPointer->Tail = NULL;
    listPointer->Size = 0;
}

void sortStudents(SLinked * listPointer, int sortType) {
    bool swapped = false;

    do {
        swapped = false;
        SNode * temp = listPointer->Head;

        switch (sortType) {
        case 1:
            while (temp != NULL && temp->Next != NULL) {
                if (temp->Data.ID > temp->Next->Data.ID) {
                    swapped = true;
                    swapNodes(temp, temp->Next, listPointer);
                }
                temp = temp->Next;
            }
            break;

        case 2:
            while (temp != NULL && temp->Next != NULL) {
                if ( strcmp(temp->Data.Name, temp->Next->Data.Name) == 1) {
                    swapped = true;
                    swapNodes(temp, temp->Next, listPointer);
                }
                temp = temp->Next;
            }
            break;

        case 3:
            while (temp != NULL && temp->Next != NULL) {
                if (temp->Data.Age > temp->Next->Data.Age) {
                    swapped = true;
                    swapNodes(temp, temp->Next, listPointer);
                }
                temp = temp->Next;
            }
            break;

        }

    } while (swapped);
}

void sortClasses(CLinked * listPointer, int sortType) {
    bool swapped = false;

    do {
        swapped = false;
        CNode * temp = listPointer->Head;

        switch (sortType) {
        case 4:
            while (temp != NULL && temp->Next != NULL) {
                if (temp->Data.Students.Size > temp->Next->Data.Students.Size) {
                    swapped = true;
                    swapNodes(temp, temp->Next, listPointer);
                }
                temp = temp->Next;
            }
            break;

        case 1:
            while (temp != NULL && temp->Next != NULL) {
                if ( strcmp(temp->Data.ID, temp->Next->Data.ID) == 1) {
                    swapped = true;
                    swapNodes(temp, temp->Next, listPointer);
                }
                temp = temp->Next;
            }
            break;
        }

    } while (swapped);
}

int recountStudents(SLinked * listPointer) {
    int count = 0;
    for (SNode * temp = listPointer->Head; temp != NULL; temp = temp->Next) {
        count++;
    }
    listPointer->Size = count;
    return count;
}

int recountClasses(CLinked * listPointer) {
    int count = 0;
    for (CNode * temp = listPointer->Head; temp != NULL; temp = temp->Next) {
        count++;
    }
    listPointer->Size = count;
    return count;
}

void swapNodes(SNode * a, SNode * b, SLinked * listPointer) {
    SNode * aPrevious = a->Previous;
    SNode * bNext = b->Next;

    a->Next = b->Next;
    a->Previous = b;
    b->Previous = aPrevious;
    b->Next = a;

    if (aPrevious == NULL) {
        listPointer->Head = b;
    } else {
        aPrevious->Next = b;
    }

    if (bNext == NULL) {
        listPointer->Tail = a;
    } else {
        bNext->Previous = a;
    }
}
