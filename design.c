#include "functions.h"
#include "design.h"

void displayLogo(int wait) {
    printf(BBLU);
    printf("	 ____   ____ _   _  ___   ___  _     \n");
    delay(wait);
    printf("	/ ___| / ___| | | |/ _ \\ / _ \\| |    \n");
    delay(wait);
    printf("	\\___ \\| |   | |_| | | | | | | | |    \n");
    delay(wait);
    printf("	 ___) | |___|  _  | |_| | |_| | |___ \n");
    delay(wait);
    printf("	|____/ \\____|_| |_|\\___/ \\___/|_____|\n");
    delay(wait*2);
    printf(BGRN);
    printf(" __  __    _    _   _    _    ____ _____ __  __ _____ _   _ _____ \n");
    delay(wait);
    printf("|  \\/  |  / \\  | \\ | |  / \\  / ___| ____|  \\/  | ____| \\ | |_   _|\n");
    delay(wait);
    printf("| |\\/| | / _ \\ |  \\| | / _ \\| |  _|  _| | |\\/| |  _| |  \\| | | |  \n");
    delay(wait);
    printf("| |  | |/ ___ \\| |\\  |/ ___ \\ |_| | |___| |  | | |___| |\\  | | |  \n");
    delay(wait);
    printf("|_|  |_/_/   \\_\\_| \\_/_/   \\_\\____|_____|_|  |_|_____|_| \\_| |_|  \n");
    delay(wait*2);
    printf(BYEL);
    printf("		 ______   ______ _____ _____ __  __ \n");
    delay(wait);
    printf("		/ ___\\ \\ / / ___|_   _| ____|  \\/  |\n");
    delay(wait);
    printf("		\\___ \\\\ V /\\___ \\ | | |  _| | |\\/| |\n");
    delay(wait);
    printf("		 ___) || |  ___) || | | |___| |  | |\n");
    delay(wait);
    printf("		|____/ |_| |____/ |_| |_____|_|  |_|\n");
    printf(RESET);
    delay(wait*2);
}

void RectangulizeCenterAlign(char Text[], int Width) {
    int spaceWidth = (int)((Width - strlen(Text)) / 2);

    printf("%c", TOP_LEFT);
    for (short i = 0; i < Width; i++) {
        printf("%c", HORIZONTAL);
    }
    printf("%c\n", TOP_RIGHT);

    printf("%c", VERTICAL);
    for (int i = 0; i < spaceWidth; i++) {
        printf(" ");
    }
    printf("%s", Text);
    if (strlen(Text) % 2 != 0) {
        printf(" ");
    }
    for (int i = 0; i < spaceWidth; i++) {
        printf(" ");
    }
    printf("%c\n", VERTICAL);

    printf("%c", BOTTOM_LEFT);
    for (short i = 0; i < Width; i++) {
        printf("%c", HORIZONTAL);
    }
    printf("%c\n", BOTTOM_RIGHT);
}

void Error(char Text[]) {
    int Width = 50;

    printf(BRED);

    int spaceWidth = (int)((Width - strlen(Text)) / 2);

    printf("%c", TOP_LEFT);
    for (short i = 0; i < Width; i++) {
        printf("%c", HORIZONTAL);
    }
    printf("%c\n", TOP_RIGHT);

    printf("%c", VERTICAL);
    for (int i = 0; i < spaceWidth; i++) {
        printf(" ");
    }
    printf("%s", Text);
    if (strlen(Text) % 2 != 0) {
        printf(" ");
    }
    for (int i = 0; i < spaceWidth; i++) {
        printf(" ");
    }
    printf("%c\n", VERTICAL);

    printf("%c", BOTTOM_LEFT);
    for (short i = 0; i < Width; i++) {
        printf("%c", HORIZONTAL);
    }
    printf("%c\n", BOTTOM_RIGHT);

    printf(RESET);

    printf("Press any key to return");
    getch();
    system("cls");
}

void Success(char Text[]) {
    printf(BGRN);
    RectangulizeCenterAlign(Text, 50);
    printf(RESET);
    printf("Press any key to continue");
    getch();
    system("cls");
}

void delay(int millis) {
    clock_t start = clock();

    while (clock() < start + millis);
}

void MessageBox(char **Text, int paragraphCount, int width) {
    int spaceWidth;

    printf("%c", TOP_LEFT);
    for (int i = 0; i < width; i++)
    {
        printf("%c", HORIZONTAL);
    }
    printf("%c\n", TOP_RIGHT);

    for (int i = 0; i < paragraphCount; i++) {
        printf("%c", VERTICAL);

        spaceWidth = (int)((width - strlen(Text[i])) / 2);
        for (int i = 0; i < spaceWidth; i++) {
        printf(" ");
        }
        printf("%s", Text[i]);
        if (strlen(Text) % 2 != 0) {
            printf(" ");
        }
        for (int i = 0; i < spaceWidth; i++) {
            printf(" ");
        }
        printf("%c\n", VERTICAL);
    }

    printf("%c", BOTTOM_LEFT);
    for (int i = 0; i < width; i++)
    {
        printf("%c", HORIZONTAL);
    }
    printf("%c\n", BOTTOM_RIGHT);
}
