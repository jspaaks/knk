#include <stdio.h>
#include <stdbool.h>


int main (void) {

    int mm0, dd0, yy0;
    int mm1, dd1, yy1;

    printf("Enter first date (mm/dd/yy): ");
    scanf(" %2d / %2d / %4d", &mm0, &dd0, &yy0);
    printf("Enter second date (mm/dd/yy): ");
    scanf(" %2d / %2d / %4d", &mm1, &dd1, &yy1);

    bool isordered;

    if (yy0 < yy1) {
        isordered = true;
    } else if (yy0 > yy1) {
        isordered = false;
    } else if (mm0 < mm1) {
        isordered = true;
    } else if (mm0 > mm1) {
        isordered = false;
    } else if (dd0 < dd1) {
        isordered = true;
    } else if (dd0 > dd1) {
        isordered = false;
    } else if (dd0 == dd1) {
        printf("Dates are the same.\n");
        return 0;
    }

    if (isordered == true) {
        printf("%02d/%02d/%02d comes earlier than %02d/%02d/%02d\n", mm0, dd0, yy0, mm1, dd1, yy1);
    } else {
        printf("%02d/%02d/%02d comes earlier than %02d/%02d/%02d\n", mm1, dd1, yy1, mm0, dd0, yy0);
    }

    return 0;

}
