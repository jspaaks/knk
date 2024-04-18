#include <stdio.h>


int main (void) {

    int user_input;

    char progress_bar_char = 24;
    int nodd = 0;
    int neven = 0;
    int nmax = 10;

    printf("\n");
    printf("\n");
    printf("\n");

    do {

        printf("\033[A");    // moves the cursor one line up
        printf("\033[A");
        printf("\033[A");
        printf("\033[2K\r"); // clears the current line

        printf("Enter an integer number (Enter 0 to stop): ");
        scanf("%d", &user_input);
        if (user_input == 0) {
            break;
        }
        if (user_input % 2 == 0) {
            neven += 1;
        } else {
            nodd += 1;
        }

        printf("Even: ");
        for (char ieven = 0; ieven < neven; ieven++) {
            printf("%c", progress_bar_char);
        }
        printf("\n");

        printf("Odd : ");
        for (char iodd = 0; iodd < nodd; iodd++) {
            printf("%c", progress_bar_char);
        }
        printf("\n");

    } while (user_input != 0 && nodd < nmax && neven < nmax);

    if (nodd == nmax || neven == nmax) {
        printf("And that's %d. Bye!\n", nmax);
    } else {
        printf("Aborted after %d characters.\n", nodd + neven);
    }

    return 0;

}
