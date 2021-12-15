#include <stdio.h>
#include <stdbool.h>


int main (void) {


    int hh12;
    int mm;

    printf("Enter a time in 12-hour format: ");
    scanf(" %d : %d", &hh12, &mm);

    if (hh12 > 12) {
        printf("Please use the 12-hour format to enter a time. Aborting.\n");
        return 1;
    }

    char c;
    int hh24;

    while (true) {
        c = getchar();
        if (c == '\n') {
            printf("AM or PM?\n");
            return 1;
        } else if (c == ' ') {
            continue;
        } else if (c == 'a' || c == 'A') {
            if (hh12 == 12) {
                hh24 = 0;
            } else {
                hh24 = hh12;
            }
            break;
        } else if (c == 'p' || c == 'P') {
            if (hh12 == 12) {
                hh24 = 12;
            } else {
                hh24 = (12 + hh12) % 24;
            }
            break;
        } else {
            printf("Invalid input, aborting.\n");
            return 1;
        }
    }

    int minutes = hh24 * 60 + mm;

    printf("Equivalent time in 24-hour format: %02d:%02d\n", minutes / 60, minutes % 60);

    return 0;

}
