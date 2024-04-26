#include <stdio.h>
#include <assert.h>
#include "dates.h"



int main (void) {

    Date d1;
    Date d2;

    printf("Enter first date (mm/dd/yyyy): ");
    scanf(" %2d / %2d / %4d", &d1.month, &d1.day, &d1.year);
    printf("Enter second date (mm/dd/yyyy): ");
    scanf(" %2d / %2d / %4d", &d2.month, &d2.day, &d2.year);

    assert(1 <= d1.day && d1.day <= 31 && "day integer not from range [1..31]");
    assert(1 <= d2.day && d2.day <= 31 && "day integer not from range [1..31]");
    assert(1 <= d1.month && d1.month <= 31 && "month integer not from range [1..12]");
    assert(1 <= d2.month && d2.month <= 31 && "month integer not from range [1..12]");

    int doy1 = day_of_year(d1);
    int doy2 = day_of_year(d2);

    printf("day of year for %d-%d-%d is: %d\n", d1.day, d1.month, d1.year, doy1);
    printf("day of year for %d-%d-%d is: %d\n", d2.day, d2.month, d2.year, doy2);

    int diff = compare_dates(d1, d2);
    if (diff == -1) {
        printf("%d-%d-%d is before %d-%d-%d\n", d1.day, d1.month, d1.year, d2.day, d2.month, d2.year);
    } else if (diff == 0) {
        printf("%d-%d-%d is the same as %d-%d-%d\n", d1.day, d1.month, d1.year, d2.day, d2.month, d2.year);
    } else {
        printf("%d-%d-%d is after %d-%d-%d\n", d1.day, d1.month, d1.year, d2.day, d2.month, d2.year);
    }

}
