#include <stdio.h>
#include <stdbool.h>


int main (void) {

    int mm0, dd0, yy0;
    int mm1, dd1, yy1;
    int idate = 0;
    bool isordered;

    do {

        printf("Enter a date (mm/dd/yy; 0/0/0 to abort): ");
        scanf(" %2d / %2d / %4d", &mm1, &dd1, &yy1);

        if (mm1 == 0 && dd1 == 0 && yy1 == 0) {
            printf("Aborting after %d dates.\n", idate);
            if (idate != 0) {
                printf("%02d/%02d/%02d is the earliest date.\n", mm0, dd0, yy0);
            }
            break;
        }

        if (idate == 0) {
            // force copying of mm1/dd0/yy0 to mm0/dd0/yy0
            isordered = false;
        } else if (yy0 < yy1) {
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
        }

        if (isordered == false) {
            mm0 = mm1;
            dd0 = dd1;
            yy0 = yy1;
        }

        idate += 1;

    } while (true);

    return 0;

}
