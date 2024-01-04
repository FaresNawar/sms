#include "functions.h"
#include "design.h"

int selectMenu(char **options, int count, CLinked * listPointer) {
    int key;
    char tempText[100];
    static int option = 1;
    bool selected = false;

    while (!selected) {
        system("cls");

        printf(BBLU);
        RectangulizeCenterAlign("School Management System", 50);
        sprintf(tempText, "%d classes in database", listPointer->Size);
        printf(BCYN);
        RectangulizeCenterAlign(tempText, 50);
        printf(RESET);

        for (int i = 1; i <= count; i++) {
            if (i == option) {
                printf(BGRN);
            } else {
                printf(BBLK);
            }
            RectangulizeCenterAlign(options[i-1], 50 );
            printf(RESET);
        }

        key = getch();

        switch (key) {
        case 72: // up arrow:
            option--;
            break;
        case 80: // down arrow:
            option++;
            break;
        case 32: // space:
            selected = true;
            break;
        case 13:
            selected = true;
            break;
        default:
            break;
        }

        option = ((option > count ? 1 : (option < 1 ? count : option)));
    }

    return option;
}

int altSelectMenu(char **options, int count, char* text) {
    int key;
    static int option = 1;
    bool selected = false;

    while (!selected) {
        system("cls");
        printf(BYEL);
        RectangulizeCenterAlign(text, 76);
        printf(RESET);
        for (int i = 1; i <= count; i++) {
            if (i == option) {
                printf(BYEL);
            } else {
                printf(BBLK);
            }
            RectangulizeCenterAlign(options[i-1], 50 );
            printf(RESET);
        }

        key = getch();

        switch (key) {
        case 72: // up arrow:
            option--;
            break;
        case 80: // down arrow:
            option++;
            break;
        case 32: // space:
            selected = true;
            break;
        case 13:
            selected = true;
            break;
        default:
            break;
        }

        option = ((option > count ? 1 : (option < 1 ? count : option)));
    }

    return option;
}

int dangerSelectMenu(char **options, int count, char* text) {
    int key;
    static int option = 1;
    bool selected = false;

    while (!selected) {
        system("cls");
        printf(REDHB);
        RectangulizeCenterAlign("WARNING: IRREPARABLE DAMAGE AHEAD", 76);
        printf(RESET);
        printf(RED);
        RectangulizeCenterAlign(text, 76);
        printf(RESET);
        for (int i = 1; i <= count; i++) {
            if (i == option) {
                printf(BYEL);
            } else {
                printf(BBLK);
            }
            RectangulizeCenterAlign(options[i-1], 50 );
            printf(RESET);
        }

        key = getch();

        switch (key) {
        case 72: // up arrow:
            option--;
            break;
        case 80: // down arrow:
            option++;
            break;
        case 32: // space:
            selected = true;
            break;
        case 13:
            selected = true;
            break;
        default:
            break;
        }

        option = ((option > count ? 1 : (option < 1 ? count : option)));
    }

    return option;
}

int simpleSelectMenu(char **options, int count) {
    int key;
    static int option = 1;
    bool selected = false;

    while (!selected) {
        system("cls");
        for (int i = 1; i <= count; i++) {
            if (i == option) {
                printf(BGRN);
            } else {
                printf(BBLK);
            }
            printf("%d. %s\n", i, options[i-1]);
            printf(RESET);
        }

        key = getch();

        switch (key) {
        case 72: // up arrow:
            option--;
            break;
        case 80: // down arrow:
            option++;
            break;
        case 32: // space:
            selected = true;
            break;
        case 13:
            selected = true;
            break;
        default:
            break;
        }

        option = ((option > count ? 1 : (option < 1 ? count : option)));
    }

    return option;
}
