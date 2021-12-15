#include <stdio.h>

int main (void) {

    int ndays;
    int day0;

    printf("Enter number of days in a month: ");
    scanf(" %d", &ndays);
    printf("Enter the day of the week on which the month begins (1=Mon, 7=Sun): ");
    scanf(" %d", &day0);

    if (ndays < 28 || ndays > 31 || day0 < 1 || day0 > 7) {
        printf("Input error, aborting.\n");
        return 1;
    }

    printf("Mo Tu We Th Fr Sa Su \n");

    for (int i = 1; i < ndays + day0; i++) {

        if (i < day0) {
            printf("   ");
        } else {
            printf("%2d ", i - day0 + 1);
        }

        if (i % 7 == 0) {
            printf("\n");
        }

    }

    printf("\n");

    return 0;

}

